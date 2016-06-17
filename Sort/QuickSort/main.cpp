#include <cstdio>

using namespace std;

/*
    Algoritmo QuickSort:

    QuickSort(A,left,right)
        if(left < right)then
            pi = partition(A,left,right)
            QuickSort(A,left,p-1)
            QuickSort(A,p+1,right)
    end

    partition(A,left,right)
        p = select pivot in A(left,right)
        swap A[p] and A[right]
        store = left
        for i = left to right -1 do
            if(A[i] <= A[right]) then
                swap A[i] and A[store]
                store ++
        swap A[store] A[right]
        return store
    end
*/

int _partition(int *Numeros, int left, int right){
    int p = left;//pivote el de la izquierda

    //guardamos el pivote (lo pasamos al ultimo)
    int tmp = Numeros[p];
    Numeros[p] = Numeros[right];
    Numeros[right] = tmp;

    int store = left;//nos ayuda a guardar las posiciones
    for(int i = left; i < right; i++){//recorre el arreglo
        if(Numeros[i] <= Numeros[right]){//en caso de encontrar uno mas pequeño
            /*Se realiza el intercambio*/
            tmp = Numeros[store];
            Numeros[store] = Numeros[i];
            Numeros[i] = tmp;
            store ++;
        }
    }

    //regresamos el original a su posicion
    tmp = Numeros[store];
    Numeros[store] = Numeros[right];
    Numeros[right] = tmp;

    return store;
}

void QuickSort(int *Numeros, int left, int right){
    if(left < right){
        int p = _partition(Numeros,left,right);
        QuickSort(Numeros,left,p-1);
        QuickSort(Numeros,p+1,right);
    }else
        return;
}

int main()
{
    int Numeros [16] = {15,9,8,1,4,11,7,12,13,16,5,3,16,2,10,14};

    printf("Elementos originales:\n\n");
    for(int i = 0; i < 16; i++)
        printf("%d ",Numeros[i]);
    printf("\n\n");


    QuickSort(Numeros,0,15);

    printf("Elementos ordenados:\n\n");
    for(int i = 0; i < 16; i++)
        printf("%d ",Numeros[i]);
    printf("\n\n");


    return 0;
}
