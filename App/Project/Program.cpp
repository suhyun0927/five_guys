#include "Program.h"
#include "UdpReceiver.h"
#include <iostream>
#include <algorithm>

using namespace std;

void Program::run() {
    UdpReceiver receiver;
    string input;

    while (true) {
        UI::showMenu(step);
        input = receiver.receive(); // UDP 메시지 수신

        //std::cout << "[DEBUG] 원본 수신 값: \"" << input << "\"\n";

        input.erase(std::remove_if(input.begin(), input.end(),
            [](unsigned char c) { return std::isspace(c); }), input.end());

        //std::cout << "[DEBUG] 공백 제거 후: \"" << input << "\"\n";

        if (input == "exit") {
            cout << "바이바이!\n";
            break;
        }

        int answer;
        try {
            answer = stoi(input);
            cout << answer;
        }
        catch (...) {

            cout << "ERROR :: 숫자만 입력해주세요.\n";
            UI::delay(800);
            continue;
        }

        // 입력값 범위 체크
        if (step == QuestionType::CarType_Q && (answer < 1 || answer > 3)) {
            cout << "ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n";
            UI::delay(800);
            continue;
        }
        if (step == QuestionType::Engine_Q && (answer < 0 || answer > 4)) {
            cout << "ERROR :: 엔진은 0 ~ 4 범위만 선택 가능\n";
            UI::delay(800);
            continue;
        }
        if (step == QuestionType::BreakSystem_Q && (answer < 0 || answer > 3)) {
            cout << "ERROR :: 제동장치는 0 ~ 3 범위만 선택 가능\n";
            UI::delay(800);
            continue;
        }
        if (step == QuestionType::SteeringSystem_Q && (answer < 0 || answer > 2)) {
            cout << "ERROR :: 조향장치는 0 ~ 2 범위만 선택 가능\n";
            UI::delay(800);
            continue;
        }
        if (step == QuestionType::Run_Test && (answer < 0 || answer > 2)) {
            cout << "ERROR :: 동작 선택은 0 ~ 2 사이여야 합니다\n";
            UI::delay(800);
            continue;
        }

        if (step == QuestionType::Run_Test && answer == 0) {
            step = QuestionType::CarType_Q;
            continue;
        }

        builder.handleStep(step, answer);
        UI::delay(800);

        if (step == QuestionType::Run_Test) {
            if (answer == 1) builder.getCar()->run();
            else if (answer == 2) builder.getCar()->test();
        }
        else {
            step = static_cast<QuestionType>(static_cast<int>(step) + 1);
        }
    }
}
