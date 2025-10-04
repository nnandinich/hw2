#include "mydatastore.h"
#include "util.h"
#include <iostream>

//constructor
MyDataStore::MyDataStore() {};

//destructor, need to delete all the new products to avoid valgrind errors
MyDataStore::~MyDataStore() {
  for(int i=0; i<products.size(); i++){
    delete products[i];
  }
  for(int i=0; i<users.size(); i++){
    delete users[i];
  }
}
//add product and need to add more keywords to map of keywords
void MyDataStore::addProduct(Product* p){
  products.push_back(p);
  std::set<std::string> keys= p->keywords();
  for(std::set<std::string>::iterator it=keys.begin(); it!=keys.end(); ++it){
    keyMatch[*it].insert(p);
  }
}
//add users and make them a cart 
void MyDataStore::addUser(User* u){
  users.push_back(u);
  std:: string userNAME=convToLower(u->getName());
  cart[userNAME]= std::vector<Product*>();
}
 /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
  std::vector<Product*> results;
  std::set<Product*> uniqueResults;
  std::set<Product*> setTwo;
  if(type==0){
    uniqueResults=keyMatch[convToLower(terms[0])];
    for(int i=1; i<terms.size(); i++){
      setTwo=keyMatch[convToLower(terms[i])];
      uniqueResults= setIntersection(uniqueResults, setTwo);
    }
  }
  else{
    for(int i=0; i<terms.size(); i++){
      setTwo=keyMatch[convToLower(terms[i])];
      uniqueResults= setUnion(uniqueResults, setTwo);
    }
  }
  for(std::set<Product*>::iterator it=uniqueResults.begin(); it!=uniqueResults.end(); ++it){
    results.push_back(*it);
  }
  pastSearch=results;
  return results;
}
/**
     * Reproduce the database file from the current Products and User values
     */
void MyDataStore::dump(std::ostream& ofile){
  ofile << "<products>" << std::endl;
  for (int i=0; i<products.size(); i++){
    products[i]->dump(ofile);
  }
  ofile << "</products>" << std::endl;
  ofile << "<users>" << std::endl;
  for (int i=0; i<users.size(); i++){
    users[i]->dump(ofile);
  }
  ofile << "</users>" << std::endl;
}

//add result from search into cart
void MyDataStore::addToCart(std::string username, int hit_result_index){
  username=convToLower(username);
  if(cart.find(username)==cart.end()){
    std::cout<<"Invalid request" << std::endl;
    return;
  }
  if(hit_result_index<0 || hit_result_index>= pastSearch.size()){
    std::cout<<"Invalid request" << std::endl;
    return;
  }
  Product *p= pastSearch[hit_result_index];
  cart[username].push_back(p);
  
}

//print users cart items
void MyDataStore::viewCart(std::string username){
  username= convToLower(username);
  if(cart.find(username)==cart.end()){
    std::cout<<"Invalid username" << std::endl;
    return;
  }

  std::vector<Product*>& currentCart= cart[username];
  for(int i=0; i<currentCart.size(); i++){
    std:: cout<<"Item " << std::to_string((i+1)) << std::endl;
    std:: cout<<currentCart[i]->displayString() <<std::endl;
  }
}

//buys what is possible and cart and leaves the rest in cart
void MyDataStore::buyCart(std::string username){
  username= convToLower(username);
  if(cart.find(username)==cart.end()){
    std::cout<<"Invalid username" << std::endl;
    return;
  }
  User* currUser;
  for(int i=0; i<users.size(); i++){
    if(convToLower(users[i]->getName())==username){
      currUser=users[i];
      break;
    }
  }
  std::vector<Product*>& currentCart= cart[username];
  std::vector<Product*> cartAfterBuy;
  for(int i=0; i<currentCart.size(); i++){
    Product *p =currentCart[i];
    if((p->getQty())>0 && (currUser->getBalance()>= p->getPrice())){
      p->subtractQty(1);
      currUser->deductAmount(p->getPrice());
    }
    //if user not purchased 
    else{
      cartAfterBuy.push_back(p);
    }
  } 
  currentCart=cartAfterBuy;
}