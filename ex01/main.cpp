#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	uintptr_t raw_val;
	Data data;

	data.ch = '4';
	data.num = 2;
	data.str = " Seoul";

	raw_val = Serializer::serialize(&data);
	Data *data_ptr = Serializer::deserialize(raw_val);

	std::cout << data_ptr->ch << data_ptr->num << data_ptr->str << std::endl;

	int *a = new int[10];
	for (int i=0;i<10;i++)
		a[i] = (i + 1) * 3;

	short *p = reinterpret_cast<short *>(a);

	for (int i = 0; i < 10; i++)
		std::cout << *p++ << std::endl;
	return 0;
}