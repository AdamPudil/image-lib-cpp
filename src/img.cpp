#include <iostream>
#include <fstream>
#include <stdio.h>


#include "img.h"

void image::fill(char r, char g, char b) {
	for(int i = 0; i < this->width * this->height; i++) {
		this->bitmap[3 * i + 0] = r;		
		this->bitmap[3 * i + 1] = g;		
		this->bitmap[3 * i + 2] = b;		

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

