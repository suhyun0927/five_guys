#include "Suv.h"
#include "UI.h"
#include <iostream>

using namespace std;

void Suv::setEngine(Engine e) { engine = e; }
void Suv::setBrake(BreakSystem b) { brake = b; }
void Suv::setSteering(SteeringSystem s) { steering = s; }

void Suv::run() const {
    if (engine == Engine::BROKEN) {
        if (udpSender) {
            udpSender->sendBack("fail|엔진이 고장났습니다. 자동차가 움직이지 않습니다.");
        }
        UI::animateCarBroken();
    }
    else {
        if (udpSender) {
            udpSender->sendBack("pass|자동차가 동작됩니다.");
        }
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