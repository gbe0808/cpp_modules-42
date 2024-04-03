#include <cassert>
#include <ctime>
#include <cstring>
#include <iostream>
#include "PmergeMe.hpp"

const size_t PmergeMe::Jacobsthal[] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381};
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
        _vec.push_back(Elem(static_cast<int>(num)));
        _dq.push_back(Elem(static_cast<int>(num)));
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
    for (std::vector<Elem>::iterator it = _instance->_vec.begin(); it != _instance->_vec.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;
    
    std::vector<Elem> sorted_vec(_instance->_vec);
    std::sort(sorted_vec.begin(), sorted_vec.end());
    std::cout << "After: ";
    for (std::vector<Elem>::iterator it = sorted_vec.begin(); it != sorted_vec.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;

    clock_t vec_start = clock();
    _sort_vec(_instance->_vec);
    clock_t vec_end = clock();
    std::cout << "Time to process a range of " << _instance->_vec.size() << " elements with std::vector : " << vec_end - vec_start << " us\n";
    
    clock_t dq_start = clock();
    _sort_dq(_instance->_dq);
    clock_t dq_end = clock();
    std::cout << "Time to process a range of " << _instance->_vec.size() << " elements with std::deque : " << dq_end - dq_start << " us\n";

    for (size_t i = 0; i < sorted_vec.size(); i++) {
        if ((sorted_vec[i] == _instance->_vec[i]) && (sorted_vec[i] == _instance->_dq[i]))
            continue;
        assert(false);
    }
}

void PmergeMe::_insert_vec(std::vector<Elem> &origin_vec, std::vector<Elem> &child_vec)
{
    size_t sz = child_vec.size();
    std::vector<Elem> chain_vec(sz);

    for (size_t i = 0; i < sz; i++)
        chain_vec[i] = origin_vec[child_vec[i].get_par_idx() + 1];
    if (origin_vec.size() & 1)
        chain_vec.push_back(origin_vec.back());

    std::vector<Elem> tmp(origin_vec);
    origin_vec.clear();
    origin_vec.push_back(chain_vec[0]);
    for (size_t i = 0; i < sz; i++)
        origin_vec.push_back(tmp[child_vec[i].get_par_idx()]);

    bool over_flag = false;
    size_t idx;
    for (int i = 1; !over_flag; i++) {
        if (Jacobsthal[i] < chain_vec.size() - 1)
            idx = Jacobsthal[i];
        else {
            idx = chain_vec.size() - 1;
            over_flag = true;
        }
        while (idx > Jacobsthal[i - 1]) {
            std::vector<Elem>::iterator it = std::upper_bound(origin_vec.begin(), origin_vec.end(), chain_vec[idx]);
            origin_vec.insert(it, chain_vec[idx]);
            --idx;
        }
    }
}

void PmergeMe::_sort_vec(std::vector<Elem> &origin_vec)
{
    size_t sz = origin_vec.size();
    if (sz <= 1)
        return;
    for (size_t i = 0; i < sz - 1; i += 2) {
        if (origin_vec[i] < origin_vec[i + 1])
            Elem::swap(origin_vec[i], origin_vec[i + 1]);
        origin_vec[i].set_cur_idx(i);
        origin_vec[i + 1].set_cur_idx(i + 1);
    }
    if (sz & 1)
        origin_vec[sz - 1].set_cur_idx(sz - 1);

    std::vector<Elem> child_vec(sz >> 1);
    for (size_t i = 0; i < (sz >> 1); i++) {
        child_vec[i] = origin_vec[i << 1];
        child_vec[i].set_par_idx(i << 1);
    }
    _sort_vec(child_vec);
    _insert_vec(origin_vec, child_vec);
}

void PmergeMe::_insert_dq(std::deque<Elem> &origin_dq, std::deque<Elem> &child_dq)
{
    size_t sz = child_dq.size();
    std::deque<Elem> chain_dq(sz);

    for (size_t i = 0; i < sz; i++)
        chain_dq[i] = origin_dq[child_dq[i].get_par_idx() + 1];
    if (origin_dq.size() & 1)
        chain_dq.push_back(origin_dq.back());

    std::deque<Elem> tmp(origin_dq);
    origin_dq.clear();
    origin_dq.push_back(chain_dq[0]);
    for (size_t i = 0; i < sz; i++)
        origin_dq.push_back(tmp[child_dq[i].get_par_idx()]);

    bool over_flag = false;
    size_t idx;
    for (int i = 1; !over_flag; i++) {
        if (Jacobsthal[i] < chain_dq.size() - 1)
            idx = Jacobsthal[i];
        else {
            idx = chain_dq.size() - 1;
            over_flag = true;
        }
        while (idx > Jacobsthal[i - 1]) {
            std::deque<Elem>::iterator it = std::upper_bound(origin_dq.begin(), origin_dq.end(), chain_dq[idx]);
            origin_dq.insert(it, chain_dq[idx]);
            --idx;
        }
    }
}

void PmergeMe::_sort_dq(std::deque<Elem> &origin_dq)
{
    size_t sz = origin_dq.size();
    if (sz <= 1)
        return;
    for (size_t i = 0; i < sz - 1; i += 2) {
        if (origin_dq[i] < origin_dq[i + 1])
            Elem::swap(origin_dq[i], origin_dq[i + 1]);
        origin_dq[i].set_cur_idx(i);
        origin_dq[i + 1].set_cur_idx(i + 1);
    }
    if (sz & 1)
        origin_dq[sz - 1].set_cur_idx(sz - 1);

    std::deque<Elem> child_dq(sz >> 1);
    for (size_t i = 0; i < (sz >> 1); i++) {
        child_dq[i] = origin_dq[i << 1];
        child_dq[i].set_par_idx(i << 1);
    }
    _sort_dq(child_dq);
    _insert_dq(origin_dq, child_dq);
}
