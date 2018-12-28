#include <iostream>

// Look - lots of work, for very little immediate benefit.   Thanks C++.

struct Base {
	virtual void do_thing() = 0;
	int data{};
	// Specify a default destructor
	// clang-tidy should also require copy, copy assignment, move and move assignment operators  "rule of 5"
	virtual ~Base() = default;
	Base(const Base &) = default;
	Base(Base &&) = default;
	Base &operator=(const Base &) = default;
	Base &operator=(Base &&) = default;
	// And provide a ctor
	Base() = default;
};

struct Derived : Base {
	virtual void do_thing() {
		std::cout << "Derived::do_thing()\n";
	}
};


int main() {
	
	// Bad example
	Base * b = new Derived();
	b->do_thing();
	delete b;
	// Better practice is
	std::unique_ptr<Base> c = std::unique_ptr<Base>(new Derived());
	c->do_thing();
	// Best is no dynamic allocation at all
	Derived d;
	d.do_thing();

	std::cout << "Hello World\n";
}