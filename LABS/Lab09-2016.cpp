#include <iostream>
using namespace std;


bool operation(int k, int v[], int &acc, int l){
	bool possible=false;

	//else if(l==5)
//	else{
//		for(int i = l;i<5;i++){
//			if(){
//				if(acc==k && l==4){
//					return true;
//				}
//				else{
//					operation(k, v, acc, l+1);
//				}
//			}
//		}
//	}


	return possible;
}

int main9(){
	int k, acc=0;
	int v[5];

	cin >> k;

	while(cin){
		for(int a = 0;a<5;a++) cin >> v[a];
		acc=v[0];

//		if(operation(k, v, acc, )) cout << "YES";
//		else cout << "NO";
		cout << endl;
		cin >> k;
	}
	return 0;
}
