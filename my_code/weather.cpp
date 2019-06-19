#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

//const double C_TO_F = 9 / 5;

Image::Image(int w, int h, std::string flnm)
    : width(w), height(h)
{
    filename = flnm;
    image_buf = new char[image_sz()];
}

// copy constructor:
Image::Image(const Image& img2) {
	height = img2.height;
	width = img2.width;
	filename = img2.filename;
	image_buf = new char[image_sz()];
 	for (int i = 0; i < image_sz(); i++) {
 		image_buf[i] = img2.image_buf[i];
		}
 }

Image::~Image() {
	if (image_buf != nullptr)
		delete [] image_buf;
}

 Image& Image::operator=(const Image& img2) {
 	if (&img2 != this) {
 		if (image_buf != nullptr)
 			delete [] image_buf;
 		height = img2.height;
 		width = img2.width;
 		filename = img2.filename;
 		image_buf = new char[image_sz()];
 		for (int i = 0; i < image_sz(); i++) {
 			image_buf[i] = img2.image_buf[i];
 		}
 	}
 	return *this;
 }

int Image::image_sz() {
    return width * height;
}


void Image::copy_fields(const Image& img2) {
}


    /*
     * Setting `display() = 0` here makes this an abstract
     * class that can't be implemented.
     * 
     */

//Date::Date(int d, int m, int y) {
  //  day = d;
    //month = m;
    //year = y;
//}


//double WReading::get_tempF() {
 //   return (temperature * C_TO_F) + 32;
//}


/*
 * A constructor for weather class.
 * */
//Weather::Weather(std::string nm, GPS loc) :
  //  station_nm(nm), my_loc(loc) {
//}


//string Weather::get_name() const {
  //  return station_nm;
//}

//

virtual Image::display(std::string s) {
    return "Displaying image " + s;
}

class Gif : public Image {
  public:
  Gif(int w, int h, std::string flnm)
    : Image(w, h, flnm) {}
    void display() {
      cout << "This is gif file" << endl;
  }
}

class Jpeg : public Image {
  public:
  Jpeg(int w, int h, std::string flnm)
    : Image(w, h, flnm) {}
    void display() {
      cout << "This is Jpeg file" << endl;
  }
}

class Png : public Image {
  public:
  Png(int w, int h, std::string flnm)
    : Image(w, h, flnm) {}
    void display() {
      cout << "This is Png file" << endl;
  }
}