#include "movie.h"
#include <set>
#include <sstream>
#include <string>
#include "util.h"

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, string genre, string rating)
    : Product(category, name, price, qty), genre_(genre), rating_(rating) {}

Movie::~Movie() {}

std::set<std::string> Movie::keywords() const {
    set<string> _keywords;
    string word;

    istringstream iss(name_ + " " + genre_);
    while (iss >> word) {
        set<string> words = parseStringToWords(word);
        _keywords.insert(words.begin(), words.end());
    }

    return _keywords;
}

std::string Movie::displayString() const {
    stringstream ss;
    ss << name_ << endl;
    ss << "Genre: " << genre_ << " Rating: " << rating_ << endl;
    ss << price_ << " " << qty_ << " left.";
    return ss.str();
}

void Movie::dump(std::ostream& os) const {
    os << category_ << endl;
    os << name_ << endl;
    os << price_ << endl;
    os << qty_ << endl;
    os << genre_ << endl;
    os << rating_ << endl;
}

string Movie::getGenre() const {
    return genre_;
}

string Movie::getRating() const {
    return rating_;
}
