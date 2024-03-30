#pragma once

#include <deque>
#include <string>
#include <vector>

class PmergeMe {
private:
    static const int Jacobsthal[];
    static PmergeMe *_instance;

    std::vector<int> _vec;
    std::deque<int> _dq;

    PmergeMe();
    ~PmergeMe();
    PmergeMe(const char *arg);
    PmergeMe(const PmergeMe &ref);
    PmergeMe &operator=(const PmergeMe &ref);

    static void _sort_vec();
    static void _merge_vec();
    static void _insert_vec();
    static void _search_vec();

    static void _sort_dq();
    static void _merge_dq();
    static void _insert_dq();
    static void _search_dq();

public:
    static PmergeMe *get_instance(const char *arg);
    static void release_instance();
    
    static void execute();
};
