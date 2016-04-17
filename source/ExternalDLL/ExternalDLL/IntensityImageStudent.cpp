#include "IntensityImageStudent.h"
#include <iostream>

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
//TODO: Nothing
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : 
IntensityImage(other.getWidth(), other.getHeight()),
map{new Intensity*[getHeight()]}
{
    for (int i = 0; i < getHeight(); ++i) {
        map[i] = new Intensity[getWidth()];
        for (int j = 0; j < getWidth(); ++j){
            map[i][j] = other.map[i][j];
        }
    }
    //std::cout << "IntensityImageStudent(const IntensityImageStudent &other)" << std::endl;
	//TODO: Create a copy from the other object
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : 
IntensityImage(width, height),
map{new Intensity*[height]}{
    for (int i = 0; i < height; ++i){
        map[i] = new Intensity[width];
    }
    //std::cout << "IntensityImageStudent(const int width, const int height)" << std::endl;
}

IntensityImageStudent::~IntensityImageStudent() {
    delete[] map;
	//TODO: delete allocated objects
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
 //std::cout << "set(const int width, const int height):" << std::endl;
 delete[] map;
 this->map = new Intensity*[height];
 for (int i = 0; i < height; ++i){
     map[i] = new Intensity[width];
 }
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage) (1);
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
 //std::cout << "set(const IntensityImageStudent &other):" << std::endl;
 delete[] map;
 this->map = new Intensity*[getHeight()];
 for (int i = 0; i < getHeight(); ++i) {
     map[i] = new Intensity[getWidth()];
     for (int j = 0; j < getWidth(); ++j){
         map[i][j] = other.map[i][j];
     }
 }
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
    //std::cout << "ssetPixel(int x, int y, RGB pixel):" <<getPixel(x,y) << std::endl; //(2);
    map[y][x] = pixel;
	//TODO: no comment needed :)
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
    //std::cout << "setPixel(int i, Intensity pixel):" << std::endl;
    int arrayPositionWidth = i % getWidth();
    int arrayPositionLength = i/getWidth();
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

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	//TODO: no comment needed :) (3);
    //std::cout << "getPixel(int x, int y):" << std::endl;
    return map[y][x];
}

Intensity IntensityImageStudent::getPixel(int i) const {
    //std::cout << "getPixel(int i):" << std::endl;
    int arrayPositionWidth = i % getWidth();
    int arrayPositionLength = i / getWidth();
    return map[arrayPositionLength][arrayPositionWidth];
	//TODO: see setPixel(int i, RGB pixel)
}