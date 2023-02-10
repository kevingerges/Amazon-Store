#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "datastore.h"
#include "util.h"
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>


class MyDataStore : public DataStore {
    public:
        MyDataStore();

        ~MyDataStore();

        void addProduct(Product* p);

        void addUser(User* u);

        std::vector<Product*> search(std::vector<std::string>& terms, int type); // can't loop

        void dump(std::ostream& ofile);

        void addCart(User* u, Product* p);

        void viewCart(User* u);

        void buyCart(User* u);

        User* getUserByUsername(const std::string& username);

    protected:
        std::map<std::string, std::set<Product*>> keywordProducts_;
        std::map<User*,std::vector<Product*>> cart; 
        std::vector<Product*> allProduct;
        std::vector<User*> allUser;
        std::map<std::string, User*> userMap;
};


#endif


