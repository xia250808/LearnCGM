#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtx/euler_angles.hpp>
#include "eul/eul.h"
#include "mat/mat3.h"
#include "quater/quater.h"
#include "utill/utill.h"

class transRotation_test {
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

	static void eul_mat3_test() {
		Eul eulA = Eul(glm::radians(65.0f), glm::radians(24.0f), glm::radians(42.0f));
		Mat3 Mat3A = eulA.transToMat3();
		glm::mat4 rotationMatrix = glm::eulerAngleYXZ(glm::radians(65.0f), glm::radians(24.0f), glm::radians(42.0f));
		Mat3 Mat3B = Utill::transGlmMat4ToMat3(rotationMatrix);
		std:string isEqual = (Mat3A == Mat3B) ? "equal" : "no euqal";
		cout << "my program result " << isEqual << " glm result" << endl;
		Mat3A.transToEul().print();
		eulA.print();
	}



	static void eul_quater_mat_test() {
		Eul eulA = Eul(glm::radians(65.0f), glm::radians(24.0f), glm::radians(42.0f));
		eulA.print();
		Mat3 Mat3A = eulA.transToMat3();
		Mat3 Mat3C = eulA.transToQuater().transToMat3();
		std:string isEqual = (Mat3A == Mat3C) ? "equal" : "no euqal";
		cout << "eul->quater->mat3|" << isEqual << " |eul->mat3" << endl;
	}

	static void eul_quater_test() {
		Eul eulA = Eul(glm::radians(65.0f), glm::radians(24.0f), glm::radians(42.0f));
		eulA.print();
		Mat3 Mat3A = eulA.transToMat3();
		Eul eulB = eulA.transToQuater().transToEul();
		std:string isEqual = (eulA == eulB) ? "equal" : "no euqal";
		cout << "eulA |" << isEqual << " |eulB" << endl;
	}

	static void tests() {
		eul_mat3_test();
		eul_quater_mat_test();
		eul_quater_test();

	}
};