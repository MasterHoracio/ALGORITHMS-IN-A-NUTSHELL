#include <cstdio>
#include <list>
#define INF 10000000

using namespace std;

/*
    Algoritmo: Bellman Ford

    BellmanFord(G,s)
        foreach v E V do
            dist[v] = INF
            pred[v] = -1
        dist[s] = 0

        for i = 1 to n do
            foreach edge (u,v) e E do
                newLen = dist[u] + weight of edge (u,v)
                if(newLen < dist[v])then
                    if(i = n)then report "Negative Cycle!"
                    dist[v] = newLen
                    pred[v] = u
    end

*/

class Grafo{
    private:
        list< pair<int,int> > *ls;
        int V, *dist, *pred;
    public:
        Grafo(int V){
            this->V = V;
            ls = new list<pair <int,int> >[V];
            dist = new int[V];
            pred = new int[V];
        }
        void addVertex(int v1, int v2, int peso){
            ls[v1].push_back(make_pair(v2,peso));
        }
        int BellmanFord(int origen, int destino){
            int newLen;
            for(int i = 0; i < V; i++){
                dist[i] = INF;
                pred[i] = -1;
            }
            dist[origen] = 0;
            for(int i = 1; i <= V; i++){
                for(int j = 0; j < V; j++){
                    list< pair<int,int> >::iterator it;
                    for(it = ls[j].begin(); it != ls[j].end(); it++){
                        newLen = dist[j] + it->second;
                        if(newLen < dist[it->first]){
                            if(i == V)
                                printf("Ciclo negativo\n");
                            dist[it->first] = newLen;
                            pred[it->first] = j;
                        }
                    }
                }
            }
            return dist[destino];
        }
};

int main()
{
    Grafo G(5);

    G.addVertex(0,4,2);
    G.addVertex(4,3,4);
    G.addVertex(4,1,5);
    G.addVertex(1,3,-2);
    G.addVertex(3,2,6);
    G.addVertex(2,1,-3);

    printf("%d\n",G.BellmanFord(0,3));

    return 0;
}
