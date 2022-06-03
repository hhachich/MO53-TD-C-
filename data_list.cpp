#include "data_list.h"
#include <fstream>
#include <exception>
#include <array>
#include <iostream>
#include <algorithm>

using namespace std;

data_list::data_list() {
}

data_list::data_list(const data_list &other) {
    _values = other._values;
}



void data_list::from_text(const std::string &source) {
    _values.clear_list();
    ifstream f{source};
    if (f.is_open()) {
        array<char, 100> buffer;
        while (f.getline(&buffer[0], 100)) {
            _values.add_value(stold(string{buffer.data()}));
        }
    } else {
        throw ios_base::failure("File cannot be opened for reading.");
    }
}

void data_list::from_binary(const std::string &source) {
    _values.clear_list();
    ifstream f{source, std::ios::binary};
    if (f.is_open()) {
        double buffer;
        while (f.read(reinterpret_cast<char *>(&buffer), sizeof(double))) {
            _values.add_value(buffer);
        }
    } else  {
        throw ios_base::failure("File cannot be opened for reading.");
    }
}

void data_list::to_text(const std::string &destination) {
    ofstream f{destination};
    if (f.is_open()) {
        for (size_t i=0; i<_values.size(); ++i) {
            f << _values.get_value(i) << endl;
        }
    }
}

void data_list::to_binary(const std::string &destination) {
    ofstream f{destination, std::ios::binary};
    if (f.is_open()) {
        for (size_t i=0; i<_values.size(); ++i) {
            double val = _values.get_value(i);
            f.write(reinterpret_cast<const char *>(&val), sizeof(double));
        }
    } else  {
        throw ios_base::failure("File cannot be opened for writing.");
    }
}

void data_list::print_data() const {
    for (size_t i=0; i<_values.size(); ++i) {
        cout << _values.get_value(i) << endl;
    }
}

data_list data_list::moving_average(size_t window_width) {
    data_list result;
    if (window_width < _values.size()) {
        double current_sum = 0.0;
        for (size_t i=0; i<window_width; ++i) {
            current_sum += _values.get_value(i);
        }
        result._values.add_value(current_sum/window_width);
        for (size_t i=0; i+window_width<_values.size(); ++i) {
            current_sum -= _values.get_value(i);
            current_sum += _values.get_value(i+window_width);
            result._values.add_value(current_sum/window_width);
        }
    }
    return result;
}

data_list data_list::sort_table(bool ascending) {
    data_list result{*this};
    result._values.sort_list(ascending);
    return result;
}

data_list data_list::average() {
    data_list result;
    data_list sum_table = table_sum();
    result._values.add_value(sum_table._values.get_value(0) / _values.size());
    return result;
}

data_list data_list::table_sum() {
    data_list result;
    double current_sum = 0.0;
    for (size_t i=0; i<_values.size(); ++i) {
        current_sum += _values.get_value(i);
    }
    result._values.add_value(current_sum);
    return result;
}

data_list data_list::table_count() {
    data_list result;
    result._values.add_value(static_cast<double>(_values.size()));
    return result;
}
