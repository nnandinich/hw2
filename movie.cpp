#include "movie.h"
//constructor
Movie::Movie(std::string category, std::string name, double price, int qty, std::string genre, std::string rating): Product(category, name, price, qty){
  genre_=genre;
  rating_=rating;
}
//get keywords from the name and genre and add the to the movies keywords
std::set<std::string> Movie::keywords() const{
 std::set<std::string> nameKeys= parseStringToWords(name_);
 std::set<std::string> genreKeys= parseStringToWords(genre_);
 std::set<std::string> keys = setUnion(nameKeys, genreKeys);
 return keys;
}
//movie info string
 std::string Movie::displayString() const{
  std:: string retval;
  retval+=name_ +"\n";
  retval+= "Genre: " +genre_ + " Rating: " + rating_ +"\n";
  retval+=std::to_string(price_) + " " + std::to_string(qty_) + " left.";
  return retval;
 }
//output database format of movie info
 void Movie::dump(std::ostream& os) const{
  os << "movie" << std::endl;
  os << name_ << std::endl;
  os << price_ << std::endl;
  os << qty_ << std::endl;
  os << genre_ << std::endl;
  os << rating_ << std::endl;

 }