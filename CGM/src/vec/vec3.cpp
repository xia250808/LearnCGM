#include <iostream>
#include "mat/mat3.h"
#include "vec/vec3.h"

using namespace std;

void Vec3::print(void)const {
    std::cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
}

std::array<float, 3> Vec3::toArray()const {
    return { x,y,z };
}

Vec3 Vec3::operator+(const Vec3& other) const {
    return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::operator*(const float k) {
    return Vec3(x * k, y * k, x * k);
};

float Vec3::operator*(const Vec3& other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vec3 Vec3::cross(const Vec3& other) const {
    return Vec3(y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x);
}


Vec3 Vec3::operator*(const Mat3& M3x3)const {
    float ret[3];
    std::array<float, 3> vec3_array = toArray();
    for (int j = 0; j < Mat3::colum; j++)
    {
        ret[j] = 0;
        for (int i = 0; i < Mat3::row; i++)
        {
            ret[j] += M3x3.mat[i][j] * vec3_array[i];
        }
    }
    return Vec3(ret[0], ret[1], ret[2]);

}

float Vec3::length() const {
    return sqrtf(x * x + y * y + z * z);
}

Vec3 Vec3::normalized() const {
    float len = length();
    if (len > 0) {
        return Vec3(x / len, y / len, z / len);
    }
    return *this;
}