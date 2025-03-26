#include "Car.h"
#include <iostream>

using namespace std;

bool Car::checkBoschCompatibility() const {
    return (brake == BreakSystem::BOSCH_B && steering == SteeringSystem::BOSCH_S) ||
        (brake != BreakSystem::BOSCH_B && steering != SteeringSystem::BOSCH_S);
}

void Car::fail(const std::string& reason) const {
    cout << "�ڵ��� �׽�Ʈ ���: FAIL\n" << reason << endl;
}

void Car::pass() const {
    cout << "�ڵ��� �׽�Ʈ ���: PASS\n";
}