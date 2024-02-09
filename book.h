#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "product.h"

using namespace std;

class Book: public Product {
private:
    string isbn_;
    string author_;

public:
    Book(const std::string category, const std::string name, double price, int qty,
            string isbn, string author);

    ~Book();

    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;

    string getIsbn() const;
    string getAuthor() const;
};

#endif