// CarBuilder.cpp (Refactored)
#include "CarBuilder.h"

void CarBuilder::createCar(CarType type) {
    switch (type) {
    case CarType::SEDAN:
        car = std::make_unique<Sedan>();
        break;
    case CarType::SUV:
        car = std::make_unique<Suv>();
        break;
    case CarType::TRUCK:
        car = std::make_unique<Truck>();
        break;
    default:
        car.reset();
        break;
    }
}

Car* CarBuilder::getCar() const {
    return car.get();
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
