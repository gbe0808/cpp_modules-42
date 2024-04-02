#pragma once

#include <iostream>
#include <utility>

class Elem {
private:

    int _val;
    size_t _par_idx;
    size_t _cur_idx;

public:
    Elem();
    Elem(int val);
    Elem(const Elem &ref);
    Elem &operator=(const Elem &ref);

    bool operator<(const Elem &ref) const;
    bool operator>(const Elem &ref) const;
    bool operator==(const Elem &ref) const;

    int get_val() const;
    size_t get_par_idx() const;
    size_t get_cur_idx() const;

    void set_val(int val);
    void set_par_idx(size_t par_idx);
    void set_cur_idx(size_t cur_idx);
    static void swap(Elem &elem1, Elem &elem2);

};

std::ostream& operator<<(std::ostream& os, const Elem& elem);
