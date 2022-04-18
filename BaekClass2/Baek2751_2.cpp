#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 2500000
#define MIL 1000000
using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int len,temp, m=0;
	cin >> len;
	vector<int> set;
	set.reserve(len);
	for(int i=0;i<len;i++){
		cin >> temp;
		set.push_back(temp);
	}
	if(set.size()>3){
		bool isOut[MAX] = {false,};
		for(int i=0;i<set.size();i++){
			isOut[set[i]+MIL] = true;
			if(set[i]+MIL>m) m = set[i] + MIL; 
		}
		for(int i=0;i<MAX;i++){
			if(i>m) break;
			else if(isOut[i]) cout << i-MIL << "\n";
		} 
	}
	else{
		sort(set.begin(), set.end());
		for(int i=0;i<set.size();i++) cout << set[i] << "\n";
	}
}