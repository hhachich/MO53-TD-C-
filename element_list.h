#ifndef element_list_H
#define element_list_H

#include "element.h"

template<typename T>
class element_list {
    element<T> *_head;
    element<T> *_tail;

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

    //return the first element of the list
    iterator begin() const{
        return iterator(_head);
    }
    //return the last element of the list
    iterator end() const {
        return iterator(_tail);
    }

    template<typename T>
    class iterator {
        private:
            element<T>*_current;
        public:
            iterator<T>(): _current(nullptr){}

            iterator<T>(element<T>* el): _current(el){}

            bool operator!=(const iterator& it) const {
                 return _current != it.current;
            }
            //prefix ++ overload
            iterator& operator++() {
                _current = _current -> _next;
                return *this;
            }
            
            //Postfix ++ overload
            iterator operator++(int)
            {
                iterator<T> iterator = *this;
                ++*this;
                return iterator;
            }
            double operator*() const {return _current -> _value}
    };

};
#endif // element_list_H


