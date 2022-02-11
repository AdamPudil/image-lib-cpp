#include <iostream>
#include <fstream>
#include "img.h"

void image::fill(char r, char g, char b) {
	for(int i = 0; i < this->width * this->height; i++) {
		this->bitmap[3 * i + 0] = r;		
		this->bitmap[3 * i + 1] = g;		
		this->bitmap[3 * i + 2] = b;		

	}
}

int image::save(const char * filename) {
	std::ofstream file;
	file.open(filename);
	
	if(!file) return -1;

	file << "P6 "; // set "magic number" to P6 (pixmap with binary encoding)
	file << this->width << ' ' << this->height << " 255\n";

	for(int i = 0; i < 3 * this->width * this->height; i++) {
		file << this->bitmap[i];

	}

	return 0;
}

image::image(int width, int height) {
	this->width = width;
	this->height = height;

	this->bitmap = new char [3 * this->width * this->height];

}

image::~image() {
	delete[] this->bitmap;

}

