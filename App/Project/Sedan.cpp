#include "Sedan.h"
#include "UI.h"
#include <iostream>

using namespace std;

void Sedan::setEngine(Engine e) { engine = e; }
void Sedan::setBrake(BreakSystem b) { brake = b; }
void Sedan::setSteering(SteeringSystem s) { steering = s; }

void Sedan::run() const {
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