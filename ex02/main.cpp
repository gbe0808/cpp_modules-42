#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate()
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	Base *ret = NULL;

    int rand_val = std::rand() % 3;
	if (rand_val == 0) {
		std::cout << "A generated\n";
		ret = new A();
	}
	else if (rand_val == 1) {
		std::cout << "B generated\n";
		ret = new B();
	}
	else {
		std::cout << "C generated\n";
		ret = new C();
	}

	return ret;
}

void identify(Base *p)
{
	std::cout << "identify(pointer)\n";
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "A로 캐스팅 되었습니다.\n";
	}
	else if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "B로 캐스팅 되었습니다.\n";
	}
	else if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "C로 캐스팅 되었습니다.\n";
	}
	else {
		std::cout << "캐스팅 되지 못함\n";
	}
}

void identify(Base &p)
{
	std::cout << "identify(reference)\n";
	try {
		A a = dynamic_cast<A &>(p);
		std::cout << "A로 캐스팅 되었습니다.\n";
		(void) a;
	} catch (std::bad_cast &e) {
		std::cerr << e.what() << '\n';
	}
	
	try {
		B b = dynamic_cast<B &>(p);
		std::cout << "B로 캐스팅 되었습니다.\n";
		(void) b;
	} catch (std::bad_cast &e) {
		std::cerr << e.what() << '\n';
	}

	try {
		C c = dynamic_cast<C &>(p);
		std::cout << "C로 캐스팅 되었습니다.\n";
		(void) c;
	} catch (std::bad_cast &e) {
		std::cerr << e.what() << '\n';
	}
}

int main()
{
	Base *base = generate();

	if (base == NULL) {
		std::cout << "Bad allocation\n";
		return 1;
	}
	
	// pointer
	identify(base);

	// reference
	identify(*base);
}