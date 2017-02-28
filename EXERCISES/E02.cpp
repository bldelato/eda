#include <iostream>
using namespace std;

const int MAX=10000;

void aemet(int v[], int n, int &picos, int &valles){
	int ant1=v[0], ant2=v[1];

	for(int i=2;i<n;i++){
		if(ant2<ant1 && v[i]>ant2){
			valles++;
		}
		else if(ant2>ant1 && v[i]<ant2) {
			picos++;
		}
		ant1=ant2;
		ant2=v[i];
	}
}

int mainE2(){
	int cases, n, picos, valles;
	int v[MAX];
	bool wrong=false;

	cin >> cases;

	for(int a=0;a<cases;a++){
		picos=0;
		valles=0;
		cin >> n;
		for(int h=0;h<n;h++){
			cin >> v[h];
			if(v[h]< -50 || v[h]>60) wrong=true;
		}
		if(n>0 && n<=10000 && !wrong){
			aemet(v, n, picos, valles);
		}
		cout << picos << " " << valles << endl;
	}
	return 0;
}
