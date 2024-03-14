#include <deque>
#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	std::list<int> lst;
	std::deque<int> deq;

	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	for (int i = 0; i < 10; i++)
		lst.insert(lst.end(), i);
	for (int i = 0; i < 10; i++)
		deq.push_back(i);
	

	std::cout << easyfind(vec, 5) << '\n';
	std::cout << easyfind(vec, 11) << '\n';
	std::cout << "-------------------------\n";

	std::cout << easyfind(lst, 5) << '\n';
	std::cout << easyfind(lst, 11) << '\n';
	std::cout << "-------------------------\n";

	std::cout << easyfind(deq, 5) << '\n';
	std::cout << easyfind(deq, 11) << '\n';

	return 0;
}
