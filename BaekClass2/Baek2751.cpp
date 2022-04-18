#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAX 1000001
using namespace std;

bool comp(int x, int y){
	return x < y;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int len;
	cin >> len;
	int *number = new int(len);
	for(int i=0;i<len;i++) cin >> number[i];
	if(len > 100000){
		bool set[MAX] = {false,};
		for(int i=0;i<len;i++) set[number[i]] = true;
		for(int i=0;i<MAX;i++){
			if(set[i]) cout << i << '\n';
		}
	}
	else{
		sort(number, number+len); //사실 직접 자는게 낫지만..
		for(int i=0;i<len;i++) cout << number[i] << '\n';
	}
	delete [] number;
	return 0;
}