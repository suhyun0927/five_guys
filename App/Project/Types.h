#pragma once

enum class QuestionType { CarType_Q, Engine_Q, BreakSystem_Q, SteeringSystem_Q, Run_Test };
enum class CarType { NONE = 0, SEDAN = 1, SUV, TRUCK };
enum class Engine { NONE = 0, GM = 1, TOYOTA, WIA, BROKEN };
enum class BreakSystem { NONE = 0, MANDO = 1, CONTINENTAL, BOSCH_B };
enum class SteeringSystem { NONE = 0, BOSCH_S = 1, MOBIS };