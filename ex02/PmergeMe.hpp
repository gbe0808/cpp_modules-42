#pragma once

#include <deque>
#include <string>
#include <utility>
#include <vector>
// #include "Elem.hpp"

#define MAX_SIZE 10000

typedef std::pair<int, int> pii;

// class Elem;

class PmergeMe {
private:
    static PmergeMe *_instance;

    std::vector<pii> _vec;
    std::deque<pii> _dq;

    PmergeMe();
    ~PmergeMe();
    PmergeMe(int argc, char **argv);
    PmergeMe(const PmergeMe &ref);
    PmergeMe &operator=(const PmergeMe &ref);

    static void _sort_vec(std::vector<pii> &origin_vec);
    static void _insert_vec(std::vector<pii> &origin_vec, std::vector<pii> &child_vec);

    static void _sort_dq(std::deque<pii> &origin_dq);
    static void _insert_dq(std::deque<pii> &origin_dq, std::deque<pii> &child_dq);

public:
    static const size_t Jacobsthal[];
    static PmergeMe *get_instance(int argc, char **argv);
    static void release_instance();
    
    static void execute();
};
