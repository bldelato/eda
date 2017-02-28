/*
Calculate the greatest common divisor (GCD) of two natural
numbers using the Euclidean algorithm
 */


#include <iostream>
using namespace std;

int tailrecursiveGCD(int a, int b){
	int m;

	if(a==b) {
		m=a;
	}
	else if(a>b){
		m = tailrecursiveGCD(a-b,b);
	}
	else if(a<b){
			m = tailrecursiveGCD(a,b-a);
		}
	return m;
}

int mainGCD() {
	int n, m,a=0, sol;

	while(a < 10){
		cin >> n;
		cin >> m;
		sol = tailrecursiveGCD(n, m);
		cout << sol << endl;
		a++;
	}
	return 0;
}
