.data

k: .word  7
A: .word 15, 42, -22, 49, 83, 51, 59     # A [1x7] vector
B: .word 19 -73 62 30 -55 -21 31, -70 44 15 -56 73 -61 4, -93 -6 21 -80 65 -84 70, 66 -64 73 -28 49 -87 7, 8 58 15 30 62 -53 -91, 45 -66 61 46 -83 -87 -62, 18 31 66 6 96 36 77     # B[7x7] matrix stored in row major
C: .word 34, -52, 77, -51, -48, -88, -89    # C[1 x 7] initialized to some random values.

msg1:     .string "C = "
spc:      .string "  "
newln:    .string "\n"


# .text means the rest of the stuff is a program or instructions to the computer
.text
.globl main                         # make main available to all project files

main:                               # There should be one main

la x2, A 
la x3, B 
la x4, C 
lw x5, k      # x5 contains the dimension of your vector/matrix


# Step 1. call the function mvmult
jal x1, mvmult

#  Step 2. call the function printResult
jal x1, printResult



# Exit the program gracefully. Don't modify anything below this.  
   la a1, newln
    li a0, 4
    ecall

exit:
    addi a0, zero, 10 
    ecall


#YOUR CODE GOES HERE 
mvmult:
    #x1 = Return Address
    #x2 = A
    #x3 = B
    #x4 = C
    #x5 = K
    #x6 = element of A
    #x7 = element of B
    #x8 = i
    #x9 = j
    #x10 = C[j]
    #x11 = byte off set for C[j]
    #x12 = accumulator 
    #x13 = byte off set for A[i]
    #x14 = A[i]
    #x15 = [i * k + j]
    #x16 = [i * k + j] * 4 offset 
    #x17 = B[i * k + j]
    #x18 = product of A[i] * B[i * k + j]

    addi x9, x0, 0 #x9 = j = 0

    startLoopJ:
        bge x9, x5, endLoopJ #j >= K, exit loop

        slli x11, x9, 2 #j * 4, since each element is 4 bytes apart, for example C[0] would be (0) * 4
        add x10, x4, x11 #C[j], add the offset to C, thus we "index" C properly
        sw x0, 0(x10) #C[j] = 0
        addi x12, x0, 0 #accumulator = 0
        
        addi x8, x0, 0 #x8 = i = 0

        startLoopI:
            bge x8, x5, endLoopI #i >= K, exit loop

            slli x13, x8, 2 #byte off set for A[i]
            add x14, x2, x13 #A[i] add the offset to A
            lw x6, 0(x14) #get the element in A[i]

            mul x15, x8, x5 #i * k
            add x15, x15, x9 #i * k + j
            slli x16, x15, 2 #(i * k + j) * 4 for offset
            add x17, x3, x16 #B[i * k + j]
            lw x7, 0(x17) #get the element in B[i * k + j]

            mul x18, x6, x7 #A[i] * B[i * k + j]
            add x12, x12, x18 #C[i] += A[i] * B[i * k + j]

            addi x8, x8, 1 #increment i by 1
            beq x0, x0, startLoopI #go back to the start of the loop
        endLoopI:

        sw x12, 0(x10) #C[j] = the dot product of A[i] * B[i][j]

        addi x9, x9, 1 #increment j by 1
        beq x0, x0, startLoopJ #go back to the start of the loop
    endLoopJ:

    jalr x0, x1, 0 

#END of your CODE

# Don't Touch this (BEGIN)

printResult:
# Code to print "C = "
    la a1, msg1
    li a0, 4
    ecall 

     la x4, C 
     lw x5, k      # x5 contains the dimension of your vector/matrix
      li x6, 0     # forloop index variable
forloop: 
      slli x7, x6, 2         # x7 has the offset
      add  x8, x4, x7       # x8 points to C[i]
      lw a1, 0(x8)          # a1 has element C[i]
      li a0, 1
      ecall                 #print C[i]

      la a1, spc           # print space
      li a0, 4
      ecall 

      addi x6, x6, 1   
      beq  x6, x5, L
      j forloop
L:  jalr x0, 0(x1)

