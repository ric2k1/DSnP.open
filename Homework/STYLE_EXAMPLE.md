# LLVM Coding Style Example

This file demonstrates the before and after of applying LLVM coding standards.

## Before (Original Style)

```cpp
#include<iostream>
#include<vector>
#include "myheader.h"
using namespace std;

class json_element{
  public:
    json_element(){}
    json_element(const string& k,int v):key(k),value(v){}

    string get_key(){return key;}
    int get_value(){return value;}
    void set_value(int v){value=v;}

  private:
    string key;
    int value;
};

void process_json(vector<json_element>& elements){
    for(int i=0;i<elements.size();i++)
    {
        if(elements[i].get_value()>100){
            cout<<"Large value: "<<elements[i].get_key()<<endl;
        }
        else{
            cout<<"Small value: "<<elements[i].get_key()<<endl;
        }
    }
}

int main(){
    vector<json_element> data;
    data.push_back(json_element("test1",50));
    data.push_back(json_element("test2",150));

    process_json(data);
    return 0;
}
```

## After (LLVM Coding Standards Applied)

```cpp
#include "myheader.h"
#include <iostream>
#include <vector>

using namespace std;

class JsonElement
{
public:
    JsonElement() {}
    JsonElement(const string &k, int v) : _key(k), _value(v) {}

    string getKey() { return _key; }
    int getValue() { return _value; }
    void setValue(int v) { _value = v; }

private:
    string _key;
    int _value;
};

void processJson(vector<JsonElement> &elements)
{
    for (size_t i = 0; i < elements.size(); ++i) {
        if (elements[i].getValue() > 100) {
            cout << "Large value: " << elements[i].getKey() << endl;
        } else {
            cout << "Small value: " << elements[i].getKey() << endl;
        }
    }
}

int main()
{
    vector<JsonElement> data;
    data.push_back(JsonElement("test1", 50));
    data.push_back(JsonElement("test2", 150));

    processJson(data);
    return 0;
}
```

## Key Changes

1. **Include Order**: Local headers first, then system headers
2. **Class Names**: `json_element` → `JsonElement` (CamelCase)
3. **Function Names**: `get_key()` → `getKey()` (camelBack)
4. **Private Members**: `key` → `_key` (underscore prefix)
5. **Spacing**: Consistent spaces around operators and after commas
6. **Braces**:
   - Function opening braces on new line
   - Control statement braces on same line
7. **Indentation**: Consistent 4 spaces
8. **Loop Variables**: `int i` → `size_t i` for array indices
9. **Increment**: `i++` → `++i` (prefer pre-increment)
