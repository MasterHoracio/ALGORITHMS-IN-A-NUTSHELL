#include <cstdio>
#include <list>
#define INF 1000000

using namespace std;

/*
    Algoritmo Floyd Warshall

    FloydWarshall(G)
        foreach u E V do
            foreach v E V do
                dist[u][v] = INF
                pred[u][v] = -1
            dist[u][u] = 0
        foreach neighbor v of u do
            dist[u][v] = weight of edge (u,v)
            pred[u][v] = u

        foreach t E V do
            foreach u E V do
                foreach v E V do
                    newLen = dist[u][t] + dist[t][v]
                    if(newLen < dist[u][v])then
                        dist[u][v] = newLen
                        pred[u][v] = pred[t][v]
    end
*/

class Grafo{
    private:
        list< pair<int,int> > *ls;
        int **dist,**pred;
        int V;
    public:
        Grafo(int V){
            this->V = V;
            ls = new list< pair<int,int> >[V];
            dist = new int*[V];
            pred = new int*[V];
            for(int i = 0; i < V; i++){
                dist[i] = new int[V];
                pred[i] = new int[V];
            }
        }
        void addEdge(int v1, int v2, int peso){
            ls[v1].push_back(make_pair(v2,peso));
        }
        void FloydWarshall(){
            int newLen;
            for(int i = 0; i < V; i++){
                for(int j = 0; j < V; j++){
                    dist[i][j] = INF;
                    pred[i][j] = -1;
                }
                dist[i][i] = 0;
            }
            for(int i = 0; i < V; i++){
                list< pair<int,int> >::iterator it;
                for(it = ls[i].begin(); it != ls[i].end(); it++){
                    dist[i][it->first] = it->second;
                    pred[i][it->first] = i;
                }
            }
            for(int k = 0; k < V; k++){
                for(int i = 0; i < V; i++){
                    for(int j = 0; j < V; j++){
                        newLen = dist[i][k] + dist[k][j];
                        if(newLen < dist[i][j]){
                            dist[i][j] = newLen;
                            pred[i][j] = pred[k][j];
                        }
                    }
                }
            }
        }
        int getShortestPath(int origen, int destino){
            return dist[origen][destino];
        }
};

int main()
{
    Grafo G(5);

    G.addEdge(0,1,2);
    G.addEdge(0,4,4);
    G.addEdge(1,2,3);
    G.addEdge(2,4,1);
    G.addEdge(2,3,5);
    G.addEdge(3,0,8);
    G.addEdge(4,3,7);

    G.FloydWarshall();

    printf("%d\n",G.getShortestPath(3,2));

    return 0;
}
