#include <cctype>
#include <iostream>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
    char alphabet_binary[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                                'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                'w', 'x', 'y', 'z'};

    char word[argc - 1];

    for (int i = 1; i < argc; ++i)
    {
        int letter_num_position = atoi(argv[i]) & ((1 << 26) - 1);
        int letter_index_value = 0;
        int quotient = letter_num_position;

        while (quotient > 0)
        {
            quotient /= 2;
            letter_index_value++;
        }

        char letter = alphabet_binary[letter_index_value - 1];

        if ((atoi(argv[i]) & (1 << 26)) != 0) 
        {
            letter = toupper(letter); 
        }

        word[i - 1] = letter;
    }

    std::cout << "You entered the word: ";
    
    for (int i = 0; i < argc - 1; ++i)
    {
        std::cout << word[i];
    }

    return 0;
}
