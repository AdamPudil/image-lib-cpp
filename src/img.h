#ifndef IMG_H
#define IMG_H

class image {
private:
	int width;
	int height;
	char * bitmap;

public:
	//image manipulation
	void fill(char red, char green, char blue);

	//file manipulation
	int save(const char * filename);
	int open(const char * filename);

	image(int width, int height);
	~image();

};



#endif 	//MESSAGE_H
