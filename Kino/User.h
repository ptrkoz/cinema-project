#pragma once
using namespace System;

public ref class User {
private:
	int id;
	String^ login;
	int permissions;
public:
	User(int id, String^ login, int permissions) {
		this->id = id;
		this->login = login;
		this->permissions = permissions;
	}

	int getId() {
		return this->id;
	}
};