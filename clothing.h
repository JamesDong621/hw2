#ifndef CLOTHING_H
#define CLOTHING_H

#include <string>
#include "product.h"

using namespace std;

class Clothing: public Product {
private:
    string size_;
    string brand_;

public:
    Clothing(const std::string category, const std::string name, double price, int qty,
            string size, string brand);

    ~Clothing();

    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;

    string getSize() const;
    string getBrand() const;
};

#endif