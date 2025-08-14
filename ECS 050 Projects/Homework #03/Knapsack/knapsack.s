.text
    .globl knapsack
    max:
        # Caller Registers Used
        # EAX = result

        maxPrologueStart:
            pushl %ebp # Save Caller's Stack Frame
            movl %esp, %ebp # Establish Current Stack Frame

            # Callee Registers Used
            pushl %edi # Save EDI's Old Value
            pushl %esi # Save ESI's Old Value

            # Arguments Used
            .equ b, 12 # Above EBP By 12 Bytes
            .equ a, 8 # Above EBP By 8 Bytes

            # Local Variables Used
        maxProlugueEnd:

        movl b(%ebp), %edi # EDI = b 
        movl a(%ebp), %esi # ESI = a

        ifStatementTwo:
            cmpl %edi, %esi # a - b
            jbe elseStatementTwo # If a - b <= 0, Go To Else Statement
            
            movl %esi, %eax # EAX = a  
            jmp maxEpilogueStart # Jump To Epilogue
        elseStatementTwo:
            movl %edi, %eax # EAX = b

        maxEpilogueStart:
            popl %esi # Restore ESI's Old Value
            popl %edi # Restore EDI's Old Value
            movl %ebp, %esp # Clear Any Local Variables
            popl %ebp # Restore Caller's Stack Frame
            ret # Return To Caller
        maxEpilogueEnd:

    knapsack:
        # Caller Registers Used
        # EAX = best_value
        # ECX = i
        # EDX = Temp Register

        knapsackPrologueStart:
            pushl %ebp # Save Caller's Stack Frame
            movl %esp, %ebp # Establish Current Stack Frame
            subl $8, %esp # Make Space For Local Variables

            # Callee Registers Used
            pushl %ebx # Save Old EBX's Value Onto The Stack
            pushl %esi # Save Old ESI's Value Onto The Stack
            pushl %edi # Save Old EDI's Value Onto The Stack

            # Arguments Used
            .equ cur_value, 24 # Above EBP By 24 Bytes
            .equ capacity, 20 # Above EBP By 20 Bytes
            .equ num_items, 16 # Above EBP By 16 Bytes
            .equ values, 12 # Above EBP By 12 Bytes
            .equ weights, 8 # Above EBP By 8 Bytes

            # Local Variables Used
            .equ i, -4 # Below EBP By 4 Bytes
            .equ best_value, -8 # Below EBP By 8 Bytes
        knapsackPrologueEnd:
        
        movl cur_value(%ebp), %edx # EDX = cur_value
        movl %edx, best_value(%ebp) # best_value = cur_value

        movl $0, i(%ebp) # i = 0
        movl i(%ebp), %ecx # ECX = i
        movl num_items(%ebp), %ebx # EBX = num_items
        forLoopOneStart:
            cmpl %ebx, %ecx # i - num_items
            jae forLoopOneEnd # Exit For Loop If (i - num_items) >= 0

            ifStatementOne:
                movl capacity(%ebp), %esi # ESI = capacity
                movl weights(%ebp), %edx # EDX = weights
                movl (%edx, %ecx, 4), %edi # EDI = weights[i]
                cmpl %edi, %esi # capacity - weights[i]
                jl elseStatementOne # If capacity - weights[i] < 0, Go To Else Statement

                pushl %ecx # Save ECX's Old Value

                movl values(%ebp), %edx # EDX = values
                movl (%edx, %ecx, 4), %eax # EAX = values[i]
                movl cur_value(%ebp), %edx # EDX = cur_value
                addl %edx, %eax # EAX = cur_value + values[i]
                pushl %eax # Push The Argument cur_value + values[i] Onto The Stack

                movl weights(%ebp), %eax # EAX = weights
                movl (%eax, %ecx, 4), %edx # EDX = weights[i]
                movl capacity(%ebp), %eax # EAX = capacity
                subl %edx, %eax # EAX = capacity - weights[i]
                pushl %eax # Push The Arugment capacity - weights[i] Onto The Stack

                movl num_items(%ebp), %eax # EAX = num_items
                subl %ecx, %eax # EAX = num_items - i
                subl $1, %eax # EAX = num_items - i - 1
                pushl %eax # Push The Argument num_items - i - 1 Onto The Stack

                movl %ecx, %eax # EAX = i
                addl $1, %eax # EAX = i + 1
                movl values(%ebp), %edx # EDX = values
                leal (%edx, %eax, 4), %eax # Get The Address Of values + i + 1
                pushl %eax # Push The Argument values + i + 1 Onto The Stack
                
                movl %ecx, %eax # EAX = i
                addl $1, %eax # EAX = i + 1
                movl weights(%ebp), %edx # EDX = weights
                leal (%edx, %eax, 4), %eax # Get The Address Of weights + i + 1
                pushl %eax # Push The Argument weights + i + 1 Onto The Stack

                call knapsack # Call knapsack Function

                addl $20, %esp # Clear The Arguments Off The Stack

                popl %ecx # Restore ECX's Old Value

                pushl %eax # Push knapsack Result Onto The Stack
                movl best_value(%ebp), %edx # EDX = best_value
                pushl %edx # Push best_value Onto The Stack

                call max # Call max Function
                addl $8, %esp # Clear The Arguments Off The Stack

                movl %eax, best_value(%ebp) # best_value = max's Result
            elseStatementOne:

            incl %ecx # Increment i By 1
            jmp forLoopOneStart # Go Back To The Start Of The For Loop
        forLoopOneEnd:

        movl best_value(%ebp), %eax # EAX = best_value

        knapsackEpilogueStart:
            popl %edi # Restore EDI's Old Value
            popl %esi # Restore ESI's Old Value
            popl %ebx # Restore EBX's Old Value
            movl %ebp, %esp # Clear Local Variables
            popl %ebp # Restore Caller's Stack Frame
            ret # Return To Caller
        knapsackEpilogueEnd:
