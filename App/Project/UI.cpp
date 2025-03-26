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
        cout << "[차량 타입 선택]\n1. Sedan\n2. SUV\n3. Truck\n";
        break;
    case QuestionType::Engine_Q:
        cout << "[엔진 선택]\n0. 뒤로가기\n1. GM\n2. TOYOTA\n3. WIA\n4. 고장난 엔진\n";
        break;
    case QuestionType::BreakSystem_Q:
        cout << "[제동장치 선택]\n0. 뒤로가기\n1. MANDO\n2. CONTINENTAL\n3. BOSCH\n";
        break;
    case QuestionType::SteeringSystem_Q:
        cout << "[조향장치 선택]\n0. 뒤로가기\n1. BOSCH\n2. MOBIS\n";
        break;
    case QuestionType::Run_Test:
        cout << "[차량 테스트]\n0. 처음으로 돌아가기\n1. RUN\n2. TEST\n";
        break;
    }
    cout << "===============================\nINPUT > ";
}

void UI::showError(const std::string& msg) {
    cerr << "ERROR :: " << msg << "\n";
}

void UI::showExitMessage() {
    cout << "바이바이!\n";
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
        cout << "자동차가 동작됩니다.\n";
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
    cout << "엔진이 고장났습니다. 자동차가 움직이지 않습니다.\n";
    for (const auto& line : frames) {
        cout << line << '\n';
    }
    delay(1500);
}