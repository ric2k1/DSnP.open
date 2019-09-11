#include <iostream>
#include <unordered_map>
using namespace std;

int main(void)
{
  unordered_map<string, int>	fruits;

  fruits.insert({"apple", 3});
  fruits.insert({"kiwi", 5});
  
  cout<<"program tested successfully !!"<<endl;
  return 0;
}
