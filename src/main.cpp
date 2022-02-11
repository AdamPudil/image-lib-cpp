#include <stdio.h>
#include "img.h"


int main() {
	image test(360, 360);
	test.fill(char(255), 0, 0);
	test.drawRect(100, 100, 200, 200, 0, char(255), 0);
	test.save("test.ppm");

}
