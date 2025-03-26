// Program.cpp (Fixed: Shell 화면도 GUI 입력에 맞게 갱신)
#include "Program.h"
#include "InputValidator.h"
#include "StepHandler.h"
#include "UI.h"
#include <iostream>
#include <algorithm>
#include <thread>

using namespace std;

void Program::run() {
    Udp receiver;
    StepHandler stepHandler;

    auto handleInput = [&](const std::string& input, Udp& receiver) {
        std::string trimmed = input;
        trimmed.erase(remove_if(trimmed.begin(), trimmed.end(), ::isspace), trimmed.end());

        if (trimmed == "exit") {
            UI::showExitMessage();
            exit(0);
        }

        int answer;
        try {
            answer = stoi(trimmed);
            cout << answer;
        }
        catch (...) {
            UI::showError("숫자만 입력해주세요.");
            UI::delay(800);
            return;
        }

        if (!InputValidator::validate(step, answer)) {
            UI::showError("입력값이 유효하지 않습니다.");
            UI::delay(800);
            return;
        }
        
        if (answer == 0) {
            if (step == QuestionType::Engine_Q) {
                step = QuestionType::CarType_Q;
                return;
            }
            else if (step == QuestionType::BreakSystem_Q) {
                step = QuestionType::Engine_Q;
                return;
            }
            else if (step == QuestionType::SteeringSystem_Q) {
                step = QuestionType::BreakSystem_Q;
                return;
            }
        }

        if (step == QuestionType::Run_Test) {
            if (answer == 0) {
                step = QuestionType::CarType_Q;
                return;
            }

            auto* car = builder.getCar();
            if (!car) {
                UI::showError("차량이 아직 생성되지 않았습니다.");
                UI::delay(800);
                return;
            }

            car->setUdp(&receiver);

            if (answer == 1) car->run();
            else if (answer == 2) car->test();
        }
        else {
            stepHandler.handleStep(step, answer, builder);
            step = static_cast<QuestionType>(static_cast<int>(step) + 1);
        }

        UI::delay(800);
        };

    // Thread: GUI 입력 (UDP) 처리
    std::thread udpThread([&]() {
        while (true) {
            std::string input = receiver.receive();
            handleInput(input, receiver);
            UI::showPrompt(step); // ✅ GUI 입력 처리 후 콘솔 메뉴 갱신
        }
        });

    // Main thread: Shell 입력
    while (true) {
        UI::showPrompt(step);
        std::string input;
        getline(std::cin, input);
        handleInput(input, receiver);
    }

    udpThread.join();
}
