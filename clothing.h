#ifndef CLOTHING_H
#define CLOTHING_H
#include "product.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "util.h"

class clothing : public Product{
public:
    clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand);
    
    ~clothing();

    /**
     * Returns the appropriate keywords that this product should be associated with
     */
    std::set<std::string> keywords() const;

    /**
     * Returns a string to display the product info for hits of the search
     */
    std::string displayString() const;

    /**
     * Outputs the product info in the database format
     */
     void dump(std::ostream& os) const;



protected:
    std::string size_;
    std::string brand_;


};
#endif
