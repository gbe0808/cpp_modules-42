#include <cassert>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include "PmergeMe.hpp"

const size_t PmergeMe::Jacobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381};
PmergeMe *PmergeMe::_instance = NULL;

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv)
{
    long num;
    for (int i = 1; i < argc; i++) {
        if (!(std::isdigit(argv[i][0]) || argv[i][0] == '+'))
            throw "value must be a positive integer";
        size_t len = std::strlen(argv[i]);
        for (size_t j = 1; j < len; j++) {
            if (!std::isdigit(argv[i][j]))
                throw "value must be a positive integer";
        }
        num = std::atol(argv[i]);
        if (num > INT_MAX || len >= 12)
            throw "value is too large";
        if (num <= 0)
            throw "value must be a positive integer";
        _vec.push_back(std::make_pair(static_cast<int>(num), 0));
        _dq.push_back(std::make_pair(static_cast<int>(num), 0));
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
    
    std::vector<pii> sorted_vec(_instance->_vec);
    std::sort(sorted_vec.begin(), sorted_vec.end());
    std::cout << "After: ";
    for (std::vector<pii>::iterator it = sorted_vec.begin(); it != sorted_vec.end(); ++it)
        std::cout << it->first << ' ';
    std::cout << std::endl;

    clock_t vec_start = clock();
    _sort_vec(_instance->_vec);
    clock_t vec_end = clock();
    std::cout << "Time to process a range of " << _instance->_vec.size() << " piients with std::vector : " << vec_end - vec_start << " us\n";
    
    clock_t dq_start = clock();
    _sort_dq(_instance->_dq);
    clock_t dq_end = clock();
    std::cout << "Time to process a range of " << _instance->_vec.size() << " piients with std::deque : " << dq_end - dq_start << " us\n";

    // std::cout << "debugging print vec\n";
    // for (size_t i = 0; i < _instance->_vec.size(); i++) {
    //     std::cout << _instance->_vec[i] << ' ';
    // } std::cout << std::endl;
    // std::cout << "debugging print dq\n";
    // for (size_t i = 0; i < _instance->_dq.size(); i++) {
    //     std::cout << _instance->_dq[i] << ' ';
    // } std::cout << std::endl;

    bool wrong_flag = (sorted_vec.size() != _instance->_vec.size() || sorted_vec.size() != _instance->_dq.size());
    for (size_t i = 0; !wrong_flag && i < sorted_vec.size(); i++) {
        if ((sorted_vec[i].first == _instance->_vec[i].first) && (sorted_vec[i].first == _instance->_dq[i].first))
            continue;
        wrong_flag = true;
    }
    assert(wrong_flag == false);
}

void PmergeMe::_insert_vec(std::vector<pii> &origin_vec, std::vector<pii> &child_vec)
{
    size_t sz = child_vec.size();
    std::vector<pii> chain_vec(sz);

    for (size_t i = 0; i < sz; i++)
        chain_vec[i] = origin_vec[child_vec[i].second + 1];
    if (origin_vec.size() & 1)
        chain_vec.push_back(origin_vec.back());

    std::vector<pii> tmp(origin_vec);
    origin_vec.clear();
    origin_vec.push_back(chain_vec[0]);
    for (size_t i = 0; i < sz; i++)
        origin_vec.push_back(tmp[child_vec[i].second]);

    bool over_flag = false;
    size_t idx;
    for (int i = 1; !over_flag; i++) {
        if (Jacobsthal[i] < chain_vec.size())
            idx = Jacobsthal[i] - 1;
        else {
            idx = chain_vec.size() - 1;
            over_flag = true;
        }

        std::vector<pii>::iterator end_iter = origin_vec.begin() + \
            std::min(idx + Jacobsthal[i - 1], origin_vec.size());

        while (idx >= Jacobsthal[i - 1]) {
            std::vector<pii>::iterator it = \
                std::upper_bound(origin_vec.begin(), end_iter, chain_vec[idx]);
            origin_vec.insert(it, chain_vec[idx]);
            --idx;
        }
    }
}

void PmergeMe::_sort_vec(std::vector<pii> &origin_vec)
{
    size_t sz = origin_vec.size();
    if (sz <= 1)
        return;
    for (size_t i = 0; i < sz - 1; i += 2) {
        if (origin_vec[i] < origin_vec[i + 1])
            swap(origin_vec[i], origin_vec[i + 1]);
    }

    std::vector<pii> child_vec(sz >> 1);
    for (size_t i = 0; i < (sz >> 1); i++)
        child_vec[i] = std::make_pair(origin_vec[i << 1].first, static_cast<int>(i << 1));
    _sort_vec(child_vec);
    _insert_vec(origin_vec, child_vec);
}

void PmergeMe::_insert_dq(std::deque<pii> &origin_dq, std::deque<pii> &child_dq)
{
    size_t sz = child_dq.size();
    std::deque<pii> chain_dq(sz);

    for (size_t i = 0; i < sz; i++)
        chain_dq[i] = origin_dq[child_dq[i].second + 1];
    if (origin_dq.size() & 1)
        chain_dq.push_back(origin_dq.back());

    std::deque<pii> tmp(origin_dq);
    origin_dq.clear();
    origin_dq.push_back(chain_dq[0]);
    for (size_t i = 0; i < sz; i++)
        origin_dq.push_back(tmp[child_dq[i].second]);

    bool over_flag = false;
    size_t idx;

    for (int i = 1; !over_flag; i++) {
        if (Jacobsthal[i] < chain_dq.size())
            idx = Jacobsthal[i] - 1;
        else {
            idx = chain_dq.size() - 1;
            over_flag = true;
        }

        std::deque<pii>::iterator end_iter = origin_dq.begin() + \
            std::min(idx + Jacobsthal[i - 1], origin_dq.size());

        int end_iter_location = end_iter - origin_dq.begin();
        while (idx >= Jacobsthal[i - 1]) {
            std::deque<pii>::iterator it = \
                std::upper_bound(origin_dq.begin(), end_iter, chain_dq[idx]);
            origin_dq.insert(it, chain_dq[idx]);
            --idx;

            if (std::abs((end_iter - origin_dq.begin()) - end_iter_location) > 1)
                end_iter = origin_dq.begin() + end_iter_location;
            end_iter_location = end_iter - origin_dq.begin();
        }
    }
}

void PmergeMe::_sort_dq(std::deque<pii> &origin_dq)
{
    size_t sz = origin_dq.size();
    if (sz <= 1)
        return;
    for (size_t i = 0; i < sz - 1; i += 2)
        if (origin_dq[i] < origin_dq[i + 1])
            swap(origin_dq[i], origin_dq[i + 1]);

    std::deque<pii> child_dq(sz >> 1);
    for (size_t i = 0; i < (sz >> 1); i++)
        child_dq[i] = std::make_pair(origin_dq[i << 1].first, static_cast<int>(i << 1));
    _sort_dq(child_dq);
    _insert_dq(origin_dq, child_dq);
}
