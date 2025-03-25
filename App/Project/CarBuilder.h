#pragma once
#pragma once
#include "Car.h"
#include "Sedan.h"
#include "Suv.h"
#include "Truck.h"

class CarBuilder {
private:
    Car* car = nullptr;

public:
    ~CarBuilder();

    void createCar(CarType type);
    Car* getCar() const;
    void setEngine(Engine e);
    void setBrake(BreakSystem b);
    void setSteering(SteeringSystem s);
};