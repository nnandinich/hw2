#include <iostream>
#include <set>
#include <string>
#include "util.h"

using namespace std;
template <typename T>
void print(set<T> &s){
  typename set<T>:: iterator it;
  for(it=s.begin(); it!=s.end(); ++it){
    cout << *it;
  }
}
int main(){
  set<int> s1= {1,2,3,4,5,6,7,11};
  set<int> s2= {3,4,5,6,7,8,9};
  set <int> inter= setIntersection(s1,s2);
  set <int> uni= setUnion(s1,s2);
  cout << "intersection: ";
  print(inter);
  cout<< endl << "union: ";
  print(uni);
  cout<<endl;
  return 0;
}