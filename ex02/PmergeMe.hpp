#pragma once

#include <deque>
#include <string>
#include <utility>
#include <vector>

#define MAX_SIZE 100000
typedef std::pair<int, int> pii;

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
    static void _merge_vec();
    static void _insert_vec(std::vector<pii> &origin_vec, std::vector<pii> &child_vec);
    static void _search_vec();

    static void _sort_dq();
    static void _merge_dq();
    static void _insert_dq();
    static void _search_dq();

public:
    static const size_t Jacobsthal[];
    static PmergeMe *get_instance(int argc, char **argv);
    static void release_instance();
    
    static void execute();
};
