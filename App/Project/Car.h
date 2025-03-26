#pragma once
#include "Types.h"
#include "UI.h"
#include <string>

class Car {
protected:
    Engine engine = Engine::NONE;
    BreakSystem brake = BreakSystem::NONE;
    SteeringSystem steering = SteeringSystem::NONE;

    bool checkBoschCompatibility() const;
    void fail(const std::string& reason) const;
    void pass() const;

public:
    virtual void setEngine(Engine e) = 0;
    virtual void setBrake(BreakSystem b) = 0;
    virtual void setSteering(SteeringSystem s) = 0;

    virtual void run() const = 0;
    virtual void test() const = 0;

    virtual ~Car() = default;
};