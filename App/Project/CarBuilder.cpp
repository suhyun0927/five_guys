#include "CarBuilder.h"

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

CarBuilder::~CarBuilder() {
    delete car;
}
