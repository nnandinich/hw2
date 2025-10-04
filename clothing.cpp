#include "clothing.h"

//constructor
Clothing::Clothing(std::string category, std::string name, double price, int qty, std::string size, std::string brand): Product(category, name, price, qty){
  size_=size;
  brand_=brand;
}
//get keywords from the name and brand and add the to the clothing keywords
std::set<std::string> Clothing::keywords() const{
 std::set<std::string> nameKeys= parseStringToWords(name_);
 std::set<std::string> brandKeys= parseStringToWords(brand_);
 std::set<std::string> keys = setUnion(nameKeys, brandKeys);
 return keys;
}

//clothing info string
 std::string Clothing::displayString() const{
  std:: string retval;
  retval+=name_ + "\n";
  retval+= "Size: " +size_ + " Brand: " + brand_ +"\n";
  retval+=std::to_string(price_) + " " + std::to_string(qty_) + " left.";
  return retval;
 }

//output database format of clothing info
 void Clothing::dump(std::ostream& os) const{
  os << "clothing" << std::endl;
  os << name_ << std::endl;
  os << price_ << std::endl;
  os << qty_ << std::endl;
  os << size_ << std::endl;
  os << brand_ << std::endl;

 }