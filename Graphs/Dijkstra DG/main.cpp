#include <cstdio>
#include <list>
#define INF 10000000

using namespace std;

/*
    Algoritmo: Dijkstra

    Dijkstra(G,s)
        foreach v E V do
            dist[v] = INF
            prev[v] = -1
            visited[v] = false
        dist[s] = 0
        while(true)do
            determine u whose dist[u] is
            smallest of unvisited vertices
            if(dist[u] == INF)then
                return
            visited[u] = true
            foreach neighbor v of u do
                w = weight of edge(u,v)
                newLen = dist[u] + w
                if(newLen < dist[v])then
                    dist[v] = newLen
                    prev[v] = u
    end
*/

class Grafo{
    private:
        int V, *dist, *prev;
        bool *visited;
        list< pair<int,int> > *ls;
    public:
        Grafo(int V){
            this->V = V;
            ls = new list< pair<int,int> >[V];
            prev = new int[V];
            dist = new int[V];
            visited = new bool[V];
        }

        void addEdge(int v1, int v2, int peso){
            ls[v1].push_back(make_pair(v2,peso));
        }

        int Dijkstra(int origen, int destino){
            for(int i = 0; i < V; i++){
                dist[i] = INF;
                prev[i] = -1;
                visited[i] = false;
            }
            dist[origen] = 0;
            int min, pos, w, newLen;
            while(true){
                min = INF;
                pos = -1;
                for(int i = 0; i < V; i++){
                    if( !visited[i] && dist[i] < min ){
                        min = dist[i];
                        pos = i;
                    }
                }
                if(pos == -1)
                    break;
                visited[pos] = true;
                list< pair<int,int> >::iterator it;
                for(it = ls[pos].begin(); it != ls[pos].end(); it++){
                    w = it->second;
                    newLen = dist[pos] + w;
                    if(newLen < dist[it->first]){
                        dist[it->first] = newLen;
                        prev[it->first] = pos;
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

    printf("%d\n",G.Dijkstra(0,1));
    return 0;
}
