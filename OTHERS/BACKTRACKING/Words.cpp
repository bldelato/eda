#include <iostream>
using namespace std;


void treatSolution(int solution[], int m){
	cout << "Solution: ";
	for(int i = 0; i < m; i++)
		cout << solution[i] << " ";
	cout << endl;
}

void variations(int solution[], int k, int n, int m, bool marks[]){
	for(int letter = 0; letter < n; letter++){
		if(!marks[letter]){
			solution[k] = letter;
			if(k == m - 1){
				treatSolution(solution,m);
			}
			else{
				marks[letter] = true; // mark
				variations(solution, k + 1, n, m, marks);
				marks[letter] = false; // unmark
			}
		}
	}
}

void variations(int n, int m){
	bool marks[n];
	int solution[m];
	variations(solution, 0, n, m, marks);
}

int mainW(){
	variations(27, 5);
	return 0;
}

