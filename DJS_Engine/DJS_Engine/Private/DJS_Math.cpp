#include "DJS_Math.h"

Vec2::Vec2(): x(0.f), y(0.f) {}

Vec2::Vec2(float value) : x(value), y(value) {}

Vec2::Vec2(float x, float y) : x(x), y(y) {}

Vec3::Vec3() : x(0.f), y(0.f), z(0.f) {}

Vec3::Vec3(float value) : x(value), y(value), z(value) {}

Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

Vec4::Vec4() : x(0.f), y(0.f), z(0.f), w(0.f) {}

Vec4::Vec4(float value) : x(value), y(value), z(value), w(value) {}

Vec4::Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}