#include "Car.h"
#include "Udp.h"
#include <iostream>
#include <sstream>

using namespace std;

bool Car::checkBoschCompatibility() const {
    return (brake == BreakSystem::BOSCH_B && steering == SteeringSystem::BOSCH_S) ||
        (brake != BreakSystem::BOSCH_B && steering != SteeringSystem::BOSCH_S);
}

void Car::fail(const std::string& reason) const {
    cout << "\n===============================";
    cout << "\n�ڵ��� �׽�Ʈ ���: FAIL\n" << reason << endl;

    if (udpSender) {
        std::string udpMessage = "fail|�ڵ��� �׽�Ʈ ���: FAIL\n" + reason;
        udpSender->sendTo(udpMessage, udpSender->getLastSenderIP(), udpSender->getLastSenderPort());
    }

    UI::delay(1500);
}

void Car::pass() const {
    cout << "\n===============================";
    cout << "\n�ڵ��� �׽�Ʈ ���: PASS\n";

    if (udpSender) {
        std::string udpMessage = "pass|�ڵ��� �׽�Ʈ�� ����߽��ϴ�.";
        udpSender->sendTo(udpMessage, udpSender->getLastSenderIP(), udpSender->getLastSenderPort());
    }

    UI::delay(1500);
}