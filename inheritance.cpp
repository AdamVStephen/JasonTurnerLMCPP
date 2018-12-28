#include <iostream>

struct Base {
	virtual void do_thing() = 0;
	int data;
};

struct Derived : Base {
	virtual void do_thing(int i) {}
};

