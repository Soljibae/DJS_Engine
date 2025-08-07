#pragma once

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
    tvec4(const tvec2<T>& v) : x(v.x), y(v.y), z(0), w(0) {}
    tvec4(const tvec2<T>& v1, const tvec2<T>& v2) : x(v1.x), y(v1.y), z(v2.x), w(v2.y) {}
    tvec4(const tvec3<T>& v) : x(v.x), y(v.y), z(v.z), w(0) {}
    tvec4(const tvec3<T>& v, T w) : x(v.x), y(v.y), z(v.z), w(w) {}

    size_t size() const {
        return 4;
    }

    T& operator[](int i) { return data[i]; }
    const T& operator[](int i) const { return data[i]; }
};

using vec4 = tvec4<float>;
using dvec4 = tvec4<double>;
using ivec4 = tvec4<int>;
