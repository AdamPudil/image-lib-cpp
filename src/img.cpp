#include <iostream>
#include <fstream>
#include <stdio.h>


#include "img.h"

void image::setPixel(int x, int y, char r, char g, char b) {
	int index = 3 * (y * this->width + x);
	this->bitmap[index + 0] = r;		
	this->bitmap[index + 1] = g;		
	this->bitmap[index + 2] = b;		
}

void image::drawRect(int x1, int y1, int x2, int y2, char r, char g, char b) {
	for(int x = x1; x < x2; x++) {
		for(int y = y1; y < y2; y++) {
			this->setPixel(x, y, r, g, b);
		}
	}
}

void image::drawCircle(int x, int y, int radius, char r, char g, char b) {



}

void image::fill(char r, char g, char b) {
	for(int x = 0; x < this->width; x++) {
		for(int y = 0; y < this->height; y++) {
			this->setPixel(x, y, r, g, b);
		}
	}
}

int image::save(const char * filename) {
	FILE * file = fopen(filename, "w");
	
	if(!file) return -1;

	fprintf(file, "P6 %d %d 255\n", this->width, this->height);

	for(int i = 0; i < 3 * this->width * this->height; i++) {
		fprintf(file, "%c", this->bitmap[i]);

	}

	fclose(file);
	return 0;
}

int image::open(const char * filename) {
	FILE * file = fopen(filename, "r");
	
	if(!file) return -1;

	if(!fscanf(file, "P6 %d %d 255\n", &this->width, &this->height)) return -1;

	delete[] this->bitmap;
	this->bitmap = new char [3 * this->width * this->height];

	for(int i = 0; i < 3 * this->width * this->height; i++) {
		if(!fscanf(file, "%c", &this->bitmap[i])) return -1;

	}

	fclose(file);
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

