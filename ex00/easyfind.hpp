#pragma once

#include <algorithm>

template <typename T>
int easyfind(const T &container, const int val)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), val);
	if (it == container.end())
		return 0;
	return 1;
}
