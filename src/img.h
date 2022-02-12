#ifndef IMG_H
#define IMG_H

class RGB {
public:
	char r, g, b;

	RGB(char r, char g, char b);
	RGB();
	~RGB();
};

class image {
private:
	int width;
	int height;
	RGB * bitmap;

public:
	//image manipulation
	void setPixel(int x, int y, RGB color);
	void drawRect(int x1, int y1, int x2, int y2, RGB color);
	void drawCircle(int x, int y, int radius, RGB color);
	void fill(RGB color);

	//file manipulation
	int save(const char * filename);
	int open(const char * filename);

	image(int width, int height);
	~image();

};



#endif 	//MESSAGE_H
