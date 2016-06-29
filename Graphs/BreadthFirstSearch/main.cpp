#include <cstdio>
#include <list>
#include <queue>

using namespace std;

/*
    Algoritmo: breadthFirstSearch

    BFS(G,s)
        foreach v E V do
            pred[v] = -1
            dist[v] = -1
            color[v] = white
        color[s] = gray
        dist[s] = 0
        Q = empty Queue
        enqueue(Q,s)

        while(Q is not empty)do
            u = head(Q)
            foreach neighbor v of u do
                if(color[v] is white)then
                    dist[v] = dist[u] + 1
                    pred[v] = u
                    color[v] = gray
                    enqueue(Q,v)
            dequeue(Q)
            color[u] = black
    end

*/

class Grafo{
    public:
        list<int> *ls;
        int *pred, *dist, nv;
        char *color;
        Grafo(int n){
            ls = new list<int>[n];
            pred = dist = new int [n];
            color = new char [n];
            nv = n;
        }
        void addEdge(int a, int b){
            ls[a].push_back(b);
            ls[b].push_back(a);
        }
        int getNumberVertex(){
            return nv;
        }
};

void breadthFirstSearch(Grafo G, int s){
    int u;
    for(int i = 0; i < G.getNumberVertex(); i++){
        G.pred[i] = -1;
        G.dist[i] = -1;
        G.color[i] = 'w';
    }
    G.color[s] = 'g';
    G.dist[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        u = q.front();
        printf("%d\n",u);
        list<int>::iterator it;
        for(it = G.ls[u].begin(); it != G.ls[u].end(); it++){
            if(G.color[*it] == 'w'){
                G.dist[*it] = G.dist[u] + 1;
                G.pred[*it] = u;
                G.color[*it] = 'g';
                q.push(*it);
            }
        }
        q.pop();
        G.color[u] = 'b';
    }

}

int main()
{
    Grafo G(8);

    G.addEdge(4,6);
    G.addEdge(4,5);
    G.addEdge(6,2);
    G.addEdge(2,0);
    G.addEdge(5,7);
    G.addEdge(7,3);
    G.addEdge(7,1);

    breadthFirstSearch(G,4);

    return 0;
}
