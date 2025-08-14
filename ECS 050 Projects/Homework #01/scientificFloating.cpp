#include <cstdint>
#include <iostream>
#include <vector>

float get_user_input()
{
    std::cout << "Please enter a float: ";
    float user_input;
    std::cin >> user_input;

    return user_input;
}

uint32_t get_exponent(unsigned int float_to_int)
{
    uint32_t mask = ~0;
    mask <<= 23;
    mask &= ~(1 << 31);
    
    uint32_t floating_point_exponent = float_to_int & mask;
    floating_point_exponent >>= 23;
    floating_point_exponent = floating_point_exponent - ((1 << 7) - 1); // Final Exponent Result Variable

    return floating_point_exponent;
}

uint32_t get_mantissa(unsigned int float_to_int)
{
    uint32_t mask = ~0;
    mask >>= 9;

    uint32_t mantissa = float_to_int & mask;
   
    return mantissa;
}

void print_mantissa(uint32_t mantissa)
{
    bool flag = false;
    std::vector<int> mantissa_to_print;

    for (int i = 0; i <= 22; ++i)
    {
        if (flag == false)
        {
            if ((mantissa >> i) & 1)
            {
                flag = true;
                mantissa_to_print.insert(mantissa_to_print.begin(), (mantissa >> i) & 1);
            }
        } else
        {
            mantissa_to_print.insert(mantissa_to_print.begin(), (mantissa >> i) & 1);    
        }
    }

   for (long unsigned int i = 0; i < mantissa_to_print.size(); ++i)
   {
        std::cout << mantissa_to_print[i];
   }
}

void printResult(unsigned int float_to_int, uint32_t exponent, uint32_t mantissa)
{
    if (float_to_int & (1 << 31))
    {
        std::cout << "-";
    }
    
    std::cout << "1.";
    
    print_mantissa(mantissa);  

    std::cout << "E" << exponent << '\n';
}

int main(int argc, char *argv[])
{
    float user_input = get_user_input();
    unsigned int float_to_int = *((unsigned int*) &user_input);

    uint32_t exponent = get_exponent(float_to_int);
    uint32_t mantissa = get_mantissa(float_to_int);

    printResult(float_to_int, exponent, mantissa);

    return 0;
}
