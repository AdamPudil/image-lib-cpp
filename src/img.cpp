#include <iostream>
#include <fstream>
#include <stdio.h>

#include "img.h"


//RGB class methods

RGB::RGB(char r, char g, char b) {
	this->r = r;
	this->g = g;
	this->b = b;

}

RGB::RGB() {
	this->r = 0;
	this->g = 0;
	this->b = 0;

}

RGB::~RGB() {

}

//image class methods

//drawing methods

void image::setPixel(int x, int y, RGB color) {
	int index = y * this->width + x;
	this->bitmap[index].r = color.r;		
	this->bitmap[index].g = color.g;		
	this->bitmap[index].b = color.b;		

}

void image::drawRect(int x1, int y1, int x2, int y2, RGB color) {
	for(int x = x1; x < x2; x++) {
		for(int y = y1; y < y2; y++) {
			this->setPixel(x, y, color);

		}
	}
}

void image::drawCircle(int x, int y, int radius, RGB color) {



}

void image::fill(RGB color) {
	for(int x = 0; x < this->width; x++) {
		for(int y = 0; y < this->height; y++) {
			this->setPixel(x, y, color);
		
		}
	}
}

//file manipulation methods

int image::save(const char * filename) {
	FILE * file = fopen(filename, "w");
	
	if(!file) return -1;

	fprintf(file, "P6 %d %d 255\n", this->width, this->height);

	for(int i = 0; i < this->width * this->height; i++) {
		fprintf(file, "%c%c%c", this->bitmap[i].r, this->bitmap[i].g, this->bitmap[i].b );

	}

	fclose(file);
	return 0;
}

int image::open(const char * filename) {
	FILE * file = fopen(filename, "r");
	
	if(!file) return -1;

	if(!fscanf(file, "P6 %d %d 255\n", &this->width, &this->height)) return -1;

	delete[] this->bitmap;
	this->bitmap = new RGB [this->width * this->height];

	for(int i = 0; i < 3 * this->width * this->height; i++) {
		if(!fscanf(file, "%c%c%c", &this->bitmap[i].r, &this->bitmap[i].g, &this->bitmap[i].b)) {
			return -1;
		}
	}

	fclose(file);
	return 0;
}

// constructor and destructor

image::image(int width, int height) {
	this->width = width;
	this->height = height;

	this->bitmap = new RGB [this->width * this->height];

}

image::~image() {
	delete[] this->bitmap;

}

