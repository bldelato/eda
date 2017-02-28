#include <iostream>
using namespace std;

int factorial (int num){
	int result = 1, i = 1;

	while(i <= num){
		result=result*i;
		i++;
	}

	return result;
}

int recursiveFactorial(int num){
	int r;

	if(num==0) {
		r=1;
	}
	else if(num>0){
		r = num*recursiveFactorial(num-1);
	}
	return r;
}

int mainF() {
	int n, a= 0, sol;

	while(a < 10){
		cin >> n;
		sol = recursiveFactorial(n);
		cout << sol << endl;
		a++;
	}
	return 0;
}

