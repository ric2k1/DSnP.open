#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    // C++17: Use structured bindings for cleaner iteration
    std::unordered_map<std::string, int> fruits;

    fruits.insert({"apple", 3});
    fruits.insert({"kiwi", 5});

    // C++17: Demonstrate structured bindings
    for (const auto &[fruit, count] : fruits) {
        std::cout << "Fruit: " << fruit << ", Count: " << count << '\n';
    }

    std::cout << "program tested successfully !!\n";
    return 0;
}
