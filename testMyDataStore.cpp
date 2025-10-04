#include "mydatastore.h"
#include "book.h"
#include "movie.h"
#include "clothing.h"
#include "util.h"
#include <iostream>

using namespace std;
int main(){
  MyDataStore dataStore;
  User *u1= new User("Nandini", 50, 0);
  Product *book1 = new Book("book", "Twilight", 10, 4, "123456", "Author");
  Product *movie1 = new Movie("movie", "Dune", 20, 6, "Science", "R");
  Product *clothing1 = new Clothing("clothing", "shirt", 50, 2, "S", "Alo");
  dataStore.addProduct(book1);
  dataStore.addProduct(movie1);
  dataStore.addProduct(clothing1);

  vector<string> terms;
  terms.push_back("twilight");
  vector<Product*> results= dataStore.search(terms,0);

  cout << "Search results " << endl;
  for(int i=0; i<results.size(); i++){
    cout<<results[i]->displayString()<< endl;
  }
  dataStore.addToCart("Nandini", 0);
  dataStore.viewCart("nandini");
  cout << "buying cart" << endl;
  dataStore.buyCart("nandini");
  dataStore.viewCart("nandini");
  cout << "dump" << endl;
  dataStore.dump(cout);
}