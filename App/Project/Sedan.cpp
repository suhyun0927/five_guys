#include "Sedan.h"
#include "UI.h"
#include <iostream>

using namespace std;

void Sedan::setEngine(Engine e) { engine = e; }
void Sedan::setBrake(BreakSystem b) { brake = b; }
void Sedan::setSteering(SteeringSystem s) { steering = s; }

void Sedan::run() const {
    if (engine == Engine::BROKEN) {
        cout << "엔진이 고장났습니다. 자동차가 움직이지 않습니다.\n";
        UI::animateCarBroken();
    }
    else {
        cout << "자동차가 동작됩니다.\n";
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