#include "Elem.hpp"

Elem::Elem() {}

Elem::Elem(int val) : _val(val) {}

Elem::Elem(const Elem &ref) 
{
    if (this != &ref)
        *this = ref;
}

Elem &Elem::operator=(const Elem &ref)
{
    _val = ref._val;
    _par_idx = ref._par_idx;
    _cur_idx = ref._cur_idx;
    return *this;
}

bool Elem::operator<(const Elem &ref) const
{
    return _val < ref._val;
}

bool Elem::operator>(const Elem &ref) const
{
    return _val > ref._val;
}

bool Elem::operator==(const Elem &ref) const
{
    return _val == ref._val;
}

int Elem::get_val() const
{
    return _val;
}

size_t Elem::get_par_idx() const
{
    return _par_idx;
}

size_t Elem::get_cur_idx() const
{
    return _cur_idx;
}

void Elem::set_val(int val)
{
    _val = val;
}

void Elem::set_par_idx(size_t par_idx)
{
    _par_idx = par_idx;
}

void Elem::set_cur_idx(size_t cur_idx)
{
    _cur_idx = cur_idx;
}

void Elem::swap(Elem& elem1, Elem& elem2)
{
    Elem tmp = elem1;
    elem1 = elem2;
    elem2 = tmp;
}

std::ostream& operator<<(std::ostream& os, const Elem& elem)
{
    // os << "val: " << elem.get_val() << " par_idx: " << elem.get_par_idx() << " cur_idx: " << elem.get_cur_idx() << "\n";
    os << elem.get_val();
    return os;
}