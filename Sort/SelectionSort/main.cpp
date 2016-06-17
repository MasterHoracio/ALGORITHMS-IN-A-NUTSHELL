#include <cstdio>

using namespace std;

int selectMax(int *Numeros, int inicio, int fin){
    int max = inicio;
    int i = inicio;
    while(++i <= fin){//encuentra el maximo
        if(Numeros[i] > Numeros[max])
            max = i;
    }
    return max;
}

void SelectionSort(int *Numeros, int tam){
    int max,tmp;
    for(int i = tam - 1; i >= 1; i--){
        max = selectMax(Numeros,0,i);//va truncando (calcula el maximo)
        if(max != i){//si no es la posicion actual
            tmp = Numeros[i];
            Numeros[i] = Numeros[max];
            Numeros[max] = tmp;
        }
    }
}

int main()
{
    int Numeros [16] = {15,9,8,1,4,11,7,12,13,16,5,3,16,2,10,14};

    printf("Numeros originales:\n\n");
    for(int i = 0; i < 16; i++)
        printf("%d ",Numeros[i]);
    printf("\n\n");

    SelectionSort(Numeros,16);

    printf("Numeros ordenados:\n\n");
    for(int i = 0; i < 16; i++)
        printf("%d ",Numeros[i]);
    printf("\n\n");

    return 0;
}
