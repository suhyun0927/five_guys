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
        fail("BOSCH ����/���� ��ǰ�� ���� ��� �մϴ�.");
    }
    else if (engine == Engine::WIA) {
        fail("Truck�� WIA ������ �� �� �����ϴ�.");
    }
    else if (brake == BreakSystem::MANDO) {
        fail("Truck�� MANDO ������ġ�� �� �� �����ϴ�.");
    }
    else {
        pass();
    }
}