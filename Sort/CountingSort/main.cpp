#include <cstdio>

using namespace std;

/*
    Algoritmo CountingSort

    Sort(A)
        create k buckets B
        for i = 0 to n - 1 do
            B[A[i]]++

        idx = 0;
        for i = 0 to k - 1 do
            while(B[i] > 0)do
                A[idx++] = i
                B[i]--
    end

*/

void CountingSort(int *A, int n, int k){
    int B[k] = {0}, idx;
    for(int i = 0; i < n; i++)
        B[A[i]]++;
    idx = 0;
    for(int i = 0; i < k; i++){
        while(B[i] > 0){
            A[idx++] = i;
            B[i]--;
        }
    }
}

int main()
{
    int A[7] = {3,0,2,0,0,2,2};

    printf("Arreglo Original:\n\n");
    for(int i = 0; i < 7; i++)
        printf("%d ",A[i]);
    printf("\n\n");

    CountingSort(A,7,4);

    printf("Arreglo Ordenado:\n\n");
    for(int i = 0; i < 7; i++)
        printf("%d ",A[i]);
    printf("\n\n");

    return 0;
}
