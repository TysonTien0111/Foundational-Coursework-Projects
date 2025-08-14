.data
    num1:
        .long 4 # Upper 32 Bits of Num One
        .long 4 # Lower 32 Bits of Num One

    num2:
        .long 4 # Upper 32 Bits of Num Two
        .long 4 # Lower 32 Bits of Num Two

.text
    .globl _start
    _start:
        # EBX = Upper Bits of Num One
        # ECX = Lower Bits of Num One

        # EDI = Upper Bits of Num Two
        # ESI = Lower Bits of Num Two

        # EDX = Sum of Upper Bits
        # EAX = Sum of Lower Bits

        movl num1, %ebx # EBX = Upper Bits of Num One
        movl (num1 + 4), %ecx # ECX = Lower Bits of Num One

        movl num2, %edi # EDI = Upper Bits of Num Two
        movl num2 + 4, %esi # ESI = Lower Bits of Num Two
        
        movl %ecx, %eax # EAX = ECX
        addl %esi, %eax # EAX = ECX + ESI

        movl %ebx, %edx # EDX = EBX
        adcl $0, %edx # EDX = EBX + Carry Flag, If Carry Flag is 0, then nothing changes, else we add 1 to the LSB of the Upper Bits of the Sum
        addl %edi, %edx # EDX = EBX + Carry Flag + EDI
        
    done:
        nop

