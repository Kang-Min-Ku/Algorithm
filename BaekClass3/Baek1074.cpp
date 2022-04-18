#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int result = 0, size = 1, input, loc;
	float row, col;
	float startR=0, startC=0, endR, endC, midR, midC;
	cin >> input >> row >> col;
	for(int i=0;i<input;i++) size *= 2; //size는 각 변 길이
	endR = startR + size - 1;
	endC = startC + size - 1;
	
	while(size > 1){
		midR = (startR + endR) / 2.0;
		midC = (startC + endC) / 2.0;
		if(row - midR < 0 && col - midC < 0) loc = 0;
		else if(row - midR < 0 && col - midC > 0){
			loc = 1;
			startC = startC + size/2;
		}
		else if(row - midR > 0 && col - midC < 0){
			loc = 2;
			startR = startR + size/2;
		}
		else {
			loc = 3;
			startR = startR + size/2;
			startC = startC + size/2;
		}
		endR = startR + (size/2 - 1);
		endC = startC + (size/2 - 1);
		result += loc * (size / 2) * (size / 2);
		size/=2;
	}
	cout << result << endl;
}