// Filename: Disc.cpp
// Date Created: 04/10/2012
// Author: Lance Baker
// Course: SENG6120
// Student Number: c3128034

#include <iostream>
#include <cstdlib>
#include "string"
#include "Disc.h"
using namespace std;
using lance_project::Disc;

namespace lance_project {

	Disc::Disc(string value) {
		this->value = value;
	}
	
	Disc::~Disc() {

	}
	
	void Disc::setValue(string value) {
		this->value = value;
	}
	
	string Disc::getValue() {
		return this->value;
	}
	
	int Disc::getCount() {
		return count(this->value.begin(), this->value.end(), 'X');
	}
	
	ostream & operator<<(ostream & out, Disc * obj) {
		out << obj->getValue();
		return out;
	}
}
