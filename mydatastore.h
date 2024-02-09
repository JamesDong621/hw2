#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "datastore.h"
#include "product.h"
#include "user.h"

#include <vector>
#include <map>

using namespace std;

class MyDataStore: public DataStore {
private:
    vector<Product*> products;
    vector<User*> users;
    map<string, set<Product*>> key2products;
    map<string, vector<Product*>> user2cart;

public:

    ~MyDataStore();

    void addProduct(Product* p);

    void addUser(User* u);

    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    void dump(std::ostream& ofile);

    void addCart(string username, Product* product);

    void buyCart(string username);

    vector<Product*> viewCart(string username);

    set<Product*> findProducts(string keyword) {
        return key2products.find(keyword) == key2products.end() ? set<Product*>() : key2products[keyword];
    }

    User* findUser(string username);
};

#endif
