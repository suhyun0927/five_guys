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
        createCar(selectedType); // ���� ����
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
        std::cout << "������ ���峵���ϴ�. �ڵ����� �������� �ʽ��ϴ�.\n";
    }
    else {
        std::cout << "�ڵ����� ���۵˴ϴ�.\n";
    }
}

void CarBuilder::test() {
    if (selectedType == CarType::SEDAN && brake == BreakSystem::CONTINENTAL) {
        std::cout << "�ڵ��� �׽�Ʈ ���: FAIL - Sedan�� Continental ������ġ �Ұ�\n";
    }
    else if (selectedType == CarType::SUV && engine == Engine::TOYOTA) {
        std::cout << "�ڵ��� �׽�Ʈ ���: FAIL - SUV�� TOYOTA ���� �Ұ�\n";
    }
    else if (selectedType == CarType::TRUCK && engine == Engine::WIA) {
        std::cout << "�ڵ��� �׽�Ʈ ���: FAIL - Truck�� WIA ���� �Ұ�\n";
    }
    else if (selectedType == CarType::TRUCK && brake == BreakSystem::MANDO) {
        std::cout << "�ڵ��� �׽�Ʈ ���: FAIL - Truck�� MANDO ������ġ �Ұ�\n";
    }
    else if (brake == BreakSystem::BOSCH_B && steering != SteeringSystem::BOSCH_S) {
        std::cout << "�ڵ��� �׽�Ʈ ���: FAIL - Bosch �����̸� Bosch ���� �ʿ�\n";
    }
    else if (brake != BreakSystem::BOSCH_B && steering == SteeringSystem::BOSCH_S) {
        std::cout << "�ڵ��� �׽�Ʈ ���: FAIL - Bosch �����̸� Bosch ���� �ʿ�\n";
    }
    else {
        std::cout << "�ڵ��� �׽�Ʈ ���: PASS\n";
    }
}

CarBuilder::~CarBuilder() {
    delete car;
}
