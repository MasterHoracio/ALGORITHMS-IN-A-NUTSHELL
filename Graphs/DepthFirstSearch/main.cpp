#include <cstdio>
#include <list>
#include <stack>

using namespace std;

/*
    Algoritmo: DepthFirstSearch

    DFS(G,s)
        foreach v e V do
            visit[v] = true
        stack t
        t.push(s)
        visit[s] = true
        while(!t.empty())do
            if(!visit[s])then
                visit[s] = true
                t.push(s)
            hasNextNode = false
            foreach u E V do
                if(!visit[u])then
                    hasNextNode = true;
                    break;
            if(hasNextNode)then
                s = *it
            else
                t.pop()
                if(!t.empty())
                    s = t.top()
    end

*/

int counter;

class Grafo{
    public:
        list<int> *ls;
        int nv;
        bool *visit;

        Grafo(int n){
            ls = new list<int>[n];
            nv = n;
            visit = new bool[n];
        }
        addEdge(int a, int b){
            ls[a].push_back(b);
            ls[b].push_back(a);
        }
        getNumberOfVertex(){
            return nv;
        }
};

void depthFirstSearch(Grafo G, int s){
    for(int i = 0; i < G.getNumberOfVertex(); i++)
        G.visit[i] = false;

    stack<int> t;
    printf("%d\n",s);
    t.push(s);
    G.visit[s] = true;

    while(!t.empty()){
        if(!G.visit[s]){
            printf("%d\n",s);
            G.visit[s] = true;
            t.push(s);
        }
        list<int>::iterator it;
        bool hasNextNode = false;
        for(it = G.ls[s].begin(); it != G.ls[s].end(); it++){
            if(!G.visit[*it]){
                hasNextNode = true;
                break;
            }
        }
        if(hasNextNode)
            s = *it;
        else{
            t.pop();
            if(!t.empty())
                s = t.top();
        }
    }
}

int main()
{
    Grafo G(8);

    //añadimos las aristas
    G.addEdge(4,6);
    G.addEdge(4,5);
    G.addEdge(6,2);
    G.addEdge(5,7);
    G.addEdge(2,0);
    G.addEdge(7,3);
    G.addEdge(7,1);

    depthFirstSearch(G,4);

    return 0;
}
