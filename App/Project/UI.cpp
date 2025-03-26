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

void UI::showMenu(QuestionType step) {
    clearScreen();
    switch (step) {
    case QuestionType::CarType_Q:
        cout << "        ______________\n";
        cout << "       /|            | \n";
        cout << "  ____/_|_____________|____\n";
        cout << " |                      O  |\n";
        cout << " '-(@)----------------(@)--'\n";
        cout << "어떤 차량 타입을 선택할까요?\n1. Sedan\n2. SUV\n3. Truck\n";
        break;
    case QuestionType::Engine_Q:
        cout << "어떤 엔진을 탑재할까요?\n0. 뒤로가기\n1. GM\n2. TOYOTA\n3. WIA\n4. 고장난 엔진\n";
        break;
    case QuestionType::BreakSystem_Q:
        cout << "어떤 제동장치를 선택할까요?\n0. 뒤로가기\n1. MANDO\n2. CONTINENTAL\n3. BOSCH\n";
        break;
    case QuestionType::SteeringSystem_Q:
        cout << "어떤 조향장치를 선택할까요?\n0. 뒤로가기\n1. BOSCH\n2. MOBIS\n";
        break;
    case QuestionType::Run_Test:
        cout << "멋진 차량이 완성되었습니다.\n0. 처음으로 돌아가기\n1. RUN\n2. TEST\n";
        break;
    }
    cout << "===============================\nINPUT > ";
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

    for (int offset = 0; offset <= maxOffset; ++offset) {
        clearScreen();
        string space(offset, ' ');
        for (const auto& line : bodyTop) {
            cout << space << line << '\n';
        }
        string wheelFrame = wheels[offset % wheelFrames];
        cout << space << " '-" << wheelFrame << "----------------" << wheelFrame << "--'\n";
        cout << space << "===============================\n";
        delay(100);
    }
    cout << "\n자동차가 멀리 달려갔습니다!\n";
}

void UI::animateCarBroken() {
    const string frames[][6] = {
        {
            "        ______________",
            "       /|   SYSTEM   | ",
            "  ____/_|___FAILURE__|____",
            " |        O       O      |",
            " '-(@)------------(@)----'",
            "==============================="
        },
        {
            "       ______________",
            "      /|   SYSTEM   | ",
            " ____/_|___FAILURE__|____",
            "|      O       O        |",
            "'-(@)------------(@)----'",
            "==============================="
        },
        {
            "       ______________",
            "      /|   SYSTEM   | ",
            " ____/_|___FAILURE__|____",
            "|      O       O        |",
            "'-( )------------(@)----'",
            "   * 바퀴가 빠졌습니다!"
        },
        {
            "     ______________",
            "    /|   SYSTEM   | ",
            " __/_|___FAILURE__|____",
            "|   O       O         |",
            "'-( )----------( )-----'",
            "   연기 발생 중..."
        }
    };

    for (const auto& frame : frames) {
        clearScreen();
        for (const auto& line : frame) {
            cout << line << '\n';
        }
        delay(400);
    }
    cout << "\n자동차가 고장났습니다. 수리가 필요합니다.\n";
}