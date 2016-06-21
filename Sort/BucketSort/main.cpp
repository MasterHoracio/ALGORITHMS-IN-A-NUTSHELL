#include <cstdio>
#include <vector>

using namespace std;

/*
    Algoritmo BucketSort

    Sort(A)
        create n buckets B
        for i = 0 to n - 1 do
            k = hash(A[i])
            add A[i] to the kth bucket B[k]
        extract(B,A)
    end

    extract(B,A)
        idx = 0;
        for i = 0 to n - 1 do
            insertionSort(B)
            for m = 1 to Size(B[i])do
                A[idx++] = mth element of B[i]
    end

*/

vector <int> Numeros[7];

void extract(int *A,int n){
    int idx = 0, pos, value;
    for(int i = 0; i < n; i++){
        if(Numeros[i].size() == 0)
            continue;
        if(Numeros[i].size() == 1)
            A[idx++] = Numeros[i].at(0);
        else{
            for(int j = 1; j < Numeros[i].size(); j++){
                pos = j - 1;
                value = Numeros[i].at(j);
                while(pos >= 0 && Numeros[i].at(pos) > value){
                    Numeros[i].at(pos + 1) = Numeros[i].at(pos);
                    pos--;
                }
                Numeros[i].at(pos + 1) = value;
            }
            for(int j = 0; j < Numeros[i].size(); j++)
                A[idx++] = Numeros[i].at(j);
        }
    }
}

int hash(int num){
    return num / 3;
}

void BucketSort(int *A, int n){
    int k;

    for(int i = 0; i < n; i++){
        k = hash(A[i]);
        Numeros[k].push_back(A[i]);
    }
    extract(A,n);
}

int main()
{
    int A[7] = {7,5,13,2,14,1,6};

    printf("Arreglo Original:\n\n");
    for(int i = 0; i < 7; i++)
        printf("%d ",A[i]);
    printf("\n\n");

    BucketSort(A,7);

    printf("Arreglo Ordenado:\n\n");
    for(int i = 0; i < 7; i++)
        printf("%d ",A[i]);
    printf("\n\n");

    return 0;
}
