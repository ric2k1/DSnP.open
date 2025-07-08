/****************************************************************************
  FileName     [ rnGen.h ]
  PackageName  [ util ]
  Synopsis     [ Random number generator ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2007-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/
#ifndef RN_GEN_H
#define RN_GEN_H

#include <sys/types.h>
#include <unistd.h>

#include <limits>
#include <random>

// C++17: Modern random number generator using std::mt19937
class RandomNumGen
{
  public:
    RandomNumGen() : _engine(std::random_device{}())
    {
        _engine.seed(getpid());
    }

    RandomNumGen(unsigned seed) : _engine(seed) {}

    // C++17: Use modern random number generation
    int operator()(const int range) const
    {
        std::uniform_int_distribution<int> dist(0, range - 1);
        return dist(_engine);
    }

    // C++17: Add method for generating random strings
    std::string generateString(size_t length) const
    {
        std::uniform_int_distribution<int> dist('a', 'z');
        std::string result;
        result.reserve(length);

        for (size_t i = 0; i < length; ++i) {
            result += static_cast<char>(dist(_engine));
        }
        return result;
    }

  private:
    mutable std::mt19937 _engine;
};

#endif  // RN_GEN_H
