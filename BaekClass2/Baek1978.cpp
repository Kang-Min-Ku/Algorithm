#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAXNUM 1000
using namespace std;

//사실 아무것도 없는 상태에서는 recursion을 써서 소수를 구해내면 되지만 지금은 소수와 범위를 아므로 그냥 쓰겠음
vector<int> eratos(int *primeSet, int setLen, int max){
	vector<int> numSet(max);
	int numSetSqrt = int(sqrt(double(max)));
	for(int i=0;i<max-1;i++) numSet[i] = i+2;
	for(int i=0;i<setLen;i++){
		if(numSetSqrt < primeSet[i]) break;
		for(int j=0;j<numSet.size();j++){
			if(numSet[j] % primeSet[i] == 0 && numSet[j] != primeSet[i]) numSet[j]=0;
		}
	}
	return numSet;
}

int main(){
	int len;
	cin >> len;
	vector<int> input(len);
	int primeSet[] = {2,3,5,7,11,13,17,19,23,29,31};
	input.reserve(len);
	for(int i=0;i<len;i++){
		cin >> input[i];
	}
	sort(input.begin(), input.end());
	vector<int> result = eratos(primeSet, 11, input.back());
	
	int count = 0, inputIdx = 0, resultIdx = 0;
	while(resultIdx < result.size()){
		if(result[resultIdx]==0){
			resultIdx+=1;
			continue;
		}
		else if(result[resultIdx] == input[inputIdx]){
			count+=1;
			resultIdx+=1;
			inputIdx+=1;
		}
		else if(result[resultIdx] > input[inputIdx]){
			inputIdx+=1;
		}
		else{
			resultIdx+=1;
		}
	}
	
	cout << count;
}