#include "Program.h"
#include <iostream>

using namespace std;

void Program::run() {
    string input;

    while (true) {
        UI::showMenu(step);
        getline(cin, input);

        if (input == "exit") {
            cout << "바이바이!\n";
            break;
        }

        int answer;
        try {
            answer = stoi(input);
        }
        catch (...) {
            cout << "ERROR :: 숫자만 입력해주세요.\n";
            UI::delay(800);
            continue;
        }

        if (step == QuestionType::CarType_Q && (answer < 1 || answer > 3)) {
            cout << "ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n";
            UI::delay(800);
            continue;
        }
        if (step == QuestionType::Engine_Q && (answer < 0 || answer > 4)) {
            cout << "ERROR :: 엔진은 1 ~ 4 범위만 선택 가능\n";
            UI::delay(800);
            continue;
        }
        if (step == QuestionType::BreakSystem_Q && (answer < 0 || answer > 3)) {
            cout << "ERROR :: 제동장치는 1 ~ 3 범위만 선택 가능\n";
            UI::delay(800);
            continue;
        }
        if (step == QuestionType::SteeringSystem_Q && (answer < 0 || answer > 2)) {
            cout << "ERROR :: 조향장치는 1 ~ 2 범위만 선택 가능\n";
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

        if (answer == 0 && step != QuestionType::CarType_Q) {
            step = static_cast<QuestionType>(static_cast<int>(step) - 1);
            continue;
        }

        switch (step) {
        case QuestionType::CarType_Q:
            builder.createCar(static_cast<CarType>(answer));
            cout << "차량 타입 선택: " << (answer == 1 ? "Sedan" : answer == 2 ? "SUV" : "Truck") << endl;
            break;
        case QuestionType::Engine_Q:
            builder.setEngine(static_cast<Engine>(answer));
            cout << "엔진 선택: " << (answer == 1 ? "GM" : answer == 2 ? "TOYOTA" : answer == 3 ? "WIA" : "고장난 엔진") << endl;
            break;
        case QuestionType::BreakSystem_Q:
            builder.setBrake(static_cast<BreakSystem>(answer));
            cout << "제동장치 선택: " << (answer == 1 ? "MANDO" : answer == 2 ? "CONTINENTAL" : "BOSCH") << endl;
            break;
        case QuestionType::SteeringSystem_Q:
            builder.setSteering(static_cast<SteeringSystem>(answer));
            cout << "조향장치 선택: " << (answer == 1 ? "BOSCH" : "MOBIS") << endl;
            break;
        case QuestionType::Run_Test:
            if (answer == 1) builder.getCar()->run();
            else if (answer == 2) builder.getCar()->test();
            break;
        }

        if (step != QuestionType::Run_Test)
            step = static_cast<QuestionType>(static_cast<int>(step) + 1);

        UI::delay(1000);
    }
}
