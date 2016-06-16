#include <cstdio>

using namespace std;

/*
    Algoritmo:

    Sort(A)
        for j = 1 to n -1 do
            i = j - 1
            value = A[j]
            while i >= 0 and A[i] > value do
                A[i + 1] = A[i]
                i--
            end
            A[i + 1] = value;
        end

*/

void Sort(int *Numeros, int tam){
    int i,value;
    for(int j = 1; j < tam; j++){
        i = j - 1;
        value = Numeros[j];
        while(i >= 0 && Numeros[i] > value){//(lim inf && izq > val)
            Numeros[i + 1] = Numeros[i];//recorre los numeros
            i--;//mueve el arreglo
        }
        Numeros[i + 1] = value;//acomoda el menor
    }
}

int main()
{
    int Numeros[16] = {15,9,8,1,4,11,7,12,13,6,5,3,16,2,10,14};

    printf("Impresion de los elementos originales: \n\n");
    for(int i = 0; i < 16; i++)
        printf("%d ",Numeros[i]);
    printf("\n\n");

    Sort(Numeros,16);

    printf("Impresion de los elementos ordenados: \n\n");
    for(int i = 0; i < 16; i++)
        printf("%d ",Numeros[i]);
    printf("\n\n");

    return 0;
}
