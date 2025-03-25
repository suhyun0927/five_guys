#include "Suv.h"
#include "UI.h"
#include <iostream>

using namespace std;

void Suv::setEngine(Engine e) { engine = e; }
void Suv::setBrake(BreakSystem b) { brake = b; }
void Suv::setSteering(SteeringSystem s) { steering = s; }

void Suv::run() const {
    if (engine == Engine::BROKEN) {
        cout << "������ ���峵���ϴ�. �ڵ����� �������� �ʽ��ϴ�.\n";
        UI::animateCarBroken();
    }
    else {
        cout << "�ڵ����� ���۵˴ϴ�.\n";
        UI::animateCarRun();
    }
}

void Suv::test() const {
    if (!checkBoschCompatibility()) {
        fail("BOSCH ����/���� ��ǰ�� ���� ��� �մϴ�.");
    }
    else if (engine == Engine::TOYOTA) {
        fail("SUV�� TOYOTA ������ �� �� �����ϴ�.");
    }
    else {
        pass();
    }
}