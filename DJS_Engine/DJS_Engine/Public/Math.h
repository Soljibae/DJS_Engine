#pragma once

struct Vec2 {
    union {
        struct { float x, y; };
        float data[2];
    };

    Vec2();
    Vec2(float value);
    Vec2(float x, float y);
};

struct Vec3 {
    union {
        struct { float x, y, z; };
        float data[3];
    };

    Vec3();
    Vec3(float value);
    Vec3(float x, float y, float z);
};

struct Vec4 {
    union {
        struct { float x, y, z, w; };
        float data[4];
    };

    Vec4();
    Vec4(float value);
    Vec4(float x, float y, float z, float w);
};

