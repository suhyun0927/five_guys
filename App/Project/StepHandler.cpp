// StepHandler.cpp
#include "StepHandler.h"

void StepHandler::handleStep(QuestionType step, int answer, CarBuilder& builder) {
    switch (step) {
    case QuestionType::CarType_Q:
        builder.createCar(static_cast<CarType>(answer));
        break;
    case QuestionType::Engine_Q:
        builder.setEngine(static_cast<Engine>(answer));
        break;
    case QuestionType::BreakSystem_Q:
        builder.setBrake(static_cast<BreakSystem>(answer));
        break;
    case QuestionType::SteeringSystem_Q:
        builder.setSteering(static_cast<SteeringSystem>(answer));
        break;
    default:
        break;
    }
}