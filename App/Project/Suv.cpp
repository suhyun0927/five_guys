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
            udpSender->sendBack("fail|������ ���峵���ϴ�. �ڵ����� �������� �ʽ��ϴ�.");
        }
        UI::animateCarBroken();
    }
    else {
        if (udpSender) {
            udpSender->sendBack("pass|�ڵ����� ���۵˴ϴ�.");
        }
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