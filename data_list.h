#ifndef DATA_LIST_H
#define DATA_LIST_H


#include <vector>
#include <string>


class data_list {
    values_list _values;
public:
    data_list();
    data_list(const data_list &other);
    ~data_list() {_values.clear_list();}

    // Input methods
    void from_text(const std::string &source);
    void from_binary(const std::string &source);

    // Output methods
    void to_text(const std::string &destination);
    void to_binary(const std::string &destination);
    void print_data()const;

    // Computation (return new instances of data_table)
    data_list moving_average(size_t window_width);
    data_list sort_table(bool ascending=true);
    data_list average(); // returns a data_table with only one value
    data_list table_sum(); // returns a data_table with only one value
    data_list table_count(); // returns a data_table with only one value
};

#endif // DATA_LIST_H
