#pragma once
#include "mat/mat3.h"
#include <iostream>
#include <array>


class Mat4 {
private:
public:
    float mat4[4][4];
    static const int row = 4, colum = 4;
    Mat4();
    Mat4(array<array<float,4>,4> initMat);
    float get(int row, int colum) {
        return mat4[row][colum];
    }
    void set(int row, int colum, float value) {
        mat4[row][colum] = value;
    }

    static Mat4 Identity();

    void print(const std::string& str);

    Mat4 operator*(const Mat4& other) const;

    Mat4 operator*(const float k)const;

    Mat4 Transpose();

    Mat3 getMinorMatrix(int excludeRow, int excludecolum) const;

    float getCofactor(int i, int j);

    Mat4 getAdjMat4();

    float getMat4Determinant();

    Mat4 Inverse();

};