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
    cout << "\n자동차 테스트 결과: FAIL\n" << reason << endl;

    if (udpSender) {
        std::string udpMessage = "fail|자동차 테스트 결과: FAIL\n" + reason;
        udpSender->sendTo(udpMessage, udpSender->getLastSenderIP(), udpSender->getLastSenderPort());
    }

    UI::delay(1500);
}

void Car::pass() const {
    cout << "\n===============================";
    cout << "\n자동차 테스트 결과: PASS\n";

    if (udpSender) {
        std::string udpMessage = "pass|자동차 테스트를 통과했습니다.";
        udpSender->sendTo(udpMessage, udpSender->getLastSenderIP(), udpSender->getLastSenderPort());
    }

    UI::delay(1500);
}