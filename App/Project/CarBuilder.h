#pragma once
#include "Car.h"
#include "Sedan.h"
#include "Suv.h"
#include "Truck.h"
#include "Types.h"

class CarBuilder {
private:
    Car* car = nullptr;

    CarType selectedType = CarType::NONE;
    Engine engine = Engine::NONE;
    BreakSystem brake = BreakSystem::NONE;
    SteeringSystem steering = SteeringSystem::NONE;

public:
    ~CarBuilder();

    void createCar(CarType type);
    Car* getCar() const;
    void setEngine(Engine e);
    void setBrake(BreakSystem b);
    void setSteering(SteeringSystem s);
    void handleStep(QuestionType step, int answer);
    void run();
    void test();
};
