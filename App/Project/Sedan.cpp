#include "Sedan.h"
#include "UI.h"
#include <iostream>

using namespace std;

void Sedan::setEngine(Engine e) { engine = e; }
void Sedan::setBrake(BreakSystem b) { brake = b; }
void Sedan::setSteering(SteeringSystem s) { steering = s; }

void Sedan::run() const {
    if (engine == Engine::BROKEN) {
        UI::animateCarBroken();
    }
    else {
        UI::animateCarRun();
    }
}

void Sedan::test() const {
    if (!checkBoschCompatibility()) {
        fail("BOSCH 제동/조향 부품은 같이 써야 합니다.");
    }
    else if (brake == BreakSystem::CONTINENTAL) {
        fail("Sedan은 Continental 제동장치를 사용할 수 없습니다.");
    }
    else {
        pass();
    }
}