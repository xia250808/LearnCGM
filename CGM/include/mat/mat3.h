#pragma once
#include <iostream>
#include <array>
#include "eul/eul.h"

class Eul;
using namespace std;
struct ColumItems
{
    float a = 0.0f;
    float b = 0.0f;
    float c = 0.0f;
    float d = 0.0f;
};
class Mat3 {
private:
    float get2x2Determinant(const float matrix2x2[4]) {
        return matrix2x2[0] * matrix2x2[3] - matrix2x2[1] * matrix2x2[2];
    }
public:
    float mat[3][3];
    static const int row = 3, colum = 3;
    const float epsilon = 1e-6f;

    Mat3();
    void set(int row, int colum, float value);
    float get(int row, int colum) const;
    std::array<float,row> getColumItems(int coum)const;
    void print(const std::string& str);
    float getMat3Determinant();
    Eul transToEul();
    bool operator==(const Mat3& other) const;
};