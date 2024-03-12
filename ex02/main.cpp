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

}

void identify(Base &p)
{

}

int main()
{
	Base *base = generate();

	if (base == NULL) {
		std::cout << "Bad allocation\n";
		return 1;
	}
	
}