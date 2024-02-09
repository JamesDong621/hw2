#include "clothing.h"
#include <set>
#include <sstream>
#include <string>
#include "util.h"

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, string size, string brand)
    : Product(category, name, price, qty), size_(size), brand_(brand) {}

Clothing::~Clothing() {}

std::set<std::string> Clothing::keywords() const {
    set<string> _keywords;
    string word;

    istringstream iss(name_ + " " + brand_);
    while (iss >> word) {
        set<string> words = parseStringToWords(word);
        _keywords.insert(words.begin(), words.end());
    }

    return _keywords;
}

std::string Clothing::displayString() const {
    stringstream ss;
    ss << name_ << endl;
    ss << "Size: " << size_ << " Brand: " << brand_ << endl;
    ss << price_ << " " << qty_ << " left.";
    return ss.str();
}

void Clothing::dump(std::ostream& os) const {
    os << category_ << endl;
    os << name_ << endl;
    os << price_ << endl;
    os << qty_ << endl;
    os << size_ << endl;
    os << brand_ << endl;
}

string Clothing::getSize() const {
    return size_;
}

string Clothing::getBrand() const {
    return brand_;
}
