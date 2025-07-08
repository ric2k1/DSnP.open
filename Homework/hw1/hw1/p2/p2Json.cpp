/****************************************************************************
  FileName     [ p2Json.cpp ]
  PackageName  [ p2 ]
  Synopsis     [ Define member functions of class Json and JsonElem ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2018-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#include "p2Json.h"

#include <algorithm>
#include <iostream>
#include <string>

// Implement member functions of class Row and Table here
bool Json::read(const std::string &jsonFile)
{
    return true;  // TODO
}

std::ostream &operator<<(std::ostream &ost, const JsonElem &elem)
{
    return (ost << "\"" << elem._key << "\" : " << elem._value);
}

// C++17: Implement optional-based find method
std::optional<JsonElem> Json::find(const std::string &key) const
{
    auto it =
        std::find_if(_obj.begin(), _obj.end(), [&key](const JsonElem &elem) {
            return elem.getKey() == key;
        });

    if (it != _obj.end()) {
        return *it;
    }
    return std::nullopt;
}
