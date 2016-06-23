#include <cstdio>
#include <list>
#include <algorithm>

using namespace std;

/*
    Algoritmo: Hash-Based Search

    loadTable(size,C)
        A = new array of given size
        for i = 0 to n - 1 do
            h = hash(c[i])
            if(A[h] is empty)then
                A[h] = new LinkedList
            add C[i] to A[h]
        return A
    end


    search(A,t)
        h = hash(t)
        list = A[h]
        if(list is empty)then
            return false
        if(list contains t)then
            return true
        return false
    end

*/

int hash(int x){
    return x % 3;
}

list<int> *loadTable(int size, int A[], int n){
    list<int> *ls = new list<int> [size];
    int h;
    for(int i = 0; i < n; i++){
        h = hash(A[i]);
        ls[h].push_back(A[i]);
    }
    return ls;
}

bool Search(list<int> ls[], int t){
    int h = hash(t);
    list<int> fi = ls[h];
    if(fi.empty())
        return false;
    if(find(fi.begin(),fi.end(), t) != fi.end())
        return true;
    return false;
}

int main()
{
    int A[7] = {1,4,8,9,11,15,17};
    list <int> *ls;
    bool aux;

    ls = loadTable(3,A,7);

    aux = Search(ls,9);

    if(aux)
        printf("Encontrado\n");
    else
        printf("No Encontrado\n");

    return 0;
}
