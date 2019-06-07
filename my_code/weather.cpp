#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

ostream& operator<<(std::ostream& os, const GPS& gps) {
	os << gps.latitude << " " << gps.longitude << endl;
	return os;
}

/*
 * A constructor for weather class.
 * */
Weather::Weather(std::string nm, GPS loc) :
    station_nm(nm), my_loc(loc) {
}

Date::Date(int d, int m, int y) :
    day(d), month(m), year(y) {
}

string Weather::get_name() const{
    return station_nm;
}

int Weather::get_rating() const{
	return rating;
}

void Weather::set_rating(int new_rating) {
	rating = new_rating;
}

void Weather::add_reading(WReading wr){
	wreadings.push_back(wr);
}

ostream& operator<<(ostream& os, const Weather& w) {
	int r = w.get_rating();
	os << w.station_nm << ": rating " << r << w.my_loc << endl;
	for(WReading a : w.wreadings) {
		os << a;
	}
	return os;
}

ostream& operator<<(ostream& os, const Date& d) {
	os << d.month << "/" << d.day << "/" << d.year << endl;
	return os;
}

ostream& operator<<(ostream& os, const WReading& r) {
	os << "Date: " << r.date << " Temperature: " << r.temperature << "Humidity: " << r.humidity << "Windspeed: " << r.windspeed << endl;
	return os;
}