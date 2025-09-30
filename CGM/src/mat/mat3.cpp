#include <cmath>
#include <array>
#include "mat/mat3.h"
#include "quater/quater.h"
#include <numbers>

using namespace std;

Mat3::Mat3() {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            mat[i][j] = 0.0f;
        }
    }
}
Mat3::Mat3(array<array<float, 3>, 3> initMat)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            mat[i][j] = initMat[i][j];
        }
    }
}

void Mat3::print(const std::string& str) {
    std::cout << "Mat3: " << str << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            cout << mat[i][j] << "\t";
        }
        cout << endl;

    }
}

void Mat3::set(int row, int colum, float value) {
    mat[row][colum] = value;
};

float Mat3::get(int row, int colum) const {
    return mat[row][colum];
};

std::array<float, 3> Mat3::getColumItems(int colum)const {
    return { get(0,colum),get(1,colum),get(2,colum) };
}

bool Mat3::operator==(const Mat3& other) const {
    bool isEqual = true;
    for (int i = 0; i < Mat3::row; i++)
    {
        for (int j = 0; j < Mat3::colum; j++)
        {
            isEqual = fabs(mat[i][j] - other.mat[i][j]) < Mat3::epsilon;
            if (!isEqual)
            {
                return isEqual;
            }
        }

    }
    return isEqual;
}

float Mat3::getMat3Determinant() {
    float M00[4] = { mat[1][1],mat[1][2],mat[2][1],mat[2][2] };
    float M01[4] = { mat[1][0],mat[1][2],mat[2][0],mat[2][2] };
    float M02[4] = { mat[1][0],mat[1][1],mat[2][0],mat[2][1] };
    float c00 = mat[0][0] * get2x2Determinant(M00);
    float c01 = -mat[0][1] * get2x2Determinant(M01);
    float c02 = mat[0][2] * get2x2Determinant(M02);
    float determinant = c00 + c01 + c02;
    return determinant;
}

Quater Mat3::transToQuater() {

}

Eul Mat3::transToEul() {
    float p;
    float y;
    float r;
    float sp = -mat[2][1];
    if (sp <= -1.0f){

        p = -numbers::pi / 2;
    }else if(sp >= 1.0f){

        p = numbers::pi / 2;

    }else {

        p = asin(sp);
    }
    if (fabs(sp) > 0.9999f)
    {
        r = 0.0f;
        y = atan2(mat[0][2], mat[0][0]);
    } else {
        y = atan2(mat[2][0], mat[2][2]);
        r = atan2(mat[0][1], mat[1][1]);
    }
    return Eul(y, p, r);
}