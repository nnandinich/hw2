#include <iostream>
#include <set>
#include <string>
#include "util.h"

using namespace std;
int main(){
  string one= "Men's";
  string two= "J.";
  string three= "I'll";
  set<string> oneAns= parseStringToWords(one);
  set<string> twoAns= parseStringToWords(two);
  set<string> threeAns= parseStringToWords(three);
  for(set<string>::iterator it= oneAns.begin(); it!= oneAns.end(); ++it){
    cout << *it << endl;
  }
  for(set<string>::iterator it= twoAns.begin(); it!= twoAns.end(); ++it){
    cout << *it << endl;
  }
  for(set<string>::iterator it= threeAns.begin(); it!= threeAns.end(); ++it){
    cout << *it << endl;
  }
  return 0;
}