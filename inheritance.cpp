#include <iostream>

// Visual Studio Claims this file is under git but I can't see it yet.

struct Base {
	virtual void do_thing() = 0;
	int data;
};

struct Derived : Base {
	virtual void do_thing(int i) {}
};

