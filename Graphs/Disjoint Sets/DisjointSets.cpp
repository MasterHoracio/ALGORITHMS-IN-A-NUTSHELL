#include <cstdio>
#include <map>

using namespace std;

map <int, int> parent;
map <int, int> n_nod;

void makeSet(int s){
	parent[s] = s;
	n_nod[s] = 0;
}

int Find(int f){
	if(parent[f] == f)
		return parent[f];
	else
		return Find(parent[f]);
}

void Union(int p, int q){
	int setp, setq;

	setp = Find(p);
	setq = Find(q);

	if(n_nod[setp] > n_nod[setq]){
		parent[setq] = setp;
	}else if(n_nod[setq] > n_nod[setp]){
		parent[setp] = setq;
	}else{
		parent[setp] = setq;
		n_nod[setq]++;
	}

}


int main(){
	int n_sets, set, n_unions, one, two, n_find, f;

	printf("Ingrese el numero de conjuntos: ");
	scanf("%d",&n_sets);

	for(int i = 0; i < n_sets; i++){
		scanf("%d",&set);
		makeSet(set);
	}

	printf("Ingrese el numero de Uniones: ");
	scanf("%d",&n_unions);

	for(int i = 0; i < n_unions; i++){
		scanf("%d %d",&one,&two);
		Union(one,two);
	}

	printf("Ingrese el numero de busquedas: ");
	scanf("%d",&n_find);

	for(int i = 0; i < n_find; i++){
		scanf("%d",&f);
		printf("%d\n",Find(f));
	}

	return 0;
}