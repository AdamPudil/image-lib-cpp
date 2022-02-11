#ifndef IMG_H
#define IMG_H

class image {
private:
	int width;
	int height;
	char * bitmap;

public:
	int save(char * filename);

	image(int width, int height);
	~image();

};



#endif 	//MESSAGE_H
