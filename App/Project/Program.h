#pragma once
#include "CarBuilder.h"
#include "UI.h"
#include <string>

class Program {
private:
    CarBuilder builder;
    QuestionType step = QuestionType::CarType_Q;

public:
    void run();
};