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
        input = receiver.receive(); // UDP �޽��� ����

        //std::cout << "[DEBUG] ���� ���� ��: \"" << input << "\"\n";

        input.erase(std::remove_if(input.begin(), input.end(),
            [](unsigned char c) { return std::isspace(c); }), input.end());

        //std::cout << "[DEBUG] ���� ���� ��: \"" << input << "\"\n";

        if (input == "exit") {
            cout << "���̹���!\n";
            break;
        }

        int answer;
        try {
            answer = stoi(input);
            cout << answer;
        }
        catch (...) {

            cout << "ERROR :: ���ڸ� �Է����ּ���.\n";
            UI::delay(800);
            continue;
        }

        // �Է°� ���� üũ
        if (step == QuestionType::CarType_Q && (answer < 1 || answer > 3)) {
            cout << "ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ����\n";
            UI::delay(800);
            continue;
        }
        if (step == QuestionType::Engine_Q && (answer < 0 || answer > 4)) {
            cout << "ERROR :: ������ 0 ~ 4 ������ ���� ����\n";
            UI::delay(800);
            continue;
        }
        if (step == QuestionType::BreakSystem_Q && (answer < 0 || answer > 3)) {
            cout << "ERROR :: ������ġ�� 0 ~ 3 ������ ���� ����\n";
            UI::delay(800);
            continue;
        }
        if (step == QuestionType::SteeringSystem_Q && (answer < 0 || answer > 2)) {
            cout << "ERROR :: ������ġ�� 0 ~ 2 ������ ���� ����\n";
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
