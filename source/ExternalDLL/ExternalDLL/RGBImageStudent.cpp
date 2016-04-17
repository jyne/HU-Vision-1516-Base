#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	//TODO: Nothing
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : 
RGBImage(other.getWidth(), other.getHeight()),
map{ new RGB*[getHeight()] }
{
    for (int i = 0; i < getHeight(); ++i) {
        map[i] = new RGB[getWidth()];
        for (int j = 0; j < getWidth(); ++j){
            map[i][j] = other.map[i][j];
        }
    }
    
}


RGBImageStudent::RGBImageStudent(const int width, const int height) :
RGBImage(width, height),
map{ new RGB*[height] }{
    for (int i = 0; i < height; ++i){
        map[i] = new RGB[width];
    }
	//TODO: Initialize pixel storage
}

RGBImageStudent::~RGBImageStudent() {
    delete[] map;
	//TODO: delete allocated objects
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
 delete[] map;
 this->map = new RGB*[height];
 for (int i = 0; i < height; ++i){
     map[i] = new RGB[width];
 }
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
 delete[] map;
 this->map = new RGB*[getHeight()];
 for (int i = 0; i < getHeight(); ++i) {
     map[i] = new RGB[getWidth()];
     for (int j = 0; j < getWidth(); ++j){
         map[i][j] = other.map[i][j];
     }
 }
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
    map[y][x] = pixel;
	//TODO: no comment needed :)
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
    int arrayPositionWidth = i % getWidth();
    int arrayPositionLength = i / getWidth();
    map[arrayPositionLength][arrayPositionWidth] = pixel;
	/*
	* TODO: set pixel i in "Row-Major Order"
	*
	*
	* Original 2d image (values):
	* 9 1 2
	* 4 3 5
	* 8 7 8
	*
	* 1d representation (i, value):
	* i		value
	* 0		9
	* 1		1
	* 2		2
	* 3		4
	* 4		3
	* 5		5
	* 6		8
	* 7		7
	* 8		8
	*/
}

RGB RGBImageStudent::getPixel(int x, int y) const {
    return map[y][x];
	//TODO: no comment needed :)
}

RGB RGBImageStudent::getPixel(int i) const {
    int arrayPositionWidth = i % getWidth();
    int arrayPositionLength = i / getWidth();
    return map[arrayPositionLength][arrayPositionWidth];
	//TODO: see setPixel(int i, RGB pixel)
}