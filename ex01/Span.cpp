#include <cmath>
#include <climits>
#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : _vec(N), _idx(0) {}

Span::Span(const Span &ref) : _vec(ref._vec), _idx(static_cast<unsigned int>(_vec.size())) {}

Span &Span::operator=(const Span &ref)
{
	_vec = ref._vec;
	_idx = _vec.size();
	return *this;
}

Span::~Span() {}

void Span::addNumber(int num)
{
	if (static_cast<size_t>(_idx) >= _vec.capacity())
		throw CapacityFullException();
	_vec[_idx++] = num;
}

unsigned int Span::shortestSpan() const
{
	if (_vec.size() <= 1)
		throw SizeTooSmallException();

	std::vector<int>::const_iterator it1, it2;
	unsigned int shortest = INT_MAX;

	for (it1 = _vec.begin(); it1 != _vec.end(); ++it1) {
		for (it2 = it1 + 1; it2 != _vec.end(); ++it2) {
			unsigned int span = static_cast<unsigned int>(std::abs(*it2 - *it1));
			if (span < shortest)
				shortest = span;
		}
	}

	return shortest;
}

unsigned int Span::longestSpan() const
{
	if (_vec.size() <= 1)
		throw SizeTooSmallException();

	int min_element = INT_MAX, max_element = INT_MIN;

	for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); it++)
	{
		if (*it < min_element)
			min_element = *it;
		if (*it > max_element)
			max_element = *it;
	}

	return static_cast<unsigned int>(max_element - min_element);
}

const char *Span::CapacityFullException::what() const throw()
{
	return "Vector Capacity is full";
}

const char *Span::SizeTooSmallException::what() const throw()
{
	return "Vector size is too small";
}
