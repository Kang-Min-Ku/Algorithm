#include <iostream>
#include <algorithm>

using namespace std;

bool desc(int a, int b){ return a < b; }

int main(){
	int input[9];
	int index = 0;
	for(int i=0;i<9;i++){
		cin >> input[i];
	}
	for(int i=0;i<9;i++){
		if(input[i]>input[index]){
			index = i;
		}
	}
	cout << input[index] << endl << index+1;
}