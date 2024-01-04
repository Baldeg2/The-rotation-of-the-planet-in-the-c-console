#pragma once
#include <math.h>
#include "Vec2.h"
#include "Vec3.h"

float clamp(float value, float min, float max) {
	return fmax(fmin(value, max), min);
}

float length(vec2 const& v) {
	return sqrt(v.x * v.x + v.y * v.y); 
}

float length(vec3 const& v) { 
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); 
}

vec3 norm(vec3 v) { 
	return v / length(v); 
}

float dot(vec3 const& a, vec3 const& b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

vec2 sphere(vec3 ro, vec3 rd, float r) {
    float b = dot(ro, rd);
    float c = dot(ro, ro) - r * r;
    float h = b * b - c;
    if (h < 0.0) return vec2(-1.0);
    h = sqrt(h);
    return vec2(-b - h, -b + h);
}