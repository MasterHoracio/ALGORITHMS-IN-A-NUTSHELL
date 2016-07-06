#include <cstdio>
#include <list>
#include <queue>
#define INF 1000000

using namespace std;

/*
    Algoritmo: Prim´s Algorithm

    Minimum Spanning Tree Algorithms

    computeMST(G)
        foreach v E V do
            key[v] = INF
            pred[v] = -1
        key[0] = 0
        PQ = new Priority Queue
        foreach v E V do
            insert(v,key[v]) into PQ

        while(PQ is not empty)do
            u = getMin(PQ)
            foreach edge (u,v) E E do
                if(PQ contains v)then
                    w = weight of edge (u,v)
                    if(w < key[v])then
                        pred[v] = u
                        key[v] = w
                        decreaseKey(PQ,v,w)
    end
*/

class Grafo{
    private:
        list< pair<int,int> > *ls;
        int V, *key, *pred;
        bool *visit;
    public:
        Grafo(int V){
            this->V = V;
            ls = new list< pair<int,int> >[V];
            key = new int[V];
            pred = new int[V];
            visit = new bool[V];
        }
        void addEdge(int v1, int v2, int peso){
            ls[v1].push_back(make_pair(v2,peso));
            ls[v2].push_back(make_pair(v1,peso));
        }
        void computeMST(int origen){
            int w;
            for(int i = 0; i < V; i++){
                key[i] = INF;
                pred[i] = -1;
                visit[i] = true;
            }
            key[origen] = 0;
            priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int, int> > > pq;
            for(int i = 0; i < V; i++)
                pq.push(make_pair(i,key[i]));
            while(!pq.empty()){
                pair<int,int> u = pq.top();
                pq.pop();
                visit[u.first] = false;
                list< pair<int,int> >::iterator it;
                for(it = ls[u.first].begin(); it != ls[u.first].end(); it++){
                    if(visit[it->first]){
                        w = it->second;
                        if(w < key[it->first]){
                            key[it->first] = w;
                            pred[it->first] = u.first;
                            //actualizamos key
                            priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int, int> > > aux;
                            pair<int,int> ap;
                            while(!pq.empty()){
                                ap = pq.top();
                                pq.pop();
                                if(ap.first == it->first){
                                    aux.push(make_pair(it->first,key[it->first]));
                                }else{
                                    aux.push(make_pair(ap.first,ap.second));
                                }
                            }
                            while(!aux.empty()){
                                ap = aux.top();
                                aux.pop();
                                pq.push(make_pair(ap.first,ap.second));
                            }
                            //fin de la actualizacion
                        }
                    }
                }

            }
        }
        void printMST(){
            printf("VERT:\t");
            for(int i = 0; i < V; i++)
                printf("%d\t",i);
            printf("\n");
            printf("KEY:\t");
            for(int i = 0; i < V; i++)
                printf("%d\t",key[i]);
            printf("\n");
            printf("PRED:\t");
            for(int i = 0; i < V; i++)
                printf("%d\t",pred[i]);
            printf("\n");
        }
};

int main()
{
    Grafo G(5);

    G.addEdge(0,1,2);
    G.addEdge(0,4,4);
    G.addEdge(0,3,8);
    G.addEdge(1,2,3);
    G.addEdge(4,2,1);
    G.addEdge(4,3,7);
    G.addEdge(2,3,5);

    G.computeMST(0);

    G.printMST();

    return 0;
}
