#include "VESC_can_messages.h"

VESC_SetDuty_t Compose_VESC_SetDuty(float duty){
}
void Parse_VESC_SetDuty(uint8_t* data, float* duty){
}

VESC_SetCurrent_t Compose_VESC_SetCurrent(float current){
}
void Parse_VESC_SetCurrent(uint8_t* data, float* current){
}

VESC_SetCurrentBrake_t Compose_VESC_SetCurrentBrake(float currentBrake){
}
void Parse_VESC_SetCurrentBrake(uint8_t* data, float* currentBrake){
}

VESC_SetRPM_t Compose_VESC_SetRPM(int32_t rpm){
}
void Parse_VESC_SetRPM(uint8_t* data, int32_t* rpm){
}

VESC_CANStatusPacket_t Compose_VESC_CANStatusPacket(int32_t rpm, float current, float duty){
}
void Parse_VESC_CANStatusPacket(uint8_t* data, int32_t* rpm, float* current, float* duty){
}

VESC_SetCurrentRel_t Compose_VESC_SetCurrentRel(float currentRel){
}
void Parse_VESC_SetCurrentRel(uint8_t* data, float* currentRel){
}

VESC_SetCurrentBrakeRel_t Compose_VESC_SetCurrentBrakeRel(float currentBrakeRel){
}
void Parse_VESC_SetCurrentBrakeRel(uint8_t* data, float* currentBrakeRel){
}

VESC_SetCurrentHandbrake_t Compose_VESC_SetCurrentHandbrake(float currentHandbrake){
}
void Parse_VESC_SetCurrentHandbrake(uint8_t* data, float* currentHandbrake){
}

VESC_SetCurrentHandbrakeRel_t Compose_VESC_SetCurrentHandbrakeRel(float currentHandbrakeRel){
}
void Parse_VESC_SetCurrentHandbrakeRel(uint8_t* data, float* currentHandbrakeRel){
}

VESC_CANStatusPacket2_t Compose_VESC_CANStatusPacket2(float ampHoursDrive, float ampHoursRegen){
}
void Parse_VESC_CANStatusPacket2(uint8_t* data, float* ampHoursDrive, float* ampHoursRegen){
}

VESC_CANStatusPacket3_t Compose_VESC_CANStatusPacket3(float wattHoursDrive, float wattHoursRegen){
}
void Parse_VESC_CANStatusPacket3(uint8_t* data, float* wattHoursDrive, float* wattHoursRegen){
}

VESC_CANStatusPacket4_t Compose_VESC_CANStatusPacket4(float mostfetTemperature, float motorTemperature, float inputCurrent, float pidPos){
}
void Parse_VESC_CANStatusPacket4(uint8_t* data, float* mostfetTemperature, float* motorTemperature, float* inputCurrent, float* pidPos){
}

VESC_Ping_t Compose_VESC_Ping(){
}
void Parse_VESC_Ping(uint8_t* data){
}

VESC_Pong_t Compose_VESC_Pong(){
}
void Parse_VESC_Pong(uint8_t* data){
}

VESC_SetCurrentLimits_t Compose_VESC_SetCurrentLimits(float minCurrentLimit, float maxCurrentLimit){
}
void Parse_VESC_SetCurrentLimits(uint8_t* data, float* minCurrentLimit, float* maxCurrentLimit){
}

VESC_SetCurrentLimitsEEPROM_t Compose_VESC_SetCurrentLimitsEEPROM(float minCurrentLimit, float maxCurrentLimit){
}
void Parse_VESC_SetCurrentLimitsEEPROM(uint8_t* data, float* minCurrentLimit, float* maxCurrentLimit){
}

VESC_SetCurrentInLimits_t Compose_VESC_SetCurrentInLimits(float minCurrentInLimit, float maxCurrentInLimit){
}
void Parse_VESC_SetCurrentInLimits(uint8_t* data, float* minCurrentInLimit, float* maxCurrentInLimit){
}

VESC_CANStatusPacket5_t Compose_VESC_CANStatusPacket5(int32_t tachoRPM, float inputVoltage, float reserved){
}
void Parse_VESC_CANStatusPacket5(uint8_t* data, int32_t* tachoRPM, float* inputVoltage, float* reserved){
}

