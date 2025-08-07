#pragma once

template<typename T>
class tvec2{
public:
    union {
        struct { T x, y; };
        T data[2];
    };

    tvec2() : x(0), y(0) {}
    tvec2(T value) : x(value), y(value) {}
    tvec2(T x, T y) : x(x), y(y) {}

    size_t size() const {
        return 2;
    }

    T& operator[](int i) { return data[i]; }
    const T& operator[](int i) const { return data[i]; }
};

using vec2 = tvec2<float>;
using dvec2 = tvec2<double>;
using ivec2 = tvec2<int>;

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

    size_t size() const {
        return 3;
    }

    T& operator[](int i) { return data[i]; }
    const T& operator[](int i) const { return data[i]; }
};

using vec3 = tvec3<float>;
using dvec3 = tvec3<double>;
using ivec3 = tvec3<int>;

template<typename T>
class tvec4 {
public:
    union {
        struct { T x, y, z, w; };
        T data[4];
    };

    tvec4() : x(0), y(0), z(0), w(0) {}
    tvec4(T value) : x(value), y(value), z(value), w(value) {}
    tvec4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

    size_t size() const {
        return 4;
    }

    T& operator[](int i) { return data[i]; }
    const T& operator[](int i) const { return data[i]; }
};

using vec4 = tvec4<float>;
using dvec4 = tvec4<double>;
using ivec4 = tvec4<int>;

template<typename T>
void VecNegate(T& result, const T& vec0)
{
    for (size_t i = 0; i < result.size(); i++)
    {
        result[i] = vec0[i] * -1;
    }
}