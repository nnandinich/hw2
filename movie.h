#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include "util.h"
#include "product.h"
#include <set>

class Movie : public Product{
  public:
    //constructor
    Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating);
    //gives set of keywords
    std::set<std::string> keywords() const;
    //returns string of movie info
    std::string displayString() const;
    //output the database format of the product info
    void dump(std::ostream& os) const;
  private:
    std::string genre_;
    std::string rating_;
};
#endif