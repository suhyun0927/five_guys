#include "UI.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

using namespace std;

void UI::clearScreen() {
    system(CLEAR);
}

void UI::delay(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void UI::showPrompt(QuestionType step) {
    clearScreen();
    switch (step) {
    case QuestionType::CarType_Q:
        cout << "[���� Ÿ�� ����]\n1. Sedan\n2. SUV\n3. Truck\n";
        break;
    case QuestionType::Engine_Q:
        cout << "[���� ����]\n0. �ڷΰ���\n1. GM\n2. TOYOTA\n3. WIA\n4. ���峭 ����\n";
        break;
    case QuestionType::BreakSystem_Q:
        cout << "[������ġ ����]\n0. �ڷΰ���\n1. MANDO\n2. CONTINENTAL\n3. BOSCH\n";
        break;
    case QuestionType::SteeringSystem_Q:
        cout << "[������ġ ����]\n0. �ڷΰ���\n1. BOSCH\n2. MOBIS\n";
        break;
    case QuestionType::Run_Test:
        cout << "[���� �׽�Ʈ]\n0. ó������ ���ư���\n1. RUN\n2. TEST\n";
        break;
    }
    cout << "===============================\nINPUT > ";
}

void UI::showError(const std::string& msg) {
    cerr << "ERROR :: " << msg << "\n";
}

void UI::showExitMessage() {
    cout << "���̹���!\n";
}

void UI::animateCarRun() {
    const string bodyTop[] = {
        "        ______________",
        "       /|            | ",
        "  ____/_|_____________|____",
        " |                      O  |"
    };
    const int maxOffset = 30;
    const string wheels[] = { "(@)", "(|)", "(-)", "(\\)", "(@)" };
    const int wheelFrames = sizeof(wheels) / sizeof(wheels[0]);

    for (int offset = 0; offset <= maxOffset; offset += 3) {
        clearScreen();
        cout << "�ڵ����� ���۵˴ϴ�.\n";
        string space(offset, ' ');
        for (const auto& line : bodyTop) {
            cout << space << line << '\n';
        }
        string wheelFrame = wheels[offset % wheelFrames];
        cout << space << " '-" << wheelFrame << "----------------" << wheelFrame << "--'\n";
        cout << "========================================================================\n";
        delay(200);
    }
}

void UI::animateCarBroken() {
    const string frames[6] = {
        "        ______________",
        "       /|   SYSTEM   | ",
        "  ____/_|___FAILURE__|____",
        " |        O       O      |",
        " '-(@)------------(@)----'",
        "==============================="
    };

    clearScreen();
    cout << "������ ���峵���ϴ�. �ڵ����� �������� �ʽ��ϴ�.\n";
    for (const auto& line : frames) {
        cout << line << '\n';
    }
    delay(1500);
}