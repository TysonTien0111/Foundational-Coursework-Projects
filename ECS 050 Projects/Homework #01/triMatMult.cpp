#include <fstream>
#include <iostream>
#include <vector>

int getIndex (int i, int j, int N)
{
    int totalElements = 0;

    for (int index = 0; index < i; ++index)
    {
        totalElements += (N - index);
    }

    return (totalElements + (j - i));
}

int main (int argc, char *argv[])
{
    std::ifstream inputMatrixOne (argv[1]);
    std::ifstream inputMatrixTwo (argv[2]);

    if (!inputMatrixOne)
    {
        return 1; 
    }

    if (!inputMatrixTwo)
    {
        return 1;
    }

    int N;
    inputMatrixOne >> N;
    inputMatrixTwo >> N;

    int totalElements = 0;
    for (int i = 1; i <= N; ++i)
    {
        totalElements += i;
    }

    std::vector<int> matrixA (totalElements);
    std::vector<int> matrixB (totalElements);
    std::vector<int> finalMatrix (totalElements);

    for (int i = 0; i < totalElements; ++i)
    {
        inputMatrixOne >> matrixA [i];
        inputMatrixTwo >> matrixB [i];
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (j < i)
            {
                continue;
            }

            int sum = 0;
            for (int k = i; k <= j; ++k)
            {
                sum += (matrixA[getIndex(i, k, N)] * matrixB[getIndex(k, j, N)]);
            }
            finalMatrix[getIndex(i, j, N)] = sum;
        }
    }

    for (int i = 0; i < totalElements - 1; ++i)
    {
        std::cout << finalMatrix[i] << ' ';
    }
    std::cout << finalMatrix[totalElements - 1] << '\n';

    return 0;
}
