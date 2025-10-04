#include "book.h"

//constructor
Book::Book(std::string category, std::string name, double price, int qty, std::string isbn, std::string author): Product(category, name, price, qty){
  isbn_=isbn;
  author_=author;
}
//get keywords from the name and author and add the to the books keywords
std::set<std::string> Book::keywords() const{
 std::set<std::string> nameKeys= parseStringToWords(name_);
 std::set<std::string> authorKeys= parseStringToWords(author_);
 std::set<std::string> keys = setUnion(nameKeys, authorKeys);
 keys.insert(isbn_);
 return keys;
}
//book info string
 std::string Book::displayString() const{
  std:: string retval;
  retval+=name_ + "\n";
  retval+= "Author: " +author_ + " ISBN: " + isbn_ +"\n";
  retval+=std::to_string(price_) + " " + std::to_string(qty_) + " left.";
  return retval;
 }

//output database format of book info
 void Book::dump(std::ostream& os) const{
  os << "book" << std::endl;
  os << name_ << std::endl;
  os << price_ << std::endl;
  os << qty_ << std::endl;
  os << isbn_ << std::endl;
  os << author_ << std::endl;

 }