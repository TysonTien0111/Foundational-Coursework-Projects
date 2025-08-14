.text
    .globl matMult
    matMult:
        # Caller Registers
        # EAX
        # ECX
        # EDX = Row Of Pointers

        # Callee Registers
        # EBX
        # ESI
        # EDI

        matMultPrologueStart:
            pushl %ebp # Save The Caller's Stack Frame
            movl %esp, %ebp # Establish The Current Stack Frame

            # Callee Registers Used
            pushl %ebx # Push EBX Onto The Stack
            pushl %esi # Push ESI Onto The Stack
            pushl %edi # Push EDI Onto The Stack

            # Arguments
            .equ num_cols_b, 28 # num_cols_b Is 28 Bytes Above EBP
            .equ num_rows_b, 24 # num_rows_b Is 24 Bytes Above EBP
            .equ b, 20 # b Is 20 Bytes Above EBP
            .equ num_cols_a, 16 # num_cols_a Is 16 Bytes Above EBP
            .equ num_rows_a, 12 # num_rows_a Is 12 Bytes Above EBP
            .equ a, 8 # a Is 8 Bytes Above EBP

            # Local Variables
        matMultPrologueEnd:

        movl num_rows_a(%ebp), %ecx # ECX = num_rows_a
        shll $2, %ecx # ECX = num_rows_a * 4
        pushl %ecx # Push ECX Onto The Stack
        call malloc # Call Malloc Function
        movl %eax, %edx # EDX = Row Of Pointers

        movl $0, %ecx # ECX = i = 0
        movl num_rows_a(%ebp), %esi # ESI = num_rows_a
        forLoopOneStart:
            cmpl %esi, %ecx # i - num_rows_a
            jge forLoopOneEnd # Exit The For Loop If i - num_rows_a >= 0 Is True

            movl num_cols_b(%ebp), %ebx # EBX = num_cols_b
            shll $2, %ebx # EBX = num_cols_b * 4
            pushl %ecx # Push i Onto The Stack
            pushl %edx # Push Row Of Pointers Onto The Stack
            pushl %ebx # Push EBX Onto The Stack
            call malloc # Call Malloc Function
            addl $4, %esp # Clear EBX From The Stack
            popl %edx # Pop Row Of Pointers Onto The Stack
            popl %ecx # Pop i Back Into ECX
            movl %eax, (%edx, %ecx, 4) # Store num_cols_b In One Row Of num_rows_a

            incl %ecx # # Increment i By 1
            jmp forLoopOneStart # Go Back To The Start Of The For Loop
        forLoopOneEnd:

        movl $0, %ecx # ECX = i = 0
        movl num_rows_a(%ebp), %esi # ESI = num_rows_a
        forLoopTwoStart:
            cmpl %esi, %ecx # i - num_rows_a
            jge forLoopTwoEnd # If i - num_rows_a >= 0, Exit The For Loop

            movl $0, %ebx # EBX = j = 0
            movl num_cols_b(%ebp), %edi # EDI = num_cols_b
            forLoopThreeStart:
                cmpl %edi, %ebx # j - num_cols_b
                jge forLoopThreeEnd # If j - num_cols_b >= 0, Exit The For Loop
             
                pushl %ebx # Push j Onto The Stack
                pushl %edi # Push num_cols_b Onto The Stack
                pushl %esi # Push num_rows_a Onto The Stack
                movl $0, %eax # EAX = Accumulator = 0
                movl $0, %ebx # EBX = k = 0
                movl num_cols_a(%ebp), %edi # EDI = num_cols_a
                forLoopFourStart:
                    cmpl %edi, %ebx # k - num_cols_a
                    jge forLoopFourEnd # If k - num_cols_a >= 0, Exit The For Loop

                    pushl %edi # Push num_cols_a Onto The Stack
                    pushl %eax # Push Accumulator Onto The Stack

                    movl a(%ebp), %esi # ESI = A
                    movl (%esi, %ecx, 4), %eax # EAX = A[i]
                    movl (%eax, %ebx, 4), %esi # ESI = A[i][k]
                    movl b(%ebp), %edi # EDI = B
                    movl (%edi, %ebx, 4), %eax # EAX = B[k]
                    pushl %ebx # Push k Onto The Stack
                    movl 20(%esp), %ebx # Move j Back Into EBX Temporarily
                    movl (%eax, %ebx, 4), %edi # EDI = B[k][j]
                    popl %ebx # Pop k Back Into EBX

                    popl %eax # Pop Accumulator Back Into EAX
                    pushl %ebx # Pusk k Onto The Stack
                    movl %esi, %ebx # EBX = A[i][k]
                    imul %edi, %ebx # EBX = A[i][k] * B[k][j]
                    addl %ebx, %eax # EAX = A[i][k] * B[k][j]
                    popl %ebx # Pop k Back Into EBX
                    popl %edi # Pop num_cols_a Back Into EDI

                    incl %ebx # Increment k By 1
                    jmp forLoopFourStart # Jump Back To The Start Of The For Loop
                forLoopFourEnd:

                popl %esi # Pop num_rows_a Back Into ESI
                popl %edi # Pop num_cols_b Back Into EDI
                popl %ebx # Pop j Back Into EBX

                pushl %edi # Push num_cols_b Onto The Stack

                movl (%edx, %ecx, 4), %edi # EDI = C[i]
                movl %eax, (%edi, %ebx, 4) # C[i][j] = Accumulator

                popl %edi # Pop num_rows_a Back Into ESI

                incl %ebx # Increment j By 1
                jmp forLoopThreeStart # Jump Back To The Start Of The For Loop
            forLoopThreeEnd:
            
            incl %ecx # Increment i By 1
            jmp forLoopTwoStart # Jump Back To The Start Of The For Loop
        forLoopTwoEnd:

        movl %edx, %eax # EAX = C Matrix

        matMultEpilogueStart:
            popl %edi # Restore EDI's Old Value
            popl %esi # Restore ESI's Old Value
            popl %ebx # Restore EBX's Old Value
            movl %ebp, %esp # Clear All Local Variables
            pop %ebp # Restore Old Stack Frame
            ret # Return To Caller
        matMultEpilogueEnd:

