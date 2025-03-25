#include "Car.h"
#include <iostream>

using namespace std;

bool Car::checkBoschCompatibility() const {
    return (brake == BreakSystem::BOSCH_B && steering == SteeringSystem::BOSCH_S) ||
        (brake != BreakSystem::BOSCH_B && steering != SteeringSystem::BOSCH_S);
}

void Car::fail(const std::string& reason) const {
    cout << "자동차 테스트 결과: FAIL\n" << reason << endl;
}

void Car::pass() const {
    cout << "자동차 테스트 결과: PASS\n";
}