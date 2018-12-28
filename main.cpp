#include <iostream>

// All changes on master branch to begin with - will get to grips with VS git interface in due course.
// Episode 103 Look - lots of work, for very little immediate benefit.   Thanks C++.
// Episode 104 : first gets rid of the whole overcomplicated mess, I will keep it for reference.

// WAS hell from 103

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

int main_103() {
	
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


// Improved in 104

struct Type {
	// OK
	//void do_thing() { return data + 4; }
	// Better - make it const
	int do_thing() const { return data + 4; }
	int do_other_thing() const { return data + 6; }
	// Best : make it constexpr
	constexpr int ce_do_thing() const { return data + 4; }
	constexpr int ce_do_other_thing() const { return data + 6; }
	
	int data{};
};

int main(int argc, char * argv[]) {
	Type obj;

	if (sizeof(long) > 4) {
		obj.do_thing();
	}
	else {
		obj.ce_do_other_thing();
	}

}