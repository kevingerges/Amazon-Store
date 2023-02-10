#ifndef BOOK_H
#define BOOK_H
#include "product.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>


class book: public Product{
public:
    book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author);
    
    ~book();

    std::set<std::string> keywords() const;

    std::string displayString() const;

    void dump(std::ostream& os) const;


protected:
    std::string isbn_;
    std::string author_;


};
#endif
