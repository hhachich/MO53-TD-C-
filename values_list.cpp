#include "values_list.h"
#include <fstream>
#include <exception>
#include <array>
#include <iostream>
#include <algorithm>

using namespace std;
values_list::values_list(const values_list &other) {
    list_element *ptr = other._head;
    while (ptr) {
        add_value(ptr->get_value());
        ptr = ptr->get_next();
    }
}

values_list &values_list::operator=(const values_list &other) {
    clear_list();
    list_element *ptr = other._head;
    while (ptr) {
        add_value(ptr->get_value());
        ptr = ptr->get_next();
    }
    return *this;
}

void values_list::clear_list() {
    list_element *tmp = _head;
    while (tmp) {
        _head = tmp->get_next();
        delete tmp;
        tmp = _head;
    }
    _head = _tail = nullptr;
}

void values_list::add_value(double v) {
    if (!_head) {
        _head = new list_element(v);
        _tail = _head;
    } else {
        _tail->set_next(new list_element(v, _tail));
        _tail = _tail->get_next();
    }
}

void values_list::pop_element() {
    if (_head) {
        list_element *tmp = _head->get_next();
        delete _head;
        _head = tmp;
        if (tmp) {
            tmp->set_prev(nullptr);
        } else {
            _tail = _head; // both =nullptr
        }
    }
}

size_t values_list::size() const {
    size_t s = 0;
    list_element *ptr = _head;
    while (ptr) {
        ptr = ptr->get_next();
        ++s;
    }
    return s;
}

double values_list::get_value(size_t position) const {
    size_t pos = 0;
    list_element *ptr = _head;
    while (ptr) {
        if (pos == position)
            return ptr->get_value();
        ptr = ptr->get_next();
        ++pos;
    }
    // Error case: position out of bounds
}

void values_list::sort_list(bool ascending) { // Naive sort
    list_element *ptr = _head;
    while (ptr && ptr->get_next()) {
        list_element *min_element = ptr;
        list_element *cursor = ptr;
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