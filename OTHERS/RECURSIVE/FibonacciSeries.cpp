#include <iostream>
using namespace std;

int multiplerecursiveFib(int n){
	int r;

	if(n==0) {
		r=0;
	}
	else if(n==1){
		r=1;
	}
	else if(n>1){
			r = multiplerecursiveFib(n-1) + multiplerecursiveFib(n-2);
		}
	return r;
}

int mainFi() {
	int n, a=0, sol;

	while(a < 10){
		cin >> n;
		sol = multiplerecursiveFib(n);
		cout << sol << endl;
		a++;
	}
	return 0;
}
