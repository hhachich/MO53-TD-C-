#include "element_list.h"
#include <fstream>
#include <exception>
#include <array>
#include <iostream>
#include <algorithm>

using namespace std;
element_list::element_list(const element_list &other) {
    element *ptr = other._head;
    while (ptr) {
        add_value(ptr->get_value());
        ptr = ptr->get_next();
    }
}

element_list &element_list::operator=(const element_list &other) {
    clear_list();
    element *ptr = other._head;
    while (ptr) {
        add_value(ptr->get_value());
        ptr = ptr->get_next();
    }
    return *this;
}

void element_list::clear() {
    element *tmp = _head;
    while (tmp) {
        _head = tmp->get_next();
        delete tmp;
        tmp = _head;
    }
    _head = _tail = nullptr;
}

void element_list::add_value(double v) {
    if (!_head) {
        _head = new element(v);
        _tail = _head;
    } else {
        _tail->set_next(new element(v, _tail));
        _tail = _tail->get_next();
    }
}

void element_list::pop_element() {
    if (_head) {
        element *tmp = _head->get_next();
        delete _head;
        _head = tmp;
        if (tmp) {
            tmp->set_prev(nullptr);
        } else {
            _tail = _head; // both =nullptr
        }
    }
}

size_t element_list::size() const {
    size_t s = 0;
    element *ptr = _head;
    while (ptr) {
        ptr = ptr->get_next();
        ++s;
    }
    return s;
}

double element_list::get_value(size_t position) const {
    size_t pos = 0;
    element *ptr = _head;
    while (ptr) {
        if (pos == position)
            return ptr->get_value();
        ptr = ptr->get_next();
        ++pos;
    }
    // Error case: position out of bounds
}

void element_list::sort_list(bool ascending) { // Naive sort
    element *ptr = _head;
    while (ptr && ptr->get_next()) {
        element *min_element = ptr;
        element *cursor = ptr;
        while (cursor) {
            if (ascending && cursor->get_value() < min_element->get_value())
                min_element = cursor;
            else if (!ascending && cursor->get_value() > min_element->get_value())
                min_element = cursor;
            cursor = cursor->get_next();
        }
        double tmp = ptr->get_value();
        ptr->set_value(min_element->get_value());
        min_element->set_value(tmp);
        ptr = ptr->get_next();
    }
}