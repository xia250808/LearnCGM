#define GLM_ENABLE_EXPERIMENTAL
#include "eul/eul.h"
#include "mat/mat3.h"
#include <glm/glm.hpp>
#include <glm/gtx/euler_angles.hpp>
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

	static Mat3 toMat3(const glm::mat4& m) {
		Mat3 retMat = Mat3();
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j) {
				retMat.set(i,j,m[i][j]);
			}
		}
		return retMat;
	}
	static void print_test() {
		/*
		
		float yaw Y = glm::radians(65.0f);
		float pitch X = glm::radians(24.0f);
		float roll; Z = glm::radians(42.0f);
		*/
		Eul eulA = Eul(glm::radians(65.0f), glm::radians(24.0f), glm::radians(42.0f));
		eulA.print();
		// R P Y => Z X Y
		eulA.transToMat3().print("eulA.transToMat3");
		glm::mat4 rotationMatrix = glm::eulerAngleYXZ(glm::radians(65.0f), glm::radians(24.0f), glm::radians(42.0f));
		printMat(rotationMatrix);
		Mat3 B =toMat3(rotationMatrix);
		B.print("MAT3 :");
		B.transToEul().print();
	}
};