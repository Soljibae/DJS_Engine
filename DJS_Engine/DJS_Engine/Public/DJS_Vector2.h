#pragma once

template<typename T>
class tvec2 {
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

    tvec2 operator+(const tvec2& other) const
    {
        return tvec2(this->x + other.x, this->y + other.y);
    }

    tvec2 operator+(const T& scalar) const
    {
        return tvec2(this->x + scalar, this->y + scalar);
    }
};

template<typename T>
tvec2<T> operator+(const T& scalar, const tvec2<T>& vec)
{
    return vec + scalar;
}

using vec2 = tvec2<float>;
using dvec2 = tvec2<double>;
using ivec2 = tvec2<int>;