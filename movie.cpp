#include <sstream>
#include <iomanip>
#include "product.h"
#include "movie.h"
#include "util.h"

using namespace std;


movie::movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating) :
Product(category, name, price , qty), genre_(genre), rating_(rating) {
}

movie::~movie(){}

std::set<std::string> movie::keywords() const {

    set<std::string> words(parseStringToWords(name_));
    words.insert(convToLower(genre_));
    return words;   
}

std::string movie::displayString() const {
    stringstream ss;
    ss << name_ << endl;
    ss << "Genre: " << genre_ << " Rating: " << rating_ << endl;
    ss << std::fixed << std::setprecision(2) << price_ << " " << qty_ << " left.\n";
    return ss.str();
}


void movie::dump(std::ostream& os) const{
     Product::dump(os);
     os << genre_ << "\n" << rating_ << endl;

}
