#pragma once
#include "Car.h"

class Sedan : public Car {
public:
    void setEngine(Engine e) override;
    void setBrake(BreakSystem b) override;
    void setSteering(SteeringSystem s) override;

    void run() const override;
    void test() const override;
};