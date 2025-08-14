##
## Your Name: Tyson-Tien Nguyen
## Last Four Digits of SID: 921031514
## EEC 170
## Lab 3
###

.data
quot:     .string "Quotient =  "
remain:   .string "Remainder = "
dividend: .string "Dividend =  "
divisor:  .string "Divisor =  "
newln:    .string "\n"
spc:      .string "       "
thank:    .string "Thank You\n"

#These are just sample values. Your program should work for all values  0 <= X <=40955 and 0 < Y <= 4095
X:  .word  189       #dividend   
Y:  .word  189        #divisor    


.text
.globl main                         # make main available to all project files

main:                               # There should be one main

  
    jal printInput

    lw a1, X                        # a3 = X
    lw a2, Y                        # a4 = Y

    # Divisor is a2 and Dividend in a1, ready to go

    jal myDiv

    jal printResults  
       
# Exit Politely with a Thank You Message

    la a1   thank
    li a0, 4
    ecall
    jal zero, exit                  # Exit program


myDiv:

#parameters to myDiv  -- a1 is the dividend and a2 is the divisor
#return the results in registers s2, and s3 to print correctly

#Your myDiv code goes here.  
#This code should be made as efficient as possible.
   
    # a1 = dividend
    # a2 = divisor
    # s2 = quotient
    # s3 = remainder
    # x2 = count
    # x3 = 12

    addi s2, x0, 0 # quotient = 0
    addi s3, x0, 0 # remainder = 0
    addi x2, x0, 0 # count = 0
    addi x3, x0, 12 # x3 = 12
    slli a1, a1, 20 # move 11th bit of dividend to 31st spot

    forLoopStart:
        bge x2, x3, forLoopEnd # count >= 12, go to forLoopEnd

        slli s2, s2, 1 # quotient <<= 1
        slli s3, s3, 1 # remainder <<= 1

        bge a1, x0, nextStep # dividend >= 0
        ori s3, s3, 1 # set LSB of remainder = 1

        nextStep:
            sub s3, s3, a2 # remainder -= divisor
            blt s3, x0, restoreStep # remainder < 0, go to restoreStep
            ori s2, s2, 1 # set LSB of quotient = 1
            beq x0, x0, finalStep # go to finalStep

        restoreStep:
            add s3, s3, a2 # add divisor back to remainder
            
        finalStep:
            slli a1, a1, 1 # dividend <<= 1
            addi x2, x2, 1 # increment count by 1
            beq x0, x0, forLoopStart # go back to forLoopStart
    forLoopEnd:

    jalr x0, x1, 0 # jump back to caller


#Make sure you return from the procedure


# Print Routines are provided. Don't Modify!!!

printInput:
        #print dividend=
            li a0, 4
            la a1, dividend
            ecall
            li a0, 1
            lw a1, X
            ecall
            li a0, 4
            la a1, spc
            ecall

        #print divisor=
            li a0, 4
            la a1, divisor
            ecall
            li a0, 1
            lw a1, Y
            ecall
            li a0, 4
            la a1, spc
            ecall
            jalr ra

printResults:
        #print Quotient=
            li a0, 4
            la a1, quot
            ecall
            li a0, 1
            mv a1, s2
            ecall
            li a0, 4
            la a1, spc
            ecall
        #print Remainder=
            li a0, 4
            la a1, remain
            ecall
            li a0, 1
            mv a1, s3
            ecall
            li a0, 4
            la a1, newln    
            ecall
            jalr ra

exit:
    addi a0, zero, 0xA 
    ecall
