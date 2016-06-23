#include <cstdio>

using namespace std;

/*
    Algoritmo Sequential Search

    search(A,t)
        for i = 0 to n - 1 do
            if(A[i] == t)then
                return true
        return false
    end

    ----------------------------------

    search(C,t)
        iter = C.begin()
        while(iter != C.end())do
            e = next element from iter
            if(e == t)then
                return true
        return false
    end

*/

bool SequentialSearch(int *N, int t, int n){
    for(int i = 0; i < n; i++)
        if(N[i] == t)
            return true;
    return false;
}

int main()
{
    bool find;
    int N[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

    find = SequentialSearch(N,11,15);

    if(find)
        printf("Encontrado\n");
    else
        printf("No Encontrado\n");

    return 0;
}
