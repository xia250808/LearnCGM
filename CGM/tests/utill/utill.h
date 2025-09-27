#include "mat/mat3.h"
#include <glm/glm.hpp> 


class Utill
{
public:
	Utill();
	static Mat3 transGlmMat4ToMat3(const glm::mat4& m) {
		Mat3 retMat = Mat3();
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j) {
				retMat.set(i, j, m[i][j]);
			}
		}
		return retMat;
	}
	~Utill();

private:

};

Utill::Utill()
{
}

Utill::~Utill()
{
}