#include <cstdio>
#include <queue>
#include <set>
#define INF 1000000
#define maxDepth 3

using namespace std;

/*
    Algoritmo: A*Search

    search(initial,goal)
        initial.depth = 0
        open = new PriorityQueue
        closed = new Set
        insert(open,copy(initial))
        while(open is not empty)do
            n = minimum(open)
            insert(closed,n)
            if(n = goal)then
                return "Solution"
            foreach valid move m at n do
                next = state when playing m at n
                next.depth = n.depth + 1
                if(closed contains next)then
                    prior = state in closed matching next
                    if(next.score < prior.socre)then
                        remove(closed,prior)
                        insert(open,next)
                else
                    insert(open,next)
        return "No Solution"
    end

*/

struct data{
    int a, b, depth, score;
};

bool operator<(const data& a, const data& b) {
  return a.score > b.score;
}

class Algorithm{
    private:
        data initial, goal;
    public:
        Algorithm(int initialA, int initialB, int goalA, int goalB){
            initial.a = initialA; initial.b = initialB;
            goal.a = goalA; goal.b = goalB;
        }
        int search(){
            bool containNext;
            initial.depth = 0; initial.score = maxDepth;

            priority_queue<data>open;
            set< pair<int,int> >closed;
            open.push(initial);

            while(!open.empty()){

                data n = open.top();
                open.pop();
                closed.insert(make_pair(n.a,n.b));

                if(n.a == goal.a && n.b == goal.b)
                    return 1;

                for(int i = 0; i < 2; i++){

                    containNext = false;
                    data next = n;
                    next.depth = n.depth + 1;

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
                        if(next.a > goal.a || next.b > goal.b)
                            next.score = INF;
                        else
                            next.score = n.score - (next.a + next.b);
                        open.push(next);
                    }
                }
            }
            return 0;
        }
};

int main()
{
    Algorithm a_star_search(0,0,2,1);

    if(a_star_search.search())
        printf("Encontrado\n");
    else
        printf("No Encontrado\n");

    return 0;
}
