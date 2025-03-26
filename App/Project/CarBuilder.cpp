#include "CarBuilder.h"
#include "Types.h"
#include <iostream>

void CarBuilder::createCar(CarType type) {
    delete car;
    car = nullptr;

    switch (type) {
    case CarType::SEDAN:
        car = new Sedan();
        break;
    case CarType::SUV:
        car = new Suv();
        break;
    case CarType::TRUCK:
        car = new Truck();
        break;
    default:
        break;
    }
}

Car* CarBuilder::getCar() const {
    return car;
}

void CarBuilder::setEngine(Engine e) {
    if (car) car->setEngine(e);
}

void CarBuilder::setBrake(BreakSystem b) {
    if (car) car->setBrake(b);
}

void CarBuilder::setSteering(SteeringSystem s) {
    if (car) car->setSteering(s);
}

void CarBuilder::handleStep(QuestionType step, int answer) {
    switch (step) {
    case QuestionType::CarType_Q:
        selectedType = static_cast<CarType>(answer);
        createCar(selectedType); // 차량 생성
        break;
    case QuestionType::Engine_Q:
        engine = static_cast<Engine>(answer);
        setEngine(engine);
        break;
    case QuestionType::BreakSystem_Q:
        brake = static_cast<BreakSystem>(answer);
        setBrake(brake);
        break;
    case QuestionType::SteeringSystem_Q:
        steering = static_cast<SteeringSystem>(answer);
        setSteering(steering);
        break;
    default:
        break;
    }
}

CarBuilder::~CarBuilder() {
    delete car;
}
