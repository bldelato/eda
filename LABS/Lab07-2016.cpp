#include <iostream>
#include <math.h>
using namespace std;

struct Matrix {
	int a1;
	int b1;		//	| a1   b1 |
	int a2;		//	| a2   b2 |
	int b2;
};

Matrix empty(){
	Matrix m;
	m.a1=0;
	m.a2=0;
	m.b1=0;
	m.b2=0;
	return m;
}

Matrix identity(){
	Matrix m;
	m.a1=1;
	m.a2=0;
	m.b1=0;
	m.b2=1;
	return m;
}

Matrix prod(Matrix m1, Matrix m2){
	Matrix m;
	m.a1=(m1.a1*m2.a1 + m1.b1*m2.a2) % 46337;
	m.a2=(m1.a2*m2.a1 + m1.b2*m2.a2) % 46337;
	m.b1=(m1.a1*m2.b1 + m1.b1*m2.b2) % 46337;
	m.b2=(m1.a2*m2.b1 + m1.b2*m2.b2) % 46337;
	return m;
}

int main7(){
	int n;

	cin >> n;

	while(n!=0 && n>0 && n<(pow(2, 31)-1)){



	cin >> n;
	}
	return 0;
}

//int fib(){
//	int sol;
//
//	return sol;
//}


