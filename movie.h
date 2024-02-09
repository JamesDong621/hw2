#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include "product.h"

using namespace std;

class Movie: public Product {
private:
    string genre_;
    string rating_;

public:
    Movie(const std::string category, const std::string name, double price, int qty,
            string genre, string rating);

    ~Movie();

    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;

    string getGenre() const;
    string getRating() const;
};

#endif