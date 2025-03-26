#include "Program.h"
#include "InputValidator.h"
#include "StepHandler.h"
#include "UI.h"
#include <iostream>
#include <algorithm>

using namespace std;

void Program::run() {
    Udp receiver;
    StepHandler stepHandler;
    std::string input;

    while (true) {
        UI::showPrompt(step);
        input = receiver.receive();

        input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

        if (input == "exit") {
            UI::showExitMessage();
            break;
        }

        int answer;
        try {
            answer = stoi(input);
            cout << answer;
        }
        catch (...) {
            UI::showError("숫자만 입력해주세요.");
            UI::delay(800);
            continue;
        }

        if (!InputValidator::validate(step, answer)) {
            UI::showError("입력값이 유효하지 않습니다.");
            UI::delay(800);
            continue;
        }

        if (step == QuestionType::Run_Test) {
            if (answer == 0) {
                step = QuestionType::CarType_Q;
                continue;
            }

            auto* car = builder.getCar();
            if (!car) {
                UI::showError("차량이 아직 생성되지 않았습니다.");
                UI::delay(800);
                continue;
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
    }
}