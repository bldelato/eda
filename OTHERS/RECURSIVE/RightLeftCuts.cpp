/*
Recursive function that calculates the number of
elements whose value equals the sum of all the elements
which are to their right
*/

//TAIL RECURSIVE

#include <iostream>
using namespace std;

int rightCutsGen(int v[], int num, int s){
	int r;

	if(num==0) r=0;

	else if(num>0){
		if(s==v[num-1])
			r=rightCutsGen(v, num-1, s+v[num-1]) + 1;
		else
			r=rightCutsGen(v, num-1, s+v[num-1]);
	}
	return r;
}

int rightCuts(int v[], int num){
	return rightCutsGen(v, num, 0);
}

int leftCutsGen(int v[], int num, int a, int s, int i){
	int r;

	if(i==num) r=a;

	else if(i<num){
		if(s==v[i])
			r=leftCutsGen(v, num, a+1,s+v[i], i+1);
		else
			r=leftCutsGen(v, num, a, s+v[i], i+1);
	}
	return r;
}

int leftCuts(int v[], int num){
	return leftCutsGen(v, num, 0, 0, 0);
}

int mainRLC() {
	int v1[] = {3, 3,12, 6, 3, 3};
	int r,l;

	r = rightCuts(v1, 6);

	cout << "The number of elements to the right: ";
	cout << r << "  " << endl;

	l = leftCuts(v1, 6);

	cout << "The number of elements to the left: ";
	cout << l << "  ";

	return 0;
}
