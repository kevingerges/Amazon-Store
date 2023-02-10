#ifndef MOVIE_H
#define MOVIE_H
#include "product.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "util.h"

class movie: public Product {
public:
    movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating);
    ~movie();

    std::set<std::string> keywords() const;

    std::string displayString() const;

    void dump(std::ostream& os) const;

protected:
    std::string genre_;
    std::string rating_;

};
#endif
