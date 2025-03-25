#pragma once
#include "Types.h"

class UI {
public:
    static void clearScreen();
    static void delay(int ms);
    static void showMenu(QuestionType step);
    static void animateCarRun();
    static void animateCarBroken();
};