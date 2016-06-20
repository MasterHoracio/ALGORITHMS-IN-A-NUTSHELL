#include <cstdio>

using namespace std;

/*
    Algoritmo: Heap Sort

    Sort(A)
        buildHeap(A)
        for i = n - 1 downto 1 do
            swap A[0] with A[i]
            heapify(A,0,i)
    end

    buildHeap(A)
        for i = n/2 - 1 dowto 0 do
            heapify(A,i,n)
    end

    heapify(A,idx,max)
        left = 2*idx + 1
        right = 2*idx + 2

        if(left < max && A[left] > A[idx]) then
            largest = left;
        else
            largest = idx;

        id(right < max && A[right] > A[largest])then
            largest = right

        if(largest != idx)then
            swap A[idx] with A[largest]
            heapify(A,largest,max)
    end
*/

void heapify(int *A, int idx, int max){
    int left, right,largest,tmp;

    left = (idx * 2) + 1;
    right = (idx * 2) + 2;

    if(left < max && A[left] > A[idx])
        largest = left;
    else
        largest = idx;

    if(right < max && A[right] > A[largest])
        largest = right;

    if(largest != idx){
        tmp = A[idx];
        A[idx] = A[largest];
        A[largest] = tmp;
        heapify(A,largest,max);
    }
}

void BuildHeap(int *A, int n){
    for(int i = (n/2)-1; i >= 0; i--)
        heapify(A,i,n);
}

void HeapSort(int *A, int n){
    int tmp;
    BuildHeap(A, n);
    for(int i = n - 1; i >= 1; i--){
        tmp = A[0];
        A[0] = A[i];
        A[i] = tmp;
        heapify(A,0,i);
    }
}

int main()
{
    int A[16] = {1,2,3,4,5,6,7,16,9,10,11,12,13,14,15,8};

    printf("Arreglo original: \n\n");
    for(int i = 0; i < 16; i++)
        printf("%d ",A[i]);
    printf("\n\n");

    HeapSort(A,16);

    printf("Arreglo ordenado: \n\n");
    for(int i = 0; i < 16; i++)
        printf("%d ",A[i]);
    printf("\n\n");

    return 0;
}
