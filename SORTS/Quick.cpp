#include <iostream>
using namespace std;

void partition(int v[], int a, int b, int &p){
	int i, j, aux;

	i=a+1;
	j=b;

	while(i<=j){
		if((v[i]>v[a]) && (v[j]<v[a])){
			aux=v[i];
			v[i]=v[j];
			v[j]=aux;
			i=i+1;
			j=j-1;
		}
		else{
			if(v[i]<=v[a]) i=i+1;
			if(v[j]>=v[a])j=j-1;
		}
	}
	p=j;
	aux= v[a];
	v[a]=v[p];
	v[p]=aux;
}

void quickSort(int v[], int a, int b){
	int p;

	if(a<=b){
		partition(v, a, b, p);
		quickSort(v, a, p-1);
		quickSort(v, p+1, b);
	}
}

void quickSort(int v[], int num){
	quickSort(v, 0, num-1);
}

int mainQ() {
	int v1[] = {3, 5, -7, 1, 8, 4};

	quickSort(v1, 6);

	cout << "The sorted array: ";
	for(int a =0;a < 6;a++){
		cout << v1[a] << "  ";
	}

return 0;
}
