#include <sstream>
#include "PmergeMe.hpp"

const = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const char *arg)
{
    std::string str(arg);

    for (size_t i = 0; i < str.length(); i++)
        if (!(std::isdigit(str[i]) || str[i] == ' '))
            throw "wrong argument";
    
    bool zero_flag = false;
    int num;
    std::istringstream ss(str);
    while (ss >> num) {
        if (!num) {
            zero_flag = true;
            break;
        }
        _vec.push_back(num);
        _dq.push_back(num);
    }
    if (!ss.eof() || zero_flag)
        throw "value must be positive integer";
}

PmergeMe::PmergeMe(const PmergeMe &ref)
{
    (void) ref;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &ref)
{
    (void) ref;
    return *this;
}

PmergeMe *PmergeMe::get_instance(const char *arg)
{
    if (!_instance)
        _instance = new PmergeMe(arg);
    return _instance;
}

void PmergeMe::release_instance()
{
    if (_instance)
        delete _instance;
    _instance = NULL;
}

void Pmerge

void PmergeMe::execute()
{
    _sort_vec();
    _sort_dq();
}
