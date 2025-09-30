#include "mat/mat4.h"
using namespace std;

Mat4::Mat4() {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            mat4[i][j] = 0.0f;
        }
    }
}
Mat4::Mat4(array<array<float, 4>, 4> initMat)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            mat4[i][j] = initMat[i][j];
        }
    }
}
void Mat4::print(const std::string& str) {
    std::cout << "mat4: " << str << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            cout << mat4[i][j] << "\t";
        }
        cout << endl;
        cout << endl;

    }
}


Mat4 Mat4::operator*(const float k) const {
    Mat4 retmat4;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            retmat4.mat4[i][j] = mat4[i][j] * k;
        }
    }
    return retmat4;
}

Mat4 Mat4::Transpose() {
    Mat4 retmat4 = Mat4();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            retmat4.mat4[j][i] = mat4[i][j];
        }
    }
    return retmat4;
}

Mat4 Mat4::operator*(const Mat4& other)const {
    Mat4 retmat4;
    if (this->colum != other.row)
    {
        throw "this matrix product not define!";
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            float dotProduct = 0;
            for (int k = 0; k < 4; k++)
            {
                dotProduct += mat4[i][k] * other.mat4[k][j];
            }
            retmat4.mat4[i][j] = dotProduct;
        }
    }
    return retmat4;
}

Mat4 Mat4::Identity() {
    Mat4 retmat4 = Mat4();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            if (i == j)
            {
                retmat4.mat4[i][j] = 1.0f;
            }
            else
            {
                retmat4.mat4[i][j] = 0.0f;
            }
        }
    }
    return retmat4;
}

Mat3 Mat4::getMinorMatrix(int excludeRow, int excludecolum) const {
    if (excludeRow >= row || excludecolum >= colum)
    {
        throw "error";
    }
    Mat3 retMat3 = Mat3();
    int mat3RowIndex = 0;
    for (int i = 0; i < row; i++)
    {
        if (i == excludeRow) {
            continue;
        }
        int mat3cloumIndex = 0;
        for (int j = 0; j < colum; j++) {
            if (j == excludecolum) {
                continue;
            }
            retMat3.set(mat3RowIndex, mat3cloumIndex, mat4[i][j]);
            mat3cloumIndex++;
        }
        mat3RowIndex++;
    }
    return retMat3;
}

float Mat4::getCofactor(int i, int j) {
    int sig;
    sig = (i + j) % 2 == 0 ? 1 : -1;
    return sig * getMinorMatrix(i, j).getMat3Determinant();
}

Mat4 Mat4::getAdjMat4() {
    Mat4 cofactormat4 = Mat4();
    Mat4 retmat4 = Mat4();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            cofactormat4.mat4[i][j] = getCofactor(i, j);
        }

    }
    retmat4 = cofactormat4.Transpose();
    return retmat4;
}

float Mat4::getMat4Determinant() {
    float Determinant = 0.0f;
    int i = 0;
    for (int j = 0; j < colum; j++)
    {
        Determinant += this->mat4[0][j] * getCofactor(i, j);
    }
    return Determinant;
}

Mat4 Mat4::Inverse() {
    float determinant = getMat4Determinant();
    Mat4 adjmat4 = getAdjMat4();
    return adjmat4 * (1 / determinant);
}