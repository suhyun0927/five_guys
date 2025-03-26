#include "Suv.h"
#include "UI.h"
#include <iostream>

using namespace std;

void Suv::setEngine(Engine e) { engine = e; }
void Suv::setBrake(BreakSystem b) { brake = b; }
void Suv::setSteering(SteeringSystem s) { steering = s; }

void Suv::run() const {
    if (engine == Engine::BROKEN) {
        UI::animateCarBroken();
    }
    else {
        UI::animateCarRun();
    }
}

void Suv::test() const {
    if (!checkBoschCompatibility()) {
        fail("BOSCH 제동/조향 부품은 같이 써야 합니다.");
    }
    else if (engine == Engine::TOYOTA) {
        fail("SUV는 TOYOTA 엔진을 쓸 수 없습니다.");
    }
    else {
        pass();
    }
}