#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

const double C_TO_F = 9 / 5;

Image::Image(int w, int h, std::string flnm)
    : width(w), height(h)
{
    filename = flnm;
    image_buf = new char[image_sz()];
}

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

Date::Date(int d, int m, int y) {
   day = d;
    month = m;
    year = y;
}


double WReading::get_tempF() {
   return (temperature * C_TO_F) + 32;
}

Weather::Weather(std::string nm, GPS loc) :
   station_nm(nm), my_loc(loc) {
}


string Weather::get_name() const {
   return station_nm;
}

void Png::display() {
  cout << "png display" << endl;
}

void Jpeg::display() {
  cout << "jpeg display" << endl;
}


void Gif::display() {
  cout << "gif display" << endl;
}

void Image::display() {
    cout << "image display" << endl;
}

void WReading::display_image() {
  image->display();
}

void Weather::display_images() {
    for(int i = 0; i < wreadings.size(); i++){
      wreadings[i].display_image();
    }
}

ostream& operator<<(ostream& os, const Weather& w) {
    int r = w.get_rating();
    os << w.station_nm << ": rating " << r << w.my_loc << endl;
    for(WReading a : w.wreadings) {
      os << a;
    }
    return os;
  }

  ostream& operator<<(std::ostream& os, const GPS& gps) {
    os << gps.latitude << " " << gps.longitude << endl;
    return os;
  }

  ostream& operator<<(ostream& os, const Date& d) {
    os << d.month << "/" << d.day << "/" << d.year << endl;
    return os;}

    ostream& operator<<(ostream& os, const WReading& r) {
    os << "Date: " << r.date << " Temperature: " << r.temperature << "Humidity: " << r.humidity << "Windspeed: " << r.windspeed << endl;
    return os;
  }

  int Weather::get_rating() const{
    return rating;
  }

void Weather::add_reading(WReading wr){
    wreadings.push_back(wr);
  }

Jpeg::Jpeg(int w, int h, std::string flnm)
    : Image(width, height, flnm), width(w), height(h){}

Gif::Gif(int w, int h, std::string flnm)
    : Image(width, height, flnm), width(w), height(h){}

Png::Png(int w, int h, std::string flnm)
    : Image(width, height, flnm), width(w), height(h){}