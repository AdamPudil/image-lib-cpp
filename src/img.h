#ifndef IMG_H
#define IMG_H

class image {
private:
	int width;
	int height;
	char * bitmap;

public:
	void fill(char red, char green, char blue);

	int save(const char * filename);

	image(int width, int height);
	~image();

};



#endif 	//MESSAGE_H
