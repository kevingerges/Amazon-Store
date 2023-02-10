#include <sstream>
#include <iomanip>
#include "product.h"
#include "clothing.h"
#include "util.h"

using namespace std;


clothing::clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand):
Product(category, name, price , qty), size_(size), brand_(brand) {
}

clothing::~clothing(){}


std::set<std::string> clothing::keywords() const {

    set<std::string> nameWords(parseStringToWords(name_));
    set<std::string> brandWords(parseStringToWords(brand_));
    set<std::string> words(setUnion(nameWords, brandWords));

    return words;   
}


std::string clothing::displayString() const {
    stringstream ss;
    ss << name_ << endl;
    ss << "Size: " << size_ << " Brand: " << brand_ << endl;
    ss << std::fixed << std::setprecision(2) << price_ << " " << qty_ << " left.\n";
    return ss.str();
}


void clothing::dump(std::ostream& os) const{
        Product::dump(os);
        os << size_ << "\n" << brand_ << endl;
}
