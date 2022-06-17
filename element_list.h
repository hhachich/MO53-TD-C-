#ifndef element_list_H
#define element_list_H

#include "element.h"

class element_list {
    element *_head;
    element *_tail;

public:
    element_list(): _head(nullptr), _tail(nullptr) {}
    element_list(const element_list &other);
    ~element_list() {clear_list();}
    element_list &operator=(const element_list &other);

    void clear();
    void push_back(double v); // Always add at the end
    void pop_element(); // Remove last element
    size_t size()const;
    double get_value(size_t position)const;

    void sort_list(bool ascending);
};

#endif // element_list_H
