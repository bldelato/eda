#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

bool isSubstring(int l1, char v1[], int l2, char v2[], int ini, int end);
bool middleSolution(int l1, char v1[], int l2, char v2[], int ini, int end);

int main6(){
	bool sol;
	int l1, l2;
	char v1[MAX], v2[MAX];

	cin >> l1;
	cin >> l2;

	while ((l1 != 0 && l1 <= MAX) && (l2 != 0 && l2 <= MAX)){
		for (int i = 0; i < l1; i++){
			cin >> v1[i];
		}
		for (int j = 0; j < l2; j++){
			cin >> v2[j];
		}

		sol = isSubstring(l1, v1, l2, v2, 0, l1-1);
		if(sol){
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		cin >> l1;
		cin >> l2;
	}
	return 0;
}

bool isSubstring(int l1, char v1[], int l2, char v2[], int ini, int end){
	bool sol = false;
	int d= end-ini;
	int m = (d/2) + ini;

	if((d+1) > l2){
		sol = isSubstring(l1,v1, l2, v2, ini, m) || isSubstring(l1,v1, l2, v2, m+1, end);
	}
	if (!sol) {
		int k= l2-1; //number of elements of each side to be taken
		int index = m-k+1;
		if (index < ini) index = ini;
		int indexEnd = m+k;
		if (indexEnd > end) indexEnd = end;
		sol = middleSolution(l1, v1, l2, v2, index-1, indexEnd);
	}
	return sol;
}

bool middleSolution(int l1, char v1[], int l2, char v2[], int ini, int end){
	bool found=false;
	int j=0, i=ini;

	while(!found && (i+l2-1 <= end)){
		j=0;
		while(!found && (i+j < l1) && (j < l2) && (v1[i+j]==v2[j])){
			if(j==(l2-1)){ found = true; }
			j++;
		}
		i++;
	}
	return found;
}
