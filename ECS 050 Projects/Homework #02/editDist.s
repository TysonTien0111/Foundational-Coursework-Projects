.data
    string1: .space 101 
    string2: .space 101
    oldDist: .space 404
    curDist: .space 404
        
.text
.globl _start
    swap:
        # Caller Registers
        # EAX = a
        # ECX = *a/*b
        # EDX = b

        # Callee Registers (None)

        prologueStartOne:
            pushl %ebp # Save the Caller's Base Stack Pointer
            movl %esp, %ebp # Move the Current Stack Pointer EBP
            subl $4, %esp # Subtract 4 Bytes from ESP to Make Space for 1 Local Variable

            # Callee Registers Used (None)

            # Arguments
            .equ b, 12 # b is 12 Bytes Above EBP
            .equ a, 8 # a is 8 Bytes Above EBP

            # Local Variables
            .equ temp, -4 # temp is 4 Bytes Below EBP
        prologueEndOne:

        movl a(%ebp), %eax # EAX = a
        movl (%eax), %ecx # ECX = *a
        movl %ecx, temp(%ebp) # temp = *a

        movl b(%ebp), %edx # EDX = b
        movl (%edx), %ecx # ECX = *b
        movl %ecx, (%eax) # *a = *b

        movl temp(%ebp), %ecx # ECX = temp
        movl %ecx, (%edx) # *b = temp
        
        epilogueStartOne:
            movl %ebp, %esp # Clear All Local Variables            
            popl %ebp # Return to Stack Frame of Caller
            ret # Return to Caller 
        epilogueEndOne:

    min:
        # Caller Registers
        # EAX = First Argument
        # ECX = Second Argument

        # Callee Registers (None)

        prologueStartTwo:
            push %ebp # Save the Caller's Base Stack Pointer
            movl %esp, %ebp # Move the Current Stack Pointer to EBP

            # Callee Registers Used (None)

            # Arguments
            .equ firstArgument, 8 # firstArgument is Above EBP by 8 Bytes
            .equ secondArgument, 12 # secondArgument is Above EBP by 12 Bytes

            # Local Variables (None)
        prologueEndTwo:

        movl firstArgument(%ebp), %eax # Move the firstArgument into EAX
        movl secondArgument(%ebp), %ecx # Move the secondArgument into ECX
        
        cmpl %ecx, %eax # a - b < 0
        jge else # If a - b >= 0, goto else

        jmp epilogueStartTwo # Jump to epilogueStartTwo since EAX = a is the Min
        else:
            movl %ecx, %eax # EAX = ECX = b

        epilogueStartTwo:
            movl %ebp, %esp # Clear Any Local Variables
            popl %ebp # Restore Caller's Base Pointer
            ret # Return to Caller
        epilogueEndTwo:

    strlen:
        # Caller Registers
        # EAX = Length Counter

        # Callee Registers
        # BL = Element/Character of String
        # ESI = Address of String

        prologueStartThree:
            pushl %ebp # Save the Caller's Base Stack Pointer
            movl %esp, %ebp # Move the Current Stack Pointer to EBP

            # Callee Registers Used
            pushl %ebx # Push Old EBX onto Stack
            pushl %esi # Push Old ESI onto Stack

            # Arguments
            .equ targetString, 8 # targetString is Above EBP by 8 Bytes

            # Local Variables (None)
        prologueEndThree:

        movl targetString(%ebp), %esi # Move the Address of the String into ESI
        movl $0, %eax # EAX = Length Counter = 0

        whileStart:
            movb (%esi, %eax, 1), %bl # Load Element/Character of String into BL
            cmpb $0, %bl # string[i] - '\0'
            je whileEnd # string[i] - '\0' == 0, Then Exit the While Loop

            incl %eax # Increment EAX aka Length Counter by 1
            jmp whileStart # Go Back to the Start of the While Loop
        whileEnd:

        
        epilogueStartThree:
            popl %esi # Pop Old ESI out of Stack
            popl %ebx # Pop Old EBX out of Stack
            movl %ebp, %esp # Deallocate Space that was Made for Any Local Variables
            popl %ebp # Restore Caller's Base Pointer
            ret # Return to Caller
        epilogueEndThree:

    editDist:
        # Caller Registers
        # EAX = word1_len
        # ECX = i
        # EDX = word2_len

        # Callee Registers
        # EBX = j
        # ESI = word1/word2
        # EDI = i - 1

        prologueStartFour:
            pushl %ebp # Save the Caller's Base Stack Pointer
            movl %esp, %ebp # Move the Current Stack Pointer to EBP
            subl $28, %esp # Allocate 28 Bytes for Our Local Variables, 5 Int Types In Total and 2 Pointers In Total

            # Callee Registers Used
            pushl %ebx # Push Old Value of EBX onto the Stack
            pushl %esi # Push Old Value of ESI onto the Stack
            pushl %edi # Push Old Value of EDI onto the Stack

            # Arguments
            .equ word2, 12 # word2 Above EBP 12 Bytes
            .equ word1, 8 # word1 Above EBP 8 Bytes

            # Local Variables
            .equ word1_len, -4 # word1_len Below EBP 4 Bytes
            .equ word2_len, -8 # word2_len Below EBP 8 Bytes
            .equ i, -12 # i Below EBP 12 Bytes
            .equ j, -16 # j Below EBP 16 Bytes
            .equ dist, -20 # dist Below EBP 20 Bytes
            .equ addressOfOldDist, -24 # addressOfOldDist Below EBP 24 Bytes
            .equ addressOfCurDist, -28 # addressOfCurDist Below EBP 28 Bytes
        prologueEndFour:
        
        pushl word1(%ebp) # Push the Address of word1 onto the Stack
        call strlen # Call strlen Function on word1
        movl %eax, word1_len(%ebp) # Move the Result from strlen into word1_len
        addl $4, %esp # CLear the Address of word1 off the Stack

        pushl word2(%ebp) # Push the Address of word2 onto the Stack
        call strlen # Call strlen Function on word2
        movl %eax, word2_len(%ebp) # Move the Result from strlen into word2_len
        addl $4, %esp # Clear the Address of word2 off the Stack

        movl $oldDist, addressOfOldDist(%ebp) # Store the Address of oldDist into addressOfOldDist
        movl $curDist, addressOfCurDist(%ebp) # Store the Address of curDist into addressOfCurDist

        movl i(%ebp), %ecx # ECX = i
        movl $0, %ecx # ECX = i = 0

        movl word2_len(%ebp), %edx # EDX = word2_len
        addl $1, %edx # EDX = word2_len + 1
        
        forLoopStartOne:
            cmpl %edx, %ecx # ECX - EDX == i - word2_len + 1
            jge forLoopEndOne # Exit For Loop if i - word2_len + 1 >= 0

            movl addressOfOldDist(%ebp), %esi # ESI = &oldDist
            movl %ecx, (%esi, %ecx, 4) # oldDist[i] = i
            movl addressOfCurDist(%ebp), %edi # EDI = &curDist
            movl %ecx, (%edi, %ecx, 4) # curDist[i] = i

            incl %ecx # Increment i by 1
            jmp forLoopStartOne # Go Back to Start of For Loop
        forLoopEndOne:
        
        movl $1, %ecx # ECX = i = 1 

        movl word1_len(%ebp), %eax # EAX = word1_len
        addl $1, %eax # EAX = word1_len + 1

        forLoopStartTwo:
            cmpl %eax, %ecx # i - word1_len + 1 >= 0
            jge forLoopEndTwo # If i - word1_len + 1 >= 0, Then Exit For Loop
            
            movl addressOfCurDist(%ebp), %esi # ESI = &curDist
            movl %ecx, 0(%esi) # curDist[0] = i

            movl j(%ebp), %ebx # EBX = j
            movl $1, %ebx # EBX = j = 1

            movl word2_len(%ebp), %edx # EDX = word2_len
            addl $1, %edx # EDX = word2_len + 1

            startInnerForLoop:
                cmpl %edx, %ebx # j - word2_len + 1 >= 0
                jge endInnerForLoop # If j - word2_len + 1 >= 0 is True, Exit Inner For Loop

                movl word1(%ebp), %esi # ESI = word1
                movl %ecx, %edi # EDI = ECX = i
                subl $1, %edi # EDI = i - 1
                movb (%esi, %edi, 1), %al # AL = word1[i - 1]

                movl word2(%ebp), %esi # ESI = word2
                movl %ebx, %edi # EDI = EBX = j
                subl $1, %edi # EDI = j - 1
                movb (%esi, %edi, 1), %ah # AH = word2[j - 1]

                cmpb %ah, %al # word1[i - 1] - word2[j - 1] == 0
                jne elseStatement # word1[i - 1] - word2[j - 1] != 0

                movl addressOfOldDist(%ebp), %esi # ESI = &oldDist
                movl (%esi, %edi, 4), %eax # EAX = oldDist[j - 1]

                movl addressOfCurDist(%ebp), %esi # ESI = &curDist
                movl %eax, (%esi, %ebx, 4) # curDist[j] = oldDist[j - 1]

                jmp nextInnerIteration # Jump to the Next Inner Loop Iteration

                elseStatement:
                    pushl %ecx # Save ECX = i onto the Stack

                    movl addressOfCurDist(%ebp), %esi # ESI = &curDist
                    pushl (%esi, %edi, 4) # Push curDist[j - 1] onto the Stack

                    movl addressOfOldDist(%ebp), %esi # ESI = &oldDist
                    pushl (%esi, %ebx, 4) # Push oldDist[j] onto the Stack

                    call min # Call the Min Function
                    addl $8, %esp # Clear the Arguments From the Stack

                    movl addressOfOldDist(%ebp), %esi # ESI = &oldDist
                    pushl (%esi, %edi, 4) # Push oldDist[j - 1] onto the Stack

                    pushl %eax # Push EAX = min(oldDist[j], curDist[j - 1]) onto the Stack

                    call min # Call the Min Function
                    addl $8, %esp # Clear the Arguments From the Stack

                    addl $1, %eax # EAX = min(min(oldDist[j], curDist[j - 1]), oldDist[j - 1]) + 1
                    movl addressOfCurDist(%ebp), %esi # ESI = &curDist
                    movl %eax, (%esi, %ebx, 4) # curDist[j] = min(min(oldDist[j], curDist[j - 1]), oldDist[j - 1]) + 1

                    popl %ecx # Pop i Back into ECX
                nextInnerIteration:
                    incl %ebx # Increment j by 1
                    jmp startInnerForLoop # Go Back Up to the Start of the Inner For Loop
            endInnerForLoop:
            pushl %eax # Save Old Value of EAX
            pushl %ecx # Save Old Value of ECX
            pushl %edx # Save Old Value of EDX

            leal addressOfCurDist(%ebp), %esi # ESI = &curDist
            pushl %esi # Push &oldDist onto the Stack

            leal addressOfOldDist(%ebp), %esi # ESI = &oldDist
            pushl %esi # Push &oldDist onto the Stack

            call swap # Call Swap Function
            
            addl $8, %esp # Remove the ESI's that were Pushed to the Stack

            popl %edx # Restore EDX's Old Value
            popl %ecx # Restore ECX's Old Value
            popl %eax # Restore EAX's Old Value

            movl word1_len(%ebp), %eax # EAX = word1_len
            addl $1, %eax # EAX = word1_len + 1
            incl %ecx # Increment i by 1
            jmp forLoopStartTwo # Go Back to Start of For Loop
        forLoopEndTwo:
        movl word2_len(%ebp), %esi # ESI = word2_len
        movl addressOfOldDist(%ebp), %edi # EDI = oldDist
        movl (%edi, %esi, 4), %eax # EAX = dist = oldDist[word2_len]

        epilogueStartFour:
            popl %edi # Restore EDI's Old Value
            popl %esi # Restore ESI's Old Value
            popl %ebx # Restore EBX's Old Value
            movl %ebp, %esp # Clear All Local Variables 
            popl %ebp # Return EBP to Caller
            ret # Return to Caller
        epilogueEndFour:

    _start:
        # Caller Registers
        # ECX = string1
        # EDX = string2

        # Callee Registers

        movl $string1, %ecx # ECX = string1
        movl $string2, %edx # EDX = string2

        pushl %edx # Push EDX onto the Stack
        pushl %ecx # Push ECX onto the Stack

        call editDist # Call editDist Function

    done:
        nop

