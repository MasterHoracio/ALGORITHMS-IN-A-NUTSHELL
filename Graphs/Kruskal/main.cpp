#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

/*
    Algoritmo: Kruskal (MST)

    Kruskal(G,v)
        vector<Arista> arbol
        size_arista = G.size()
        stable_sort(G)
        subset = new int[v]
        for i = 0 to v do
            subset[i] = -1
        foreach v E G do
            v1 = buscar(subset,v.getVertice1())
            v2 = buscar(subset,v.getVertice2())
            if(v1 != v2)then
                arbol.push(v)
                unir(subset,v1,v2)
    end

    buscar(subset[],i)
        if(subset[i] == -1)then
            return i
        return buscar(subset,subset[i])
    end

    unir(subset,v1,v2)
        v1_set = buscar(subset,v1)
        v2_set = buscar(subset,v2)
        subset[v1_set] = v2_set
    end
*/

class Arista{
    int vertice1, vertice2, peso;
    public:
        Arista(int v1, int v2, int peso){
            vertice1 = v1;
            vertice2 = v2;
            this->peso = peso;
        }
        int getVertice1(){
            return vertice1;
        }
        int getVertice2(){
            return vertice2;
        }
        int getPeso(){
            return peso;
        }
        bool operator < (const Arista& arista2)const{
            return (peso < arista2.peso);
        }
};

class Grafo{
    int V;
    vector <Arista> arista;
    public:

    Grafo(int V){
        this->V = V;
    }

    void addArista(int v1, int v2, int peso){
        Arista ars(v1,v2,peso);
        arista.push_back(ars);
    }

    //funcion find
    int buscar(int subset[], int i){
        if(subset[i] == -1)
            return i;
        return buscar(subset,subset[i]);
    }

    //funcion unir
    void unir(int subset[], int v1, int v2){
        int v1_set = buscar(subset,v1);
        int v2_set = buscar(subset,v2);
        subset[v1_set] = v2_set;
    }

    void kruskal(){
        vector<Arista> arbol;
        int size_aristas = arista.size();

        sort(arista.begin(),arista.end());

        int *subset = new int[V];
        memset(subset,-1,sizeof(int) * V);

        for(int i = 0; i < size_aristas; i++){
            int v1 = buscar(subset, arista[i].getVertice1());
            int v2 = buscar(subset, arista[i].getVertice2());

            if(v1 != v2){
                //si son diferentes no forman ciclo
                arbol.push_back(arista[i]);
                unir(subset,v1,v2);
            }
        }

        int size_arbol = arbol.size();

        for(int i = 0; i < size_arbol; i++){
            char v1 = 'A' + arbol[i].getVertice1();
            char v2 = 'A' + arbol[i].getVertice2();
            printf("(%c,%c) = %d\n",v1,v2,arbol[i].getPeso());
        }

    }

};

int main()
{
    Grafo G(7);
    G.addArista(0,1,7);
    G.addArista(0,3,5);
    G.addArista(1,2,8);
    G.addArista(1,3,9);
    G.addArista(1,4,7);
    G.addArista(2,4,5);
    G.addArista(3,4,15);
    G.addArista(3,5,6);
    G.addArista(4,5,8);
    G.addArista(4,6,9);
    G.addArista(5,6,11);

    G.kruskal();

    return 0;
}
