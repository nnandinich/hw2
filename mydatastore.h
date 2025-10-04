#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <iostream>
#include <string>
#include "util.h"
#include "product.h"
#include "datastore.h"
#include "user.h"
#include <set>
#include <map>
#include <vector>

class MyDataStore: public DataStore{
public:
//all the virtual functions from datastore.h need to be included
   MyDataStore();
   ~MyDataStore();
   void addProduct(Product* p);
   void addUser(User* u);
   std::vector<Product*> search(std::vector<std::string>& terms, int type);
   void dump(std::ostream& ofile);
   //adds a new item to users cart
   void addToCart(std::string username, int hit_result_index);
    //lets user view their cart
   void viewCart(std::string username);
   //lets user buy everything in their cart
   void buyCart(std::string username);
private:
  std::vector<User*> users;
  std::vector<Product*> products;
  std::map<std::string, std::vector<Product*>> cart;  
  //need way to map between keywords and products that match the keywords
  std::map<std::string, std::set<Product*>> keyMatch;
  //need to retain last search results so that users can see them still
  std::vector<Product*> pastSearch;
};
#endif