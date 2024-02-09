#include "book.h"
#include <set>
#include <sstream>
#include <string>
#include "util.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, string isbn, string author)
    : Product(category, name, price, qty), isbn_(isbn), author_(author) {}

Book::~Book() {}

std::set<std::string> Book::keywords() const {
    set<string> _keywords;
    string word;

    istringstream iss(name_ + " " + author_);
    while (iss >> word) {
        set<string> words = parseStringToWords(word);
        _keywords.insert(words.begin(), words.end());
    }
    _keywords.insert(isbn_);

    return _keywords;
}

std::string Book::displayString() const {
    stringstream ss;
    ss << name_ << endl;
    ss << "Author: " << author_ << " ISBN: " << isbn_ << endl;
    ss << price_ << " " << qty_ << " left.";
    return ss.str();
}

void Book::dump(std::ostream& os) const {
    os << category_ << endl;
    os << name_ << endl;
    os << price_ << endl;
    os << qty_ << endl;
    os << isbn_ << endl;
    os << author_ << endl;
}

string Book::getIsbn() const {
    return isbn_;
}

string Book::getAuthor() const {
    return author_;
}
