#include "InputValidator.h"

bool InputValidator::validate(QuestionType step, int value) {
    switch (step) {
    case QuestionType::CarType_Q: return value >= 1 && value <= 3;
    case QuestionType::Engine_Q: return value >= 0 && value <= 4;
    case QuestionType::BreakSystem_Q: return value >= 0 && value <= 3;
    case QuestionType::SteeringSystem_Q: return value >= 0 && value <= 2;
    case QuestionType::Run_Test: return value >= 0 && value <= 2;
    default: return false;
    }
}