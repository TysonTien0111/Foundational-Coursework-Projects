#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
    int starting_base;
    std::cout << "Please enter the number's base: ";
    std::cin >> starting_base;

    std::string starting_number;
    std::cout << "Please enter the number: ";
    std::cin >> starting_number;

    std::string temp = starting_number;

    int new_base;
    std::cout << "Please enter the new base: ";
    std::cin >> new_base;

    if (starting_base == new_base)
    {
        std::cout << starting_number  << "base " << starting_base << "is " << starting_number << "base "
                  << new_base << '\n';

        return 0;
    }

    for (long unsigned int i = 0; i < starting_number.length(); ++i)
    {
        starting_number[i] = std::tolower(starting_number[i]);
    }

    std::map<char, long unsigned int> letter_to_number = {{'a', 10}, {'b', 11}, {'c', 12}, {'d', 13}, {'e', 14},
                                            {'f', 15}, {'g', 16}, {'h', 17}, {'i', 18}, {'j', 19},
                                            {'k', 20}, {'l', 21}, {'m', 22}, {'n', 23}, {'o', 24},
                                            {'p', 25}, {'q', 26}, {'r', 27}, {'s', 28}, {'t', 29},
                                            {'u', 30}, {'v', 31}, {'w', 32}, {'x', 33}, {'y', 34},
                                            {'z', 35}};

    std::vector<long unsigned int> original_number;

    for (long unsigned int i = 0; i < starting_number.length(); ++i)
    {
        if (letter_to_number.find(starting_number[i]) != letter_to_number.end())
        {
            original_number.insert(original_number.begin(), letter_to_number[starting_number[i]]);
        } else
        {
            int ascii_code_to_integer = starting_number[i] - 48;
            original_number.insert(original_number.begin(), ascii_code_to_integer);
        }
    }

    for (long unsigned int i = 0; i < original_number.size(); ++i)
    {
        original_number[i] *= pow(starting_base, i);
    }

    long unsigned int original_number_in_base_10 = 0;

    for (long unsigned int i = 0; i < original_number.size(); ++i)
    {
        original_number_in_base_10 += original_number[i];
    }

    std::vector<long unsigned int> new_number;

    while (original_number_in_base_10 > 0)
    {
        new_number.insert(new_number.begin(), original_number_in_base_10 % new_base);
        original_number_in_base_10 /= new_base;
    }

    std::cout << temp << " base " << starting_base << " is ";

    for (long unsigned int i = 0; i < new_number.size(); ++i)
    {
        if (new_number[i] > 9)
        {
            for (long unsigned int j = 0; j < 26; ++j)
            {
                char key = 'a' + j;

                if (letter_to_number.find(key)->second
                   == (new_number[i] % new_base))
                {
                    std::cout << static_cast<char>(std::toupper(letter_to_number.find(key)->first));
                    break;
                }
            }
        } else
        {
            std::cout << new_number[i]; 
        }
    }

    std::cout << " base " << new_base << '\n';

    return 0;
}