#include <iostream>
using namespace std;

const int MAX = 100000;

int piedras(char v[], int i, int j, char c){
	int sol = 0;

	while(i<=j){
		if(v[i]==c) sol++;
		i++;
	}
	return sol;
}

int xxxx(char v[], int n, int tam, int numr, int numz){
	int cont = 0, i=0, j;
	j=tam-1 + i;

	while(j<n){
		if((piedras(v,i,j,'r')>=numr) && (piedras(v,i,j,'z')>=numz)){
			cont++;
		}
		i++;
		j++;
	}
	return cont;
}

int mainD0(){
	int cases,n, tam, numr, numz, result;
	char v[MAX];

	cin >> cases;

	for(int a=0;a<cases;a++){
		cin >> n >> tam >> numr >> numz;
		for(int h=0;h<n;h++){
			cin >> v[h];
		}
		if(n>0){
			result = xxxx(v,n,tam,numr,numz);
			cout << result << endl;
		}
	}
	return 0;
}
