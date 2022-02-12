#ifndef IMG_H
#define IMG_H

class RGB {
public:
	char r, g, b;

	RGB(char r, char g, char b);
	RGB();
	~RGB();
};

class point {
public:
	int x;
	int y;
	
	point(int x, int y);
	point();
	~point();
};

class image {
private:
	int width;
	int height;
	RGB * bitmap;

public:
	//image manipulation
	void setPixel(point a, RGB color);
	void drawRect(point a, point b, RGB color);
	void drawCircle(point c, int radius, RGB color);
	void fill(RGB color);

	//file manipulation
	int save(const char * filename);
	int open(const char * filename);

	image(int width, int height);
	~image();

};



#endif 	//MESSAGE_H
