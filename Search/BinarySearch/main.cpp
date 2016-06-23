#include <cstdio>

using namespace std;

/*
    Agoritmo: Binary Search

    search(A,t)
        low = 0
        high = n - 1
        while(low <= high)do
            ix = (low + high) / 2
            if(t == A[ix])then
                return true
            else if(t < A[ix])then
                high = ix - 1
            else
                low = ix + 1
        return false
    end

*/

bool BinarySearch(int *A, int n, int t){
    int low = 0;
    int high = n - 1;

    while(low <= high){
        int mid = (low + high) / 2;
        if(A[mid] == t)
            return true;
        else if(A[mid] > t)//esta a la izq
            high = mid - 1;
        else//esta a la der
            low = mid + 1;
    }
    return false;
}

int main()
{
    int A[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    bool cont = BinarySearch(A,16,14);

    if(cont)
        printf("Esta\n");
    else
        printf("No Esta\n");

    return 0;
}
