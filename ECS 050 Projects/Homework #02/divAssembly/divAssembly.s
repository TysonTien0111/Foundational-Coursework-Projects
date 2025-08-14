.data
    dividend: .long 4 # dividend
    divisor: .long 4 # divisor

.text
    .globl _start
    _start:
        # ebx = dividend
        # esi = divisor
        # eax = quotient
        # edx = remainder
        # ecx = i

        movl dividend, %ebx # ebx = dividend 
        movl divisor, %esi # esi = divisor
        movl $0, %eax # eax = quotient = 0
        movl $0, %edx # edx = remainder = 0
        movl $0, %ecx # ecx = i = 0

        loopStart:
            cmpl $32, %ecx # i - 32 >= 0
            jge loopEnd # if i - 32 >= 0 is true, exit for loop
            
            shll $1, %eax # eax = quotient <<= 1
            shll $1, %edx # edx = remainder <<= 1
            shll $1, %ebx # ebx = dividend <<= 1
            
            adcl $0, %edx # sets the LSB of edx = remainder to whatever the MSB of ebx = dividend was

            cmpl %esi, %edx # remainder - divisor < 0
            jb noSubtraction # if remainder - divisor < 0 == true, don't subtract remainder by divisor

            orl $1, %eax # eax = quotient != (1 << 0)
            subl %esi, %edx # remainder -= divisor

            noSubtraction:
            
            incl %ecx # increment i by 1
            jmp loopStart # go back up to loopStart for next iteration
        loopEnd:
    done:
        nop

