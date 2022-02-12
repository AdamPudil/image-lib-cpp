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

//point class methods

point::point(int x, int y) {
	this->x = x;
	this->y = y;

}

point::point() {
	this->x = 0;
	this->y = 0;

}

point::~point() {

}

//image class methods

//drawing methods

void image::setPixel(point a, RGB color) {
	int index = a.y * this->width + a.x;
	this->bitmap[index].r = color.r;		
	this->bitmap[index].g = color.g;		
	this->bitmap[index].b = color.b;		

}

void image::drawRect(point a, point b, RGB color) {
	for(int x = a.x; x < b.x; x++) {
		for(int y = a.y; y < b.y; y++) {
			this->setPixel(point(x, y), color);
	
		}
	}
}

void image::drawCircle(point c, int radius, RGB color) {



}

void image::fill(RGB color) {
	drawRect(point(0, 0), point(this->width, this->height), color);
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

