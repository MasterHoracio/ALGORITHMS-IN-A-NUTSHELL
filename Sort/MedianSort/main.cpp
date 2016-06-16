#include <cstdio>

using namespace std;

/*
    MedianSort(A,left,right)
        if(left < rigth) then
            find median value A[me] is A[left,right]
            mid = |(right - left) / 2|
            swap A[me] and A[mid]
            for i = left to mid - 1 do
                if(A[i] >= a[MID]) THEN
                   find A[k] <= A[mid] where k > mid
                    swap A[i] and A[k]
            MedianSort(A,left,mid - 1)
            MedianSort(A,mid + 1, right)
    end
*/

int _partition(int *Numeros, int left, int rigth, int pivotIntex){
    int idx, store, tmp;
    int pivot = Numeros[pivotIntex];

    //move pivot to the end of the array
    tmp = Numeros[rigth];
    Numeros[rigth] = Numeros[pivotIntex];
    Numeros[pivotIntex] = tmp;

    store = left;
    /*All values <= pivot are moved to front of array and pivot inserted just after them*/
    for(idx = left; idx < rigth; idx++){
        if(Numeros[idx] <= pivot){
            tmp = Numeros[idx];
            Numeros[idx] = Numeros[store];
            Numeros[store] = tmp;
            store++;
        }
    }

    tmp = Numeros[rigth];
    Numeros[rigth] = Numeros[store];
    Numeros[store] = tmp;
    return store;
}

int selectKth(int *Numeros, int k, int left, int right){
    int idx = left;
    int pivotIndex = _partition(Numeros,left,right,idx);

    if(left + k - 1 == pivotIndex)
        return pivotIndex;

    if(left + k - 1 < pivotIndex)//esta a la izq
        return selectKth(Numeros,k,left,pivotIndex - 1);
    else//esta a la derecha
        return selectKth(Numeros,k - (pivotIndex - left + 1),pivotIndex + 1,right);
}

void MedianSort(int *Numeros, int left, int right){
    if(right <= left)
        return;
    int mid = (right - left + 1) / 2;
    int me = selectKth(Numeros,mid+1,left,right);

    MedianSort(Numeros,left,left + mid - 1);
    MedianSort(Numeros,left + mid + 1,right);

}

int main()
{
    int Numeros[16] = {15,9,8,1,4,11,7,12,13,6,5,3,16,2,10,14};

    printf("Numeros originales: \n\n");
    for(int i = 0; i < 16; i++)
        printf("%d ",Numeros[i]);
    printf("\n\n");

    MedianSort(Numeros,0,15);

    printf("Numeros ordenados: \n\n");
    for(int i = 0; i < 16; i++)
        printf("%d ",Numeros[i]);
    printf("\n\n");

    return 0;
}
