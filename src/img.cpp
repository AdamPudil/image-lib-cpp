#include "img.h"

int image::save(char * filename) {
	
	return 0;
}

image::image(int width, int height) {
	width = width;
	height = height;

	bitmap = new char [4 * width * height];

}

image::~image() {
	delete[] bitmap;

}

