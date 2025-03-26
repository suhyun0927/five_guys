#include "Car.h"
#include "Udp.h"
#include "UI.h"
#include <iostream>
#include <sstream>

using namespace std;

bool Car::checkBoschCompatibility() const {
    return (brake == BreakSystem::BOSCH_B && steering == SteeringSystem::BOSCH_S) ||
        (brake != BreakSystem::BOSCH_B && steering != SteeringSystem::BOSCH_S);
}

void Car::fail(const std::string& reason) const {
    std::ostringstream oss;
    oss << "�ڵ��� �׽�Ʈ ���: FAIL\n" << reason;

    std::cout << "\n===============================\n" << oss.str() << '\n';

    if (udpSender) {
        udpSender->sendBack("fail|" + reason);
    }

    UI::delay(1500);
}

void Car::pass() const {
    std::ostringstream oss;
    oss << "�ڵ��� �׽�Ʈ ���: PASS";

    std::cout << "\n===============================\n" << oss.str() << '\n';

    if (udpSender) {
        udpSender->sendBack("pass|" + oss.str());
    }

    UI::delay(1500);
}