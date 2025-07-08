/****************************************************************************
  FileName     [ p2Json.h]
  PackageName  [ p2 ]
  Synopsis     [ Header file for class Json JsonElem ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2018-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#ifndef P2_JSON_H
#define P2_JSON_H

#include <iostream>
#include <optional>
#include <string>
#include <unordered_set>
#include <vector>

class JsonElem
{
  public:
    // TODO: define constructor & member functions on your own
    JsonElem() = default;
    JsonElem(std::string key, int value) : _key(std::move(key)), _value(value)
    {
    }

    // C++17: Add structured binding support
    auto getKey() const noexcept -> const std::string &
    {
        return _key;
    }
    auto getValue() const noexcept -> int
    {
        return _value;
    }

    // C++17: Add comparison operators
    bool operator==(const JsonElem &other) const
    {
        return _key == other._key && _value == other._value;
    }

    bool operator<(const JsonElem &other) const
    {
        return _key < other._key ||
               (_key == other._key && _value < other._value);
    }

    friend std::ostream &operator<<(std::ostream &, const JsonElem &);

  private:
    std::string _key;  // DO NOT change this definition. Use it to store key.
    int _value;        // DO NOT change this definition. Use it to store value.
};

class Json
{
  public:
    // TODO: define constructor & member functions on your own
    bool read(const std::string &);

    // C++17: Add structured binding support for iteration
    std::vector<JsonElem>::const_iterator begin() const noexcept
    {
        return _obj.begin();
    }
    std::vector<JsonElem>::const_iterator end() const noexcept
    {
        return _obj.end();
    }
    std::vector<JsonElem>::size_type size() const noexcept
    {
        return _obj.size();
    }
    bool empty() const noexcept
    {
        return _obj.empty();
    }

    // C++17: Add optional return for safer access
    std::optional<JsonElem> find(const std::string &key) const;

  private:
    std::vector<JsonElem> _obj;  // DO NOT change this definition.
                                 // Use it to store JSON elements.
};

#endif  // P2_TABLE_H
