#include "Program.h"
#include <iostream>

using namespace std;

void Program::run() {
    string input;

    while (true) {
        UI::showMenu(step);
        getline(cin, input);

        if (input == "exit") {
            cout << "���̹���!\n";
            break;
        }

        int answer;
        try {
            answer = stoi(input);
        }
        catch (...) {
            cout << "ERROR :: ���ڸ� �Է����ּ���.\n";
            UI::delay(800);
            continue;
        }

        if (step == QuestionType::CarType_Q && (answer < 1 || answer > 3)) {
            cout << "ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ����\n";
            UI::delay(800);
            continue;
        }
        if (step == QuestionType::Engine_Q && (answer < 0 || answer > 4)) {
            cout << "ERROR :: ������ 1 ~ 4 ������ ���� ����\n";
            UI::delay(800);
            continue;
        }
        if (step == QuestionType::BreakSystem_Q && (answer < 0 || answer > 3)) {
            cout << "ERROR :: ������ġ�� 1 ~ 3 ������ ���� ����\n";
            UI::delay(800);
            continue;
        }
        if (step == QuestionType::SteeringSystem_Q && (answer < 0 || answer > 2)) {
            cout << "ERROR :: ������ġ�� 1 ~ 2 ������ ���� ����\n";
            UI::delay(800);
            continue;
        }
        if (step == QuestionType::Run_Test && (answer < 0 || answer > 2)) {
            cout << "ERROR :: ���� ������ 0 ~ 2 ���̿��� �մϴ�\n";
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
            cout << "���� Ÿ�� ����: " << (answer == 1 ? "Sedan" : answer == 2 ? "SUV" : "Truck") << endl;
            break;
        case QuestionType::Engine_Q:
            builder.setEngine(static_cast<Engine>(answer));
            cout << "���� ����: " << (answer == 1 ? "GM" : answer == 2 ? "TOYOTA" : answer == 3 ? "WIA" : "���峭 ����") << endl;
            break;
        case QuestionType::BreakSystem_Q:
            builder.setBrake(static_cast<BreakSystem>(answer));
            cout << "������ġ ����: " << (answer == 1 ? "MANDO" : answer == 2 ? "CONTINENTAL" : "BOSCH") << endl;
            break;
        case QuestionType::SteeringSystem_Q:
            builder.setSteering(static_cast<SteeringSystem>(answer));
            cout << "������ġ ����: " << (answer == 1 ? "BOSCH" : "MOBIS") << endl;
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
