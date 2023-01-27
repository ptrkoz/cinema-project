#include "Movie.h"

void Movie::changeName(String^ NewName) {
	this->name = NewName;
}

String^ Movie::getName() {
	return this->name;
}