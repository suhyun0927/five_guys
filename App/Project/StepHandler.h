#pragma once
#include "CarBuilder.h"
#include "Types.h"

class StepHandler {
public:
    void handleStep(QuestionType step, int answer, CarBuilder& builder);
};