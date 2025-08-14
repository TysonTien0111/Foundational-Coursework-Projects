#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    uint32_t dividend = strtoul(argv[1], NULL, 10);
    uint32_t divisor = strtoul(argv[2], NULL, 10);
    uint32_t remainder = 0;
    uint32_t quotient = 0;

    for (int i = 0; i < 32; ++i)
    {
        remainder <<= 1;
        quotient <<= 1;

        if (dividend & (1 << 31))
        {
            remainder |= (1 << 0);
        }

        if (remainder >= divisor)
        {
            quotient |= (1 << 0);
            remainder -= divisor;
        }

        dividend <<= 1;
    }

    printf("%s / %s = %u R %u\n", argv[1], argv[2], quotient, remainder);

    return 0;
}
