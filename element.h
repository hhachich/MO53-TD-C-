#ifndef element_H
#define element_H

class element {
    double _value;
    element *_prev;
    element *_next;

public:
    element(double v=0.0, element *p=nullptr, element *n=nullptr):
        _value(v), _prev(p), _next(n) {}
    ~element() {}

    element *get_next() {return _next;}
    void set_next(element *n) {_next = n;}
    element *get_prev() {return _prev;}
    void set_prev(element *n) {_prev = n;}
    double get_value()const {return _value;}
    void set_value(double v) {_value = v;}
};
#endif //element_H