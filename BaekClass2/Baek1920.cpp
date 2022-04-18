#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool binarySearch(vector<int> input, int target){
	int start = 0, end = input.size()-1;
	while(start <= end){
		int mid = (start+end)/2;
		if(input.at(mid)>target){
			end = mid-1;
		}
		else if(input.at(mid) < target){
			start = mid+1;
		}
		else return true;
	}
	return false;
}


int main(){
	//input
	int inputLen, targetLen, temp;
	vector<int> input, target;
	cin >> inputLen;
	input.reserve(inputLen);
	for(int i=0;i<inputLen;i++){
		cin >> temp;
		input.push_back(temp);
	}
	cin >> targetLen;
	target.reserve(targetLen);
	for(int i=0;i<targetLen;i++){
		cin >> temp;
		target.push_back(temp);
	}
	//
	sort(input.begin(),input.end());
	for(int i=0;i<targetLen;i++){
		if(binarySearch(input, target.at(i))) cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 1;
}