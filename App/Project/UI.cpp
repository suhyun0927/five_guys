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
        cout << "� ���� Ÿ���� �����ұ��?\n1. Sedan\n2. SUV\n3. Truck\n";
        break;
    case QuestionType::Engine_Q:
        cout << "� ������ ž���ұ��?\n0. �ڷΰ���\n1. GM\n2. TOYOTA\n3. WIA\n4. ���峭 ����\n";
        break;
    case QuestionType::BreakSystem_Q:
        cout << "� ������ġ�� �����ұ��?\n0. �ڷΰ���\n1. MANDO\n2. CONTINENTAL\n3. BOSCH\n";
        break;
    case QuestionType::SteeringSystem_Q:
        cout << "� ������ġ�� �����ұ��?\n0. �ڷΰ���\n1. BOSCH\n2. MOBIS\n";
        break;
    case QuestionType::Run_Test:
        cout << "���� ������ �ϼ��Ǿ����ϴ�.\n0. ó������ ���ư���\n1. RUN\n2. TEST\n";
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
    cout << "\n�ڵ����� �ָ� �޷������ϴ�!\n";
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
            "   * ������ �������ϴ�!"
        },
        {
            "     ______________",
            "    /|   SYSTEM   | ",
            " __/_|___FAILURE__|____",
            "|   O       O         |",
            "'-( )----------( )-----'",
            "   ���� �߻� ��..."
        }
    };

    for (const auto& frame : frames) {
        clearScreen();
        for (const auto& line : frame) {
            cout << line << '\n';
        }
        delay(400);
    }
    cout << "\n�ڵ����� ���峵���ϴ�. ������ �ʿ��մϴ�.\n";
}