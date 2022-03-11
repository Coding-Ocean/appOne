#pragma once
#include"let.h"

extern const float M_PI;
extern const float M_2PI;
extern const float TO_RAD;
extern const float TO_DEG;

enum ANGLE_MODE { RADIANS, DEGREES };
extern ANGLE_MODE AngleMode;
void angleMode(ANGLE_MODE mode);
float sin(float angle); 
float cos(float angle);
float tan(float angle);
float asin(float sinAngle);
float acos(float cosAngle);
float atan(float tanAngle);
float atan2(float y, float x);
float sqrt(float square);
float pow(float a, float b);
float absolute(float a);
float round(float v);
float map(float v, float a1, float a2, float b1, float b2);
