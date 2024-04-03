#pragma once

#include <deque>
#include <string>
#include <utility>
#include <vector>
#include "Elem.hpp"

#define MAX_SIZE 10000

class Elem;

class PmergeMe {
private:
    static PmergeMe *_instance;

    std::vector<Elem> _vec;
    std::deque<Elem> _dq;

    PmergeMe();
    ~PmergeMe();
    PmergeMe(int argc, char **argv);
    PmergeMe(const PmergeMe &ref);
    PmergeMe &operator=(const PmergeMe &ref);

    static void _sort_vec(std::vector<Elem> &origin_vec);
    static void _insert_vec(std::vector<Elem> &origin_vec, std::vector<Elem> &child_vec);

    static void _sort_dq(std::deque<Elem> &origin_dq);
    static void _insert_dq(std::deque<Elem> &origin_dq, std::deque<Elem> &child_dq);

public:
    static const size_t Jacobsthal[];
    static PmergeMe *get_instance(int argc, char **argv);
    static void release_instance();
    
    static void execute();
};
