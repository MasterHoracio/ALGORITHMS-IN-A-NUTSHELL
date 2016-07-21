#include <cstdio>
#include <set>
#include <stack>
#define maxDepth 3

using namespace std;

/*
    Algoritmo: Depth-First Search

    DFS(initial,goal)
        if(initial = goal)then
            return "solution"
        initial.depth = 0
        open = new stack
        closed = new set
        insert(open,copy(initial))
        while(open is not empty)do
            n = pop(open)
            insert(closed,n)
            foreach valid move m at n do
                next = state when playing m at n
                if(closed doesn´t contain next)
                    next.depth = n.depth + 1
                if(next = goal)then
                    return "solution"
                if(next.depth < maxDepth)then
                    insert(open,next)
        return "No Solution"
    end

*/

struct data{
    int a, b, depth;
};

class DFS{
    private:
        data initial, goal;
    public:
        DFS(int initialA, int initialB, int finalA, int finalB){
            initial.a = initialA;
            initial.b = initialB;
            goal.a = finalA;
            goal.b = finalB;
        }
        int search(){
            set< pair<int, int> >::iterator it;
            bool containNext;
            if(initial.a == goal.a && initial.b == goal.b)
                return 1;
            initial.depth = 0;
            stack<data> open;
            set< pair<int, int> > closed;
            open.push(initial);
            while(!open.empty()){
                data n = open.top();
                open.pop();
                closed.insert(make_pair(n.a,n.b));
                for(int i = 0; i < 2; i++){
                    containNext = false;
                    data next = n;
                    if(i == 0)
                        next.a++;
                    else
                        next.b++;
                    for(it = closed.begin(); it != closed.end(); it++){
                        pair<int, int> p;p = *it;
                        if(p.first == next.a && p.second == next.b)
                            containNext = true;
                    }
                    if(!containNext){
                        next.depth = n.depth + 1;
                        if(next.a == goal.a && next.b == goal.b)
                            return 1;
                        if(next.depth < maxDepth)
                            open.push(next);
                    }

                }
            }
            return 0;
        }

};

int main()
{
    DFS d = DFS(0,0,2,1);

    if(d.search())
        printf("Encontrado\n");
    else
        printf("No Encontrado\n");

    return 0;
}
