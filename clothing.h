#ifndef CLOTHING_H
#define CLOTHING_H
#include <iostream>
#include <string>
#include "util.h"
#include "product.h"
#include <set>

class Clothing : public Product{
  public:
  //constructor
    Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand);
    //gives set of keywords
    std::set<std::string> keywords() const;
    //returns string of clothing info
    std::string displayString() const;
    //output the database format of the product info
    void dump(std::ostream& os) const;
  private:
    std::string size_;
    std::string brand_;
};
#endif