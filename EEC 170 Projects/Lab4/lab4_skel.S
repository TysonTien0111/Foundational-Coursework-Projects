# Targeted Half Precision Format: IEEE 754 Half Precision

.data

## Tyson-Tien Nguyen, 921031514



X_string: .string "X = "
Y_string: .string "Y = "
result_string: .string "X x Y = "

newln:    .string "\n"

# X and Y are the inputs

X:  .word  0x211F
Y:  .word  0x251F


# .text means the rest of the stuff is a program or instructions to the computer
.text
.globl main                         # make main available to all project files

main:                               # There should be one main

# Don't Touch this (BEGIN)
# Code to print X_string
    la a1, X_string
    li a0, 4
    ecall 

# Code to print X. The syscall code 34 in register a0, results in printing the number in hexadecimal notation. 
    lw a1, X
    li a0, 34
    ecall 

# Code to print newln
    la a1, newln
    li a0, 4
    ecall 

# Code to print Y_string
la a1, Y_string
    li a0, 4
    ecall 

# Code to print Y. The syscall code 34 in register a0, results in printing the number in hexadecimal notation. 
    lw a1, Y
    li a0, 34
    ecall 
# Code to print newln
    la a1, newln
    li a0, 4
    ecall


###    Pass X in a1,  Pass Y in a2, call the function hfmult and store result in a3
    lw a1, X
    lw a2, Y
    jal x1, hfmult


# Code to print result_string
    la a1, result_string
    li a0, 4
    ecall 

# Code to print result. The syscall code 34 in register a0, results in printing the number in hexadecimal notation. 
    add a1, x0, a3
    li a0, 34
    ecall 
# Code to print newln
    la a1, newln
    li a0, 4
    ecall
    j exit

# Don't touch this (END)

### BEGIN YOUR CODE  (Make sure the result is in register a3, remember X and Y are in a1 and a2)
hfmult:
    # a1 = X
    # a2 = Y
    # a3 = result

    # x2 = sign of X
    # x3 = sign of Y
    # x4 = exponent of X
    # x5 = exponent of Y
    # x6 = mantissa of X
    # x7 = mantissa of Y
    # x8 = sign of the product of X and Y
    # x9 = exponent of X and Y combined
    # x31 = product of X and Y
    # x13 = If 21st bit is 1
    # x14 = 0x1F
    # x15 = LSB of Product of X and Y
    # x16 = MSB of Rounding
    # x17 = 8 bits of Rounding
    # x18 = roundingCheck
    # x19 = significand
    # x20 = 0x800
    # x21 = 0x7C00
    # x22 = 0xF
    # x23 = 0x200000
    # x24 = 0x8000
    # x25 = 0xC00
    # x26 =0xC000
    
    li x20, 0x800 # x20 = 0x800
    li x21, 0x7C00 # x21 = 0x7C00
    addi x22, x0, 0xF # x22 = 0xF
    li x23, 0x200000 # x23 = 0x200000
    li x24, 0x8000 # x24 = 0x8000
    li x25, 0xC00 # x25 = 0xC00
    
    and x4, a1, x21 # get the exponent of X
    and x5, a2, x21 # get the exponent of Y
    srli x4, x4, 10 # shift LSB to 0th index for X
    srli x5, x5, 10 # shift LSB to 0th index for Y

    add x9, x4, x5 # add the exponent of X and Y
    sub x9, x9, x22 # subtract the sum of the exponent of X and Y by the bias of 15

    andi x6, a1, 0x03FF # get the mantissa of X
    andi x7, a2, 0x03FF # get the mantissa of X

    ifStatementOne:
        beq x4, x0, elseStatementOne # if exponent == 0, go to else branch
        addi x6, x6, 0x400 # add 1 bit to the 10th index
    elseStatementOne:

    ifStatementTwo:
        beq x5, x0, elseStatementTwo # if exponent == 0, go to else branch
        addi x7, x7, 0x400 # add 1 bit to the 10th index
    elseStatementTwo:

    mul x31, x6, x7 # X * Y

    and x13, x31, x23 # Check if 21st bit is 1

    ifStatementThree:
        beq x13, x0, elseStatementThree # if 21st bit is == 0, go to else branch
        srli x31, x31, 1 # shift x31 to the right by 1
        addi x9, x9, 1 # add 1 to the exponent
    elseStatementThree:

    and x2, a1, x24 # get the sign of X
    and x3, a2, x24 # get the sign of Y

    xor x8, x2, x3 # get the sign of the product of X and Y

    addi x14, x0, 0x1F # x14 = 0x1F

    ifStatementFour:
        blt x9, x14, elseStatementFour # if x9 < 31, go to else branch
        add a3, a3, x0 # clear a3
        and a3, a3, x25 # set a3 [0:9] = 0
        or a3, a3, x21 # set a3 [10:14] = 1
        add a3, a3, x8 # set a3 [15] = x8
        jalr x0, ra, 0 # return to the caller
    elseStatementFour:

    ifStatementFive:
        bgt x9, x0, elseStatementFive # if x9 > 0, go to else branch
        add a3, a3, x0 # clear a3
        and a3, a3, x26 # set a3[0:14] = 0
        add a3, a3, x8 # set a3 [15] = x8
        jalr x0, ra, 0 # return to the Caller
    elseStatementFive:

    andi x15, x31, 0x00000400 # LSB of the Product of X and Y
    srli x15, x15, 10 # Shift LSB of the Product of X and Y to Index 0

    andi x16, x31, 0x00000200 # MSB for Rounding
    srli x16, x16, 9 # Shift MSB of Rounding to Index 0

    andi x17, x31, 0x1FF # 8 bits for Rounding

    ifStatementSix:
        beq x17, x0, elseStatementSix # if x17 == 0, go to else branch
        andi x17, x17, 0x000 # set all bits to 0
        ori x17, x17, 0b1 # set LSB to 1
    elseStatementSix:

    ifStatementSeven:
        or x18, x17, x15 # x17 || x15 and store it in x18
        and x18, x16, x18, # x16 && x18 and store it in x18
    elseStatementSeven:

    srli x19, x31, 10 # shift significand 10 bits to the right
    add x19, x19, x18 # add x18 to x19

    ifStatementEight:
        blt x19, x20, elseStatementEight # if x19 < x20, go to elseStatementEight branch
        srli x19, x19, 1 # shift x19 to the right by 1
        addi x9, x9, 1 # add 1 to the exponent
    elseStatementEight:

    andi a3, x19, 0x3FF # put the mantissa into a3
    
    slli x9, x9, 10 # shift exponent bits left 10 times
    or a3, a3, x9 # set a3 [10:14] with x9

    add a3, a3, x8 # set the exponent sign in a3

    jalr x0, ra, 0 # return to caller
####  END YOUR CODE

# Don't modify anything below this.  It is just to exit the program gracefully.

   la a1, newln
    li a0, 4
    ecall

exit:
    addi a0, zero, 10 
    ecall
