#include <stdio.h>
#include "img.h"


int main() {
	RGB red  (char(255), 0, 0);
	RGB green(0, char(255), 0);
	RGB blue (0, 0, char(255));

	image test(400, 360);

	test.fill(RGB(char(255), char(255), 0));
	test.drawRect(point(100, 100), point(200, 200), blue);
	test.save("test.ppm");

}
