#pragma once
#include <cmath>

template<typename T>
class tvec2 {
public:
    union {
        struct { T x, y; };
        T data[2];
    };

    tvec2() : x(0), y(0) {}
    explicit tvec2(T value) : x(value), y(value) {}
    tvec2(T x, T y) : x(x), y(y) {}

    size_t Size() const { return 2; }

    auto Length() const {
        if constexpr (std::is_integral_v<T>) {
            return std::sqrt(static_cast<double>(x * x + y * y));
        }
        else {
            return std::sqrt(x * x + y * y);
        }
    }

    auto SquareLength() const {
        if constexpr (std::is_integral_v<T>) {
            return static_cast<double>(x * x + y * y);
        }
        else {
            return x * x + y * y;
        }
    }

    auto Distance(const tvec2& other) const {
        if constexpr (std::is_integral_v<T>) {
            return std::sqrt(static_cast<double>((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y)));
        }
        else {
            return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
        }
    }

    auto SquareDistance(const tvec2& other) const {
        if constexpr (std::is_integral_v<T>) {
            return static_cast<double>((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
        }
        else {
            return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);
        }
    }

    auto Angle() const {
        if constexpr (std::is_integral_v<T>) {
            return static_cast<double>(std::atan2(y, x));
        }
        else {
            return std::atan2(y, x);
        }
    }

    static tvec2<float> FromAngle(float angle) { return tvec2(std::cos(angle), std::sin(angle)); }

    static tvec2<double> FromAngle(double angle) { return tvec2(std::cos(angle), std::sin(angle)); }

    static tvec2<float> FromAngleDegree(float angle) {
        const float PI = 3.1415926535f;
        float rad = angle / 180.0f * PI;
        return tvec2<float>(std::cos(rad), std::sin(rad));
    }

    static tvec2<double> FromAngleDegree(double angle) {
        const double PI = 3.141592653589793;
        double rad = angle / 180.0 * PI;
        return tvec2<double>(std::cos(rad), std::sin(rad));
    }

    tvec2 Lerp(const tvec2& other, float t) const { return tvec2(x + (other.x - x) * t, y + (other.y - y) * t); }

    tvec2 Lerp(const tvec2& other, double t) const { return tvec2(x + (other.x - x) * t, y + (other.y - y) * t); }

    T DotProduct(const tvec2& other) const { return x * other.x + y * other.y; }

    T CrossProduct(const tvec2& other) const { return x * other.y - y * other.x; }

    tvec2 Project(const tvec2& other) const {
        if (other.SquareLength() == 0) {
            return tvec2();
        }

        T dot = DotProduct(other);

        double k = static_cast<double>(dot) / static_cast<double>(other.SquareLength());

        return tvec2(
            static_cast<T>(k * other.x),
            static_cast<T>(k * other.y)
        );
    }

    tvec2 ProjectPerp(const tvec2& other) const { return *this - Project(other); }

    tvec2 Normalize() const { 
        if (Length() == 0) {
            return tvec2();
        }

        return *this / Length(); 
    }

    T& operator[](int i) { return data[i]; }

    const T& operator[](int i) const { return data[i]; }

    tvec2 operator+(const tvec2& other) const { return tvec2(this->x + other.x, this->y + other.y); }

    tvec2 operator+(const T& scalar) const { return tvec2(this->x + scalar, this->y + scalar); }

    tvec2 operator-(const tvec2& other) const { return tvec2(this->x - other.x, this->y - other.y); }

    tvec2 operator-(const T& scalar) const { return tvec2(this->x - scalar, this->y - scalar); }

    tvec2 operator*(const tvec2& other) const { return tvec2(this->x * other.x, this->y * other.y); }

    tvec2 operator*(const T& scalar) const { return tvec2(this->x * scalar, this->y * scalar); }

    tvec2 operator/(const tvec2& other) const { 
        T new_x = other.x != 0 ? this->x / other.x : static_cast<T>(0);
        T new_y = other.y != 0 ? this->y / other.y : static_cast<T>(0);
        return tvec2(new_x, new_y);
    }

    tvec2 operator/(const T& scalar) const { 
        if (scalar == 0) {
            return tvec2();
        }

        return tvec2(this->x / scalar, this->y / scalar); 
    }
    
    tvec2 operator+() const { return tvec2(x, y); }

    tvec2 operator-() const { return tvec2(-x, -y); }

    bool operator==(const tvec2& other) const { return (x == other.x && y == other.y); }

    bool operator!=(const tvec2& other) const { return !(*this == other); }

    tvec2& operator+=(const T& scalar) {
        this->x += scalar;
        this->y += scalar;
        return *this;
    }

    tvec2& operator+=(const tvec2& other) {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    tvec2& operator-=(const T& scalar) {
        this->x -= scalar;
        this->y -= scalar;
        return *this;
    }

    tvec2& operator-=(const tvec2& other) {
        this->x -= other.x;
        this->y -= other.y;
        return *this;
    }

    tvec2& operator*=(const T& scalar) {
        this->x *= scalar;
        this->y *= scalar;
        return *this;
    }

    tvec2& operator*=(const tvec2& other) {
        this->x *= other.x;
        this->y *= other.y;
        return *this;
    }

    tvec2& operator/=(const T& scalar) {
        if (scalar == 0) {
            this->x = 0;
            this->y = 0;
            return *this;
        }

        this->x /= scalar;
        this->y /= scalar;
        return *this;
    }

    tvec2& operator/=(const tvec2& other) {
        if (other.x != 0) {
            this->x /= other.x;
        }
        else {
            this->x = 0;
        }
        if (other.y != 0) {
            this->y /= other.y;
        }
        else {
            this->y = 0; 
        }
        return *this;
    }
};

template<typename T>
tvec2<T> operator+(const T& scalar, const tvec2<T>& vec) { return vec + scalar; }

template<typename T>
tvec2<T> operator-(const T& scalar, const tvec2<T>& vec) { return tvec2<T>(scalar - vec.x, scalar - vec.y); }

template<typename T>
tvec2<T> operator*(const T& scalar, const tvec2<T>& vec) { return vec * scalar; }

template<typename T>
tvec2<T> operator/(const T& scalar, const tvec2<T>& vec) { 
    if (vec.x == 0 || vec.y == 0) {
        return tvec2();
    }

    return tvec2(scalar / vec.x, scalar / vec.y); 
}

template<typename T>
tvec2<T> operator/(const tvec2<T>& lhs, double rhs) {
    if (rhs == 0.0) {
        return tvec2<T>();
    }
    return tvec2<T>(static_cast<T>(lhs.x / rhs), static_cast<T>(lhs.y / rhs));
}

using vec2 = tvec2<float>;
using dvec2 = tvec2<double>;
using ivec2 = tvec2<int>;