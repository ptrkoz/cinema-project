#pragma once
#include <string>

using namespace System;

public ref class Movie {
private:
	int id;
	String^ name;
	String^ description;
	String^ imagePath;
public:
	Movie(int id, String^ name, String^ description, String^ imagePath) {
		this->id = id;
		this->name = name;
		this->description = description;
		this->imagePath = imagePath;
	}
	void changeName(String^ newName);

	String^ getName();
};
