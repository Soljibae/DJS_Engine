#pragma once

template<typename T>
class tvec3 {
public:
    union {
        struct { T x, y, z; };
        T data[3];
    };

    tvec3() : x(0), y(0), z(0) {}
    tvec3(T value) : x(value), y(value), z(value) {}
    tvec3(T x, T y, T z) : x(x), y(y), z(z) {}
    tvec3(const tvec2<T>& v) : x(v.x), y(v.y), z(0) {}
    tvec3(const tvec2<T>& v, T z) : x(v.x), y(v.y), z(z) {}

    size_t size() const {
        return 3;
    }

    T& operator[](int i) { return data[i]; }
    const T& operator[](int i) const { return data[i]; }
};

using vec3 = tvec3<float>;
using dvec3 = tvec3<double>;
using ivec3 = tvec3<int>;
