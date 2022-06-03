#ifndef LIST_ELEMENT_H
#define LIST_ELEMENT_H


#include <vector>
#include <string>

class list_element {
    double _value;
    list_element *_prev;
    list_element *_next;

public:
    list_element(double v=0.0, list_element *p=nullptr, list_element *n=nullptr):
        _value(v), _prev(p), _next(n) {}
    ~list_element() {}

    list_element *get_next() {return _next;}
    void set_next(list_element *n) {_next = n;}
    list_element *get_prev() {return _prev;}
    void set_prev(list_element *n) {_prev = n;}
    double get_value()const {return _value;}
    void set_value(double v) {_value = v;}
};
#endif //LIST_ELEMENT_H
