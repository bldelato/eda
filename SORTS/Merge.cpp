#include <iostream>
using namespace std;

void merge(int v[], int a, int m, int b){
	int *u = new int[b-a+1];
	int i, j, k;

	for (k=a;k<=b;k++){
		u[k-a]=v[k];
	}
	i=0;
	j=m-a+1;
	k=a;
	while((i<=m-a) && (j<=b-a)){
		if(u[i]<=u[j]){
			v[k]=u[i];
			i=i+1;
		}
		else {
			v[k]=u[j];
			j=j+1;
		}
		k=k+1;
	}
	while(i<=m-a){
		v[k]=u[i];
		i=i+1;
		k=k+1;
	}
	while(j<=b-a){
		v[k]=u[j];
		j=j+1;
		k=k+1;
	}
	delete[] u;
}

void mergeSort(int v[], int a, int b){
	int m;

	if(a<b){
		m=(a+b)/2;
		mergeSort(v, a, m);
		mergeSort(v, m+1, b);
		merge(v, a, m, b);
	}
}

void mergeSort(int v[], int num){
	mergeSort(v, 0, num-1);
}

int mainM() {
	int v1[] = {3, 5, -7, 1, 8, 4};

	mergeSort(v1, 6);

	cout << "The sorted array: ";
	for(int a =0;a < 6;a++){
		cout << v1[a] << "  ";
	}

return 0;
}
