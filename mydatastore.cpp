#include "datastore.h"
#include "util.h"
#include <sstream>
#include <iomanip>
#include "product.h"
#include "mydatastore.h"


MyDataStore::MyDataStore(){

    // std::cout << "constructing" << std::endl;
    // allProduct.clear();
    // allUser.clear();
    // cart.clear();  
}


MyDataStore::~MyDataStore(){

    std::vector<Product*>::iterator it;
    for(it = allProduct.begin(); it != allProduct.end(); ++it){
        delete *it;
    }
    std::vector<User*>::iterator it2;
    for(it2 = allUser.begin(); it2 != allUser.end(); ++it2){
        delete *it2;
    }
    // std::map<User*, std::vector<Product*>>::iterator it3;
    // for(it3 = cart.begin(); it3 != cart.end(); ++it3){
    //     delete it3->first;
    //     std::vector<Product*>::iterator it4;
    //     for(it4 = it3->second.begin(); it4 != it3->second.end(); ++it4){
    //         delete *it4;
    //     }
    // }
   
}

void MyDataStore::addProduct(Product* p){
    
    allProduct.push_back(p);
    std::set<std::string> keywords = p->keywords();
    std::set<std::string>::iterator it;
    for(it = keywords.begin(); it != keywords.end(); ++it){
        keywordProducts_[convToLower(*it)].insert(p);
    }
   
}

void MyDataStore::addUser(User* u){
    allUser.push_back(u);
}

std::vector<Product*>MyDataStore::search(std::vector<std::string>& terms, int type){
    // for(auto s:keywordProducts_){
    //     std::cout<<s.first<< std::endl;
    // }

    std::set<Product*> temp;
    std::set<Product*> temp2;
    std::set<Product*>::iterator it;
    std::map<std::string, std::set<Product*>>::iterator it2;
    std::vector<std::string>::iterator it3;
    std::vector<Product*> result;

    if(type == 1){
        for(it3 = terms.begin(); it3 != terms.end(); ++it3){
            it2 = keywordProducts_.find(convToLower(*it3));
            if(it2 != keywordProducts_.end()){
                temp = it2->second;
                temp2 = setUnion(temp2, temp);
            }
            // else {
            //     setIntersection(temp, keywordProducts_[*it3]);
            // }
        }
        for(it = temp2.begin(); it != temp2.end(); ++it){
            result.push_back(*it);
        }
    }
    else if(type == 0){
        for(it3 = terms.begin(); it3 != terms.end(); ++it3){
            it2 = keywordProducts_.find(convToLower(*it3));
            if(it2 != keywordProducts_.end()){
                if(it3 == terms.begin())
                    temp2 = it2->second;
                temp = it2->second;
                temp2 = setIntersection(temp2, temp);
            }

        }
        for(it = temp2.begin(); it != temp2.end(); ++it){
            result.push_back(*it);
        }
    }
    return result;


}

void MyDataStore::dump(std::ostream& ofile){

    std::vector<Product*>::iterator it;
    ofile << "<products>" << std::endl;
    for(it = allProduct.begin(); it != allProduct.end(); ++it){
       (*it)->dump(ofile);
    }
    ofile << "</products>" << std::endl;
     ofile << "<users>" << std::endl;
    std::vector<User*>::iterator it2;
    for(it2 = allUser.begin(); it2 != allUser.end(); ++it2){
        (*it2)->dump(ofile); 
    }
     ofile << "</users>" << std::endl;

}

void MyDataStore::addCart(User* u, Product* p){
    if (p->getQty() == 0){
        std::cout << "Out of stock" << std::endl;
        return;
    }
    cart[u].push_back(p);

}
void MyDataStore::viewCart(User* u){
    if (cart[u].empty()){
        std::cout << "Cart is empty" << std::endl;
        return;
    }
    std::string username = convToLower(u->getName());
    if (username == convToLower(u->getName()))
    {
        int start = 1;
        std::vector<Product*> temp = cart[u];
        std::vector<Product*>::iterator it;
        for(it = temp.begin(); it != temp.end(); ++it){
            std::cout << "Item "  << start << std::endl;
            std::cout << (*it)->displayString() << std::endl;
            std::cout << std::endl;
            start++;
    }
    }
    else{
        std::cout << "Invalid username" << std::endl;
    }
}


void MyDataStore::buyCart(User* u){
    if(u->getBalance() < 0){
        std::cout << "You don't have enough money" << std::endl;
        return;
    }
    else{
        std::vector<Product*> temp2;
        std::vector<Product*> temp = cart[u];
        std::vector<Product*>::iterator it;
       for(it = temp.begin(); it != temp.end(); ++it){
        if((*it)->getPrice() > u->getBalance()){		
					temp2.push_back(*it);
        }
        else if((*it)->getQty() > 0){
            u->deductAmount((*it)->getPrice());
            (*it)->subtractQty(1);
        }
        else{
            std::cout<<"Out of stock" << std::endl;
        }
    }
    if(temp2.size() > 0){
        cart[u] = temp2;
      }
      else{
        cart.erase(u);
      }
    }
    // cart[u].clear();
    
}


User* MyDataStore::getUserByUsername(const std::string& username) {
    for(User* u: allUser){
        if(u->getName() == username){
            return u;
        }
    }
    return NULL;
}


