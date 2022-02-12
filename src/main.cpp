#include <stdio.h>
#include "img.h"


int main() {
	RGB red  (char(255), 0, 0);
	RGB green(0, char(255), 0);
	RGB blue (0, 0, char(255));

	image test(360, 360);

	test.fill(red);
	test.drawRect(100, 100, 200, 200, blue);
	test.save("test.ppm");

}
