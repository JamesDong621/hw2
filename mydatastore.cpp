#include "mydatastore.h"
#include "util.h"

MyDataStore::~MyDataStore() {
    for (vector<Product*>::iterator it = products.begin(); it != products.end(); it++) {
        delete *it;
    }
    for (vector<User*>::iterator it = users.begin(); it != users.end(); it++) {
        delete *it;
    }
}

void MyDataStore::addProduct(Product* p) {
    products.push_back(p);

    set<string> keywords = p->keywords();
    for (set<string>::iterator it = keywords.begin(); it != keywords.end(); it++) {
        string keyword = convToLower(*it);
        if (key2products.find(keyword) == key2products.end()) {
            key2products.insert(make_pair(keyword, set<Product*>()));
        }
        key2products[keyword].insert(p);
    }
}

void MyDataStore::addUser(User* u) {
    users.push_back(u);
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
    int n = terms.size();
    if (n == 0) {
        return vector<Product*>();
    }

    string term = terms[0];
    set<Product*> result = findProducts(term);
    for (int i = 1; i < n; i++) {
        term = terms[i];
        set<Product*> cur_products = findProducts(term);
        if (type == 0) {
            result = setIntersection(result, cur_products);
        } else {
            result = setUnion(result, cur_products);
        }
    }

    return vector<Product*>(result.begin(), result.end());
}

void MyDataStore::dump(std::ostream& ofile) {
    ofile << "<products>" << endl;   
    for (vector<Product*>::iterator it = products.begin(); it != products.end(); it++) {
        (*it)->dump(ofile);
    }
    ofile << "</products>" << endl;

    ofile << "<users>" << endl;   
    for (vector<User*>::iterator it = users.begin(); it != users.end(); it++) {
        (*it)->dump(ofile);
    }
    ofile << "</users>" << endl;
}

void MyDataStore::addCart(string username, Product* product) {
    if (user2cart.find(username) == user2cart.end()) {
        user2cart.insert(make_pair(username, vector<Product*>()));
    } 
    user2cart[username].push_back(product);
}

vector<Product*> MyDataStore::viewCart(string username) {
    return user2cart.find(username) == user2cart.end() ? vector<Product*>() : user2cart[username];
}

void MyDataStore::buyCart(string username) {
    User* user = findUser(username);
    vector<Product*> cart = viewCart(username);
    vector<Product*> new_cart;

    for (vector<Product*>::iterator it = cart.begin(); it != cart.end(); it++) {
        Product* product = *it;
        if (user->getBalance() >= product->getPrice() && product->getQty() > 0) {
            user->deductAmount(product->getPrice());
            product->subtractQty(1);
        } else {
            new_cart.push_back(product);
        }
    }
    user2cart[username] = new_cart;
}

User* MyDataStore::findUser(string username) {
    for (vector<User*>::iterator it = users.begin(); it != users.end(); it++) {
        if ((*it)->getName() == username) {
            return *it;
        }
    }
    return nullptr;
}