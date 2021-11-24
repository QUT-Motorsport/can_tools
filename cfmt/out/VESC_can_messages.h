#ifndef _VESC_CAN_MESSAGES_H_
#define _VESC_CAN_MESSAGES_H_

// Generated on: 2021-11-15 19:27:43.2592053 +1000 AEST m=+0.007044401
// By: DESKTOP-6C52M7S\trfra

// VESC | SetDuty command
typedef struct VESC_SetDuty_t {
	uint32_t id;
	uint8_t data[4];
} VESC_SetDuty_t;

VESC_SetDuty_t Compose_VESC_SetDuty(float duty);
void Parse_VESC_SetDuty(uint8_t* data, float* duty);

// VESC | SetCurrent command
typedef struct VESC_SetCurrent_t {
	uint32_t id;
	uint8_t data[4];
} VESC_SetCurrent_t;

VESC_SetCurrent_t Compose_VESC_SetCurrent(float current);
void Parse_VESC_SetCurrent(uint8_t* data, float* current);

// VESC | SetCurrentBrake command
typedef struct VESC_SetCurrentBrake_t {
	uint32_t id;
	uint8_t data[4];
} VESC_SetCurrentBrake_t;

VESC_SetCurrentBrake_t Compose_VESC_SetCurrentBrake(float currentBrake);
void Parse_VESC_SetCurrentBrake(uint8_t* data, float* currentBrake);

// VESC | SetRPM command
typedef struct VESC_SetRPM_t {
	uint32_t id;
	uint8_t data[4];
} VESC_SetRPM_t;

VESC_SetRPM_t Compose_VESC_SetRPM(int32_t rpm);
void Parse_VESC_SetRPM(uint8_t* data, int32_t* rpm);

// VESC | CANStatusPacket command
typedef struct VESC_CANStatusPacket_t {
	uint32_t id;
	uint8_t data[8];
} VESC_CANStatusPacket_t;

VESC_CANStatusPacket_t Compose_VESC_CANStatusPacket(int32_t rpm, float current, float duty);
void Parse_VESC_CANStatusPacket(uint8_t* data, int32_t* rpm, float* current, float* duty);

// VESC | SetCurrentRel command
typedef struct VESC_SetCurrentRel_t {
	uint32_t id;
	uint8_t data[4];
} VESC_SetCurrentRel_t;

VESC_SetCurrentRel_t Compose_VESC_SetCurrentRel(float currentRel);
void Parse_VESC_SetCurrentRel(uint8_t* data, float* currentRel);

// VESC | SetCurrentBrakeRel command
typedef struct VESC_SetCurrentBrakeRel_t {
	uint32_t id;
	uint8_t data[4];
} VESC_SetCurrentBrakeRel_t;

VESC_SetCurrentBrakeRel_t Compose_VESC_SetCurrentBrakeRel(float currentBrakeRel);
void Parse_VESC_SetCurrentBrakeRel(uint8_t* data, float* currentBrakeRel);

// VESC | SetCurrentHandbrake command
typedef struct VESC_SetCurrentHandbrake_t {
	uint32_t id;
	uint8_t data[4];
} VESC_SetCurrentHandbrake_t;

VESC_SetCurrentHandbrake_t Compose_VESC_SetCurrentHandbrake(float currentHandbrake);
void Parse_VESC_SetCurrentHandbrake(uint8_t* data, float* currentHandbrake);

// VESC | SetCurrentHandbrakeRel command
typedef struct VESC_SetCurrentHandbrakeRel_t {
	uint32_t id;
	uint8_t data[4];
} VESC_SetCurrentHandbrakeRel_t;

VESC_SetCurrentHandbrakeRel_t Compose_VESC_SetCurrentHandbrakeRel(float currentHandbrakeRel);
void Parse_VESC_SetCurrentHandbrakeRel(uint8_t* data, float* currentHandbrakeRel);

// VESC | CANStatusPacket2 command
typedef struct VESC_CANStatusPacket2_t {
	uint32_t id;
	uint8_t data[8];
} VESC_CANStatusPacket2_t;

VESC_CANStatusPacket2_t Compose_VESC_CANStatusPacket2(float ampHoursDrive, float ampHoursRegen);
void Parse_VESC_CANStatusPacket2(uint8_t* data, float* ampHoursDrive, float* ampHoursRegen);

// VESC | CANStatusPacket3 command
typedef struct VESC_CANStatusPacket3_t {
	uint32_t id;
	uint8_t data[8];
} VESC_CANStatusPacket3_t;

VESC_CANStatusPacket3_t Compose_VESC_CANStatusPacket3(float wattHoursDrive, float wattHoursRegen);
void Parse_VESC_CANStatusPacket3(uint8_t* data, float* wattHoursDrive, float* wattHoursRegen);

// VESC | CANStatusPacket4 command
typedef struct VESC_CANStatusPacket4_t {
	uint32_t id;
	uint8_t data[8];
} VESC_CANStatusPacket4_t;

VESC_CANStatusPacket4_t Compose_VESC_CANStatusPacket4(float mostfetTemperature, float motorTemperature, float inputCurrent, float pidPos);
void Parse_VESC_CANStatusPacket4(uint8_t* data, float* mostfetTemperature, float* motorTemperature, float* inputCurrent, float* pidPos);

// VESC | Ping command
typedef struct VESC_Ping_t {
	uint32_t id;
	uint8_t data[0];
} VESC_Ping_t;

VESC_Ping_t Compose_VESC_Ping();
void Parse_VESC_Ping(uint8_t* data);

// VESC | Pong command
typedef struct VESC_Pong_t {
	uint32_t id;
	uint8_t data[0];
} VESC_Pong_t;

VESC_Pong_t Compose_VESC_Pong();
void Parse_VESC_Pong(uint8_t* data);

// VESC | SetCurrentLimits command
typedef struct VESC_SetCurrentLimits_t {
	uint32_t id;
	uint8_t data[8];
} VESC_SetCurrentLimits_t;

VESC_SetCurrentLimits_t Compose_VESC_SetCurrentLimits(float minCurrentLimit, float maxCurrentLimit);
void Parse_VESC_SetCurrentLimits(uint8_t* data, float* minCurrentLimit, float* maxCurrentLimit);

// VESC | SetCurrentLimitsEEPROM command
typedef struct VESC_SetCurrentLimitsEEPROM_t {
	uint32_t id;
	uint8_t data[8];
} VESC_SetCurrentLimitsEEPROM_t;

VESC_SetCurrentLimitsEEPROM_t Compose_VESC_SetCurrentLimitsEEPROM(float minCurrentLimit, float maxCurrentLimit);
void Parse_VESC_SetCurrentLimitsEEPROM(uint8_t* data, float* minCurrentLimit, float* maxCurrentLimit);

// VESC | SetCurrentInLimits command
typedef struct VESC_SetCurrentInLimits_t {
	uint32_t id;
	uint8_t data[8];
} VESC_SetCurrentInLimits_t;

VESC_SetCurrentInLimits_t Compose_VESC_SetCurrentInLimits(float minCurrentInLimit, float maxCurrentInLimit);
void Parse_VESC_SetCurrentInLimits(uint8_t* data, float* minCurrentInLimit, float* maxCurrentInLimit);

// VESC | CANStatusPacket5 command
typedef struct VESC_CANStatusPacket5_t {
	uint32_t id;
	uint8_t data[8];
} VESC_CANStatusPacket5_t;

VESC_CANStatusPacket5_t Compose_VESC_CANStatusPacket5(int32_t tachoRPM, float inputVoltage, float reserved);
void Parse_VESC_CANStatusPacket5(uint8_t* data, int32_t* tachoRPM, float* inputVoltage, float* reserved);

#endif