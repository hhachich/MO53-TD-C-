#ifndef VALUES_LIST_H
#define VALUES_LIST_H

#include "list_element.h"
#include <vector>
#include <string>

class values_list {
    list_element *_head;
    list_element *_tail;

public:
    values_list(): _head(nullptr), _tail(nullptr) {}
    values_list(const values_list &other);
    ~values_list() {clear();}
    values_list &operator=(const values_list &other);

    void clear();
    void add_value(double v); // Always add at the end
    void pop_element(); // Remove last element
    size_t size()const;
    double get_value(size_t position)const;

    void sort_list(bool ascending);
};

#endif // VALUES_LIST_H
