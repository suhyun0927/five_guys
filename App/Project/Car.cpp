#include "Car.h"
#include <iostream>

using namespace std;

bool Car::checkBoschCompatibility() const {
    return (brake == BreakSystem::BOSCH_B && steering == SteeringSystem::BOSCH_S) ||
        (brake != BreakSystem::BOSCH_B && steering != SteeringSystem::BOSCH_S);
}

void Car::fail(const std::string& reason) const {
    cout << "\n===============================";
    cout << "\n�ڵ��� �׽�Ʈ ���: FAIL\n" << reason << endl;
    UI::delay(1500);
}

void Car::pass() const {
    cout << "\n===============================";
    cout << "\n�ڵ��� �׽�Ʈ ���: PASS\n";
    UI::delay(1500);
}