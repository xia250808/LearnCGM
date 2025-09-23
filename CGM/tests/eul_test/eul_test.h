#include "eul/eul.h"
class eul_test {
public:
	static void print_test() {
		Eul eulA = Eul(2, 1, 4);
		eulA.print();
	}
};