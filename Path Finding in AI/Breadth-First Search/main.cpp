#include <cstdio>
#include <queue>
#include <set>
#define maxDepth 3

using namespace std;

/*
    Algoritmo: Breadth-First Search

    BFS(initial, goal)
        if(initial = goal) then
            return "solution"
        open = new queue
        closed = new set
        insert(open,copy(initial))
        while(open is not empty)do
            n = head(open)
            insert(closed,n)
            foreach valid move m at n do
                next = state when playing m at n
                if(closed doesn´t contains next)then
                    if(next = goal)then
                        return "solution"
                    insert(open,next)
        return "No Solution"
    end

*/

struct data{
    int a, b;
};

class BFS{
    private:
        data initial, goal;
    public:
        BFS(int initialA, int initialB, int goalA, int goalB){
            initial.a = initialA; initial.b = initialB;
            goal.a = goalA; goal.b = goalB;
        }
        int search(){
            bool containNext;
            if(initial.a == goal.a && initial.b == goal.b)
                return 1;
            queue<data> open;
            set< pair<int,int> > closed;
            open.push(initial);
            while(!open.empty()){
                data n = open.front();
                open.pop();
                closed.insert(make_pair(n.a,n.b));
                for(int i = 0; i < 2; i++){
                    containNext = false;
                    data next = n;
                    if(i == 0)
                        next.a++;
                    else
                        next.b++;
                    set< pair<int,int> >::iterator it;
                    for(it = closed.begin(); it != closed.end(); it++){
                        pair<int,int> p = *it;
                        if(p.first == next.a && p.second == next.b)
                            containNext = true;
                    }
                    if(!containNext){
                        if(next.a == goal.a && next.b == goal.b)
                            return 1;
                        open.push(next);
                    }
                }
            }
            return 0;
        }
};

int main()
{
    BFS bfs(0,0,2,1);

    if(bfs.search())
        printf("Encontrado\n");
    else
        printf("No Encontrado\n");

    return 0;
}
