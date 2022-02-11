#include <stdio.h>
#include "img.h"


int main() {
	image test(0, 0);
	if(test.open("img.ppm") != 0) printf("cannot open file");
	test.save("test.ppm");

}
