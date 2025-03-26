#include "Truck.h"
#include "UI.h"
#include <iostream>

using namespace std;

void Truck::setEngine(Engine e) { engine = e; }
void Truck::setBrake(BreakSystem b) { brake = b; }
void Truck::setSteering(SteeringSystem s) { steering = s; }

void Truck::run() const {
    if (engine == Engine::BROKEN) {
        UI::animateCarBroken();
    }
    else {
        UI::animateCarRun();
    }
}

void Truck::test() const {
    if (!checkBoschCompatibility()) {
        fail("BOSCH 제동/조향 부품은 같이 써야 합니다.");
    }
    else if (engine == Engine::WIA) {
        fail("Truck은 WIA 엔진을 쓸 수 없습니다.");
    }
    else if (brake == BreakSystem::MANDO) {
        fail("Truck은 MANDO 제동장치를 쓸 수 없습니다.");
    }
    else {
        pass();
    }
}