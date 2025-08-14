import numpy as np

def generate_random_vector_matrix(k):
    # Generate a 1xk vector A with elements ranging from -100 to 100
    A = np.random.randint(-100, 101, size=(1, k))

    # Generate a kxk matrix B with elements ranging from -100 to 100
    B = np.random.randint(-100, 101, size=(k, k))

    # Generate C
    C = np.random.randint(-100, 101, size=(1, k))

    # Perform matrix multiplication (AxB)
    product = A @ B  # Matrix multiplication

    # Print the headers
    print(f"k: .word  {k}")
    # Print vector A 
    A_str = ', '.join(map(str, A[0]))
    print(f"A: .word {A_str}     # A [1xk] vector")
    # Print matrix B
    B_str = ', '.join(' '.join(map(str, row)) for row in B)
    print(f"B: .word {B_str}     # B[{k}x{k}] matrix stored in row major")
    # Print vector C 
    C_str = ', '.join(map(str, C[0]))
    print(f"C: .word {C_str}    # C[1 x {k}] initialized to some random values.")


    
    C_str = ' '.join(map(str, product[0]))
    print(f"\nC = {C_str}")

if __name__ == "__main__":
    k = 7
    generate_random_vector_matrix(k)