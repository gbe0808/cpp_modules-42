#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &ref) 
{
	(void) ref;
}

Serializer::~Serializer() {}

Serializer &Serializer::operator=(const Serializer &ref)
{
	(void) ref;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
