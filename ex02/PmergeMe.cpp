#include <cstring>
#include <sstream>
#include <iostream>
#include "PmergeMe.hpp"

const size_t PmergeMe::Jacobsthal[] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381};
PmergeMe *PmergeMe::_instance = NULL;

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv)
{
    int num;
    for (int i = 1; i < argc; i++) {
        if (!(std::isdigit(argv[i][0]) || argv[i][0] == '+'))
            throw "value must be a positive integer";
        for (size_t j = 1; j < std::strlen(argv[i]); j++) {
            if (!std::isdigit(argv[i][j]))
                throw "value must be a positive integer";
        }
        num = std::atoi(argv[i]);
        if (num == 0)
            throw "value must not be a zero";
        _vec.push_back(std::make_pair(num, 0));
        _dq.push_back(std::make_pair(num, 0));
    }
    if (_vec.size() > MAX_SIZE)
        throw "over max size";
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

PmergeMe *PmergeMe::get_instance(int argc, char **argv)
{
    if (!_instance)
        _instance = new PmergeMe(argc, argv);
    return _instance;
}

void PmergeMe::release_instance()
{
    if (_instance)
        delete _instance;
    _instance = NULL;
}

void PmergeMe::execute()
{
    std::cout << "Before: ";
    for (std::vector<pii>::iterator it = _instance->_vec.begin(); it != _instance->_vec.end(); ++it)
        std::cout << it->first << ' ';
    std::cout << std::endl;
    _sort_vec(_instance->_vec);
    std::cout << "After: ";
    for (std::vector<pii>::iterator it = _instance->_vec.begin(); it != _instance->_vec.end(); ++it)
        std::cout << it->first << ' ';
    std::cout << std::endl;
    // _sort_dq();
}

void PmergeMe::_insert_vec(std::vector<pii> &origin_vec, std::vector<pii> &child_vec)
{
    size_t sz = child_vec.size();
    std::vector<pii> chain_vec(sz);

    for (size_t i = 0; i < sz; i++) {
        const size_t idx = child_vec[i].second + 1;
        // chain_vec[i] = std::make_pair(origin_vec[idx].first, idx);
        chain_vec[i] = origin_vec[idx];
    }
    if (origin_vec.size() & 1)
        chain_vec.push_back(origin_vec.back());

    for (size_t i = 0; i < chain_vec.size(); i++)
        std::cout << chain_vec[i].first << ' ' << chain_vec[i].second << std::endl;
    std::cout << std::endl;

    origin_vec.clear();
    origin_vec.push_back(chain_vec[0]);
    for (size_t i = 0; i < sz; i++)
        origin_vec.push_back(child_vec[i]);

    for (int i = 1; true; i++) {
        size_t idx = std::min(Jacobsthal[i], chain_vec.size() - 1);
        if (Jacobsthal[i - 1] >= chain_vec.size() - 1)
            break;
        std::cout << "idx: " << idx << std::endl;
        while (idx > Jacobsthal[i - 1]) {
            std::vector<pii>::iterator it = std::upper_bound(origin_vec.begin(), origin_vec.end(), child_vec[idx]);
            origin_vec.insert(it, child_vec[idx]);
            --idx;
        }
    }
}

void PmergeMe::_sort_vec(std::vector<pii> &origin_vec)
{
    size_t sz = origin_vec.size();
    if (sz <= 1)
        return;
    for (size_t i = 0; i < sz; i++)
        origin_vec[i].second = i * 2;
    for (size_t i = 0; i < sz - 1; i += 2) {
        if (origin_vec[i] < origin_vec[i + 1])
            std::swap(origin_vec[i], origin_vec[i + 1]);
    }
    
    std::vector<pii> child_vec(sz >> 1);
    for (size_t i = 0; i < (sz >> 1); i++)
        child_vec[i] = origin_vec[i * 2];
    _sort_vec(child_vec);
    for (size_t i = 0; i < sz; i++)
        std::cout << origin_vec[i].first << ' ' << origin_vec[i].second << std::endl;
    std::cout << std::endl;
    for (size_t i = 0; i < (sz >> 1); i++)
        std::cout << child_vec[i].first << ' ' << child_vec[i].second << std::endl;
    std::cout << std::endl;
    _insert_vec(origin_vec, child_vec);
}
