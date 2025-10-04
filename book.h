#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include "util.h"
#include "product.h"
#include <set>

class Book : public Product{
  public:
  //constructor
    Book(const std::string category, const std::string name, double price, int qty, const std::string isbn, const std::string author);
    //gives set of keywords
    std::set<std::string> keywords() const;
    //returns string of book info
    std::string displayString() const;
    //output the database format of the product info
    void dump(std::ostream& os) const;
  private:
    std::string isbn_;
    std::string author_;
};
#endif