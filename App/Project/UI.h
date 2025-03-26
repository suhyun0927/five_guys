#pragma once
#include "Types.h"
#include <string>

class UI {
public:
    static void clearScreen();
    static void delay(int ms);

    static void showPrompt(QuestionType step);
    static void showError(const std::string& msg);
    static void showExitMessage();

    static void animateCarRun();
    static void animateCarBroken();
};