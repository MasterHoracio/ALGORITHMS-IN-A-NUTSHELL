#include <cstdio>
#include <list>
#include <queue>
#define INF 10000000

using namespace std;

/*
    Algoritmo: Dijkstra PQ

    Dijkstra(G,s)
        PQ = new Priority Queue
        foreach v E V do
            dist[v] = INF
            pred[v] = -1
        dist[s] = 0
        foreach v E V do
            insert(v,dist[v]) into PQ

        while(PQ in not empty)do
            u = getmin(PQ)
            foreach neighbor v of u do
                w = weight of edge(u,v)
                newLen = dist[u] + w
                if(newLen < dist[v])then
                    decraseKey(PQ,v,newLen)
                    dist[v] = newLen
                    pred[v] = u
    end

*/

class Grafo{
    private:
        int V;
        list< pair<int,int> > *ls;
    public:
        Grafo(int V){
            this->V = V;
            ls = new list< pair<int,int> >[V];
        }
        void addEdge(int v1, int v2, int costo){
            ls[v1].push_back(make_pair(v2,costo));
        }
        int Dijkstra(int origen, int destino){
            int dist[V];
            bool visitados[V];
            //pair<distancia,origen>
            priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int, int> > > pq;
            for(int i = 0; i < V; i++){
                dist[i] = INF;
                visitados[i] = false;
            }
            dist[origen] = 0;
            pq.push(make_pair(dist[origen],origen));
            while(!pq.empty()){
                pair<int,int> p = pq.top();
                int u = p.second;//obtiene el vertice
                pq.pop();
                if(!visitados[u]){
                    visitados[u] = true;
                    list< pair<int,int> >::iterator it;
                    for(it = ls[u].begin(); it != ls[u].end(); it++){
                        int v = it->first;
                        int costo_arista  = it->second;
                        if(dist[v] > dist[u] + costo_arista){
                            dist[v] = dist[u] + costo_arista;
                            pq.push(make_pair(dist[v],v));
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

    G.addEdge(0,1,4);
    G.addEdge(0,2,2);
    G.addEdge(0,3,5);
    G.addEdge(1,4,1);
    G.addEdge(2,1,1);
    G.addEdge(2,3,2);
    G.addEdge(2,4,1);
    G.addEdge(3,4,1);

    printf("%d\n",G.Dijkstra(0,4));

    return 0;
}
