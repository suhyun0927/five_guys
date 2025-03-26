#pragma once
#include "Car.h"
#include "Sedan.h"
#include "Suv.h"
#include "Truck.h"
#include "Types.h"
#include <memory>

class CarBuilder {
private:
    std::unique_ptr<Car> car;

public:
    void createCar(CarType type);
    Car* getCar() const;
    void setEngine(Engine e);
    void setBrake(BreakSystem b);
    void setSteering(SteeringSystem s);
};