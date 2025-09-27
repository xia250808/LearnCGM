#define GLM_ENABLE_EXPERIMENTAL
#include "eul/eul.h"
#include "mat/mat3.h"
#include <glm/glm.hpp>
#include <glm/gtx/euler_angles.hpp>
#include "utill/utill.h"

class eul_test {
public:

	static void printMat(const glm::mat4& m) {
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j) {
				cout<< m[i][j] << "\t";
			}
			cout << "\n";
		}
	}

	static void print_test() {
		/*
		
		float yaw Y = glm::radians(65.0f);
		float pitch X = glm::radians(24.0f);
		float roll; Z = glm::radians(42.0f);
		*/
		Eul eulA = Eul(glm::radians(65.0f), glm::radians(24.0f), glm::radians(42.0f));
		eulA.print();
		Mat3 Mat3A = eulA.transToMat3();
		glm::mat4 rotationMatrix = glm::eulerAngleYXZ(glm::radians(65.0f), glm::radians(24.0f), glm::radians(42.0f));
		printMat(rotationMatrix);
		Mat3 Mat3B = Utill::transGlmMat4ToMat3(rotationMatrix);
		std::string isEqual = (Mat3A == Mat3B) ? "equal" : "no euqal";
		cout << isEqual << endl;
		Mat3B.transToEul().print();
	}
};