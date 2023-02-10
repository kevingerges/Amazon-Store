#include <sstream>
#include <iomanip>
#include "product.h"
#include "book.h"
#include "util.h"

using namespace std;



book::book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author) :
Product(category, name, price , qty), isbn_(isbn), author_(author) {
}



book::~book(){}


std::set<std::string> book::keywords() const {

    set<std::string> nameWords(parseStringToWords(name_));
    set<std::string> authorWords(parseStringToWords(author_));
    set<std::string> words(setUnion(nameWords, authorWords));

    words.insert(isbn_);

    return words;    


}


std::string book::displayString() const {
    std::stringstream ss;
    ss << name_ + "\n";
    ss << "Author: " + author_ + " ISBN: " + isbn_ + "\n";
    ss << std::fixed << std::setprecision(2) << price_ << " " << qty_ << " left.\n";
    return ss.str();
}


void book::dump(std::ostream& os) const{
    Product::dump(os);
    os << isbn_ << "\n" << author_ << endl;

}
