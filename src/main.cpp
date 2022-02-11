#include <stdio.h>
#include "img.h"


int main() {
	image test(360, 360);
	test.fill(char(255), 0, 0);
	test.save("img.ppm");

}
