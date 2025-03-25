#include "Sedan.h"
#include "UI.h"
#include <iostream>

using namespace std;

void Sedan::setEngine(Engine e) { engine = e; }
void Sedan::setBrake(BreakSystem b) { brake = b; }
void Sedan::setSteering(SteeringSystem s) { steering = s; }

void Sedan::run() const {
    if (engine == Engine::BROKEN) {
        cout << "������ ���峵���ϴ�. �ڵ����� �������� �ʽ��ϴ�.\n";
        UI::animateCarBroken();
    }
    else {
        cout << "�ڵ����� ���۵˴ϴ�.\n";
        UI::animateCarRun();
    }
}

void Sedan::test() const {
    if (!checkBoschCompatibility()) {
        fail("BOSCH ����/���� ��ǰ�� ���� ��� �մϴ�.");
    }
    else if (brake == BreakSystem::CONTINENTAL) {
        fail("Sedan�� Continental ������ġ�� ����� �� �����ϴ�.");
    }
    else {
        pass();
    }
}