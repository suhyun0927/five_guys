#include "CarBuilder.h"
#include "Types.h"
#include <iostream>

void CarBuilder::createCar(CarType type) {
    delete car;
    car = nullptr;

    switch (type) {
    case CarType::SEDAN:
        car = new Sedan();
        break;
    case CarType::SUV:
        car = new Suv();
        break;
    case CarType::TRUCK:
        car = new Truck();
        break;
    default:
        break;
    }
}

Car* CarBuilder::getCar() const {
    return car;
}

void CarBuilder::setEngine(Engine e) {
    if (car) car->setEngine(e);
}

void CarBuilder::setBrake(BreakSystem b) {
    if (car) car->setBrake(b);
}

void CarBuilder::setSteering(SteeringSystem s) {
    if (car) car->setSteering(s);
}

void CarBuilder::handleStep(QuestionType step, int answer) {
    switch (step) {
    case QuestionType::CarType_Q:
        selectedType = static_cast<CarType>(answer);
        createCar(selectedType); // 차량 생성
        break;
    case QuestionType::Engine_Q:
        engine = static_cast<Engine>(answer);
        setEngine(engine);
        break;
    case QuestionType::BreakSystem_Q:
        brake = static_cast<BreakSystem>(answer);
        setBrake(brake);
        break;
    case QuestionType::SteeringSystem_Q:
        steering = static_cast<SteeringSystem>(answer);
        setSteering(steering);
        break;
    default:
        break;
    }
}

void CarBuilder::run() {
    if (engine == Engine::BROKEN) {
        std::cout << "엔진이 고장났습니다. 자동차가 움직이지 않습니다.\n";
    }
    else {
        std::cout << "자동차가 동작됩니다.\n";
    }
}

void CarBuilder::test() {
    if (selectedType == CarType::SEDAN && brake == BreakSystem::CONTINENTAL) {
        std::cout << "자동차 테스트 결과: FAIL - Sedan은 Continental 제동장치 불가\n";
    }
    else if (selectedType == CarType::SUV && engine == Engine::TOYOTA) {
        std::cout << "자동차 테스트 결과: FAIL - SUV는 TOYOTA 엔진 불가\n";
    }
    else if (selectedType == CarType::TRUCK && engine == Engine::WIA) {
        std::cout << "자동차 테스트 결과: FAIL - Truck은 WIA 엔진 불가\n";
    }
    else if (selectedType == CarType::TRUCK && brake == BreakSystem::MANDO) {
        std::cout << "자동차 테스트 결과: FAIL - Truck은 MANDO 제동장치 불가\n";
    }
    else if (brake == BreakSystem::BOSCH_B && steering != SteeringSystem::BOSCH_S) {
        std::cout << "자동차 테스트 결과: FAIL - Bosch 제동이면 Bosch 조향 필요\n";
    }
    else if (brake != BreakSystem::BOSCH_B && steering == SteeringSystem::BOSCH_S) {
        std::cout << "자동차 테스트 결과: FAIL - Bosch 조향이면 Bosch 제동 필요\n";
    }
    else {
        std::cout << "자동차 테스트 결과: PASS\n";
    }
}

CarBuilder::~CarBuilder() {
    delete car;
}
