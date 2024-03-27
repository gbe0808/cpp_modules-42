#pragma once

#include <exception>
#include <vector>

class Span {
private:
	Span();

	std::vector<int> _vec;
	unsigned int _max_size;
public:
	Span(unsigned int N);
	Span(const Span &ref);
	Span &operator=(const Span &ref);
	~Span();

	void addNumber(int num);
	void addNumbers(int *nums, int size);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	class CapacityFullException : public std::exception {
		const char *what() const throw();
	};

	class SizeTooSmallException : public std::exception {
		const char *what() const throw();
	};
};