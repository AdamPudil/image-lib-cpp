#ifndef IMG_H
#define IMG_H

class image {
private:
	int width;
	int height;
	char * bitmap;

public:
	//image manipulation
	void setPixel(int x, int y, char r, char g, char b);
	void drawRect(int x1, int y1, int x2, int y2, char r, char g, char b);
	void drawCircle(int x, int y, int radius, char r, char g, char b);
	void fill(char r, char g, char b);

	//file manipulation
	int save(const char * filename);
	int open(const char * filename);

	image(int width, int height);
	~image();

};



#endif 	//MESSAGE_H
