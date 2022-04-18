#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAXSUM 300000
using namespace std;

//카드개수가 최대 100개기 때문에 brute force가 나을 수 있다.
//내 생각에는 큰 수부터 시작했으면 더 빠르지 않았을까 싶음
int main(){
	int size, limit, dis=MAXSUM;
	cin >> size >> limit;
	vector<int> cardSet;
	cardSet.reserve(size);
	for(int i=0;i<size;i++) cin >> cardSet[i];
	
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(i==j) continue;
			for(int k=0;k<size;k++){
				if(i==k||j==k) continue;
				int count = cardSet[i]+cardSet[j]+cardSet[k];
				if(limit-count>=0&&limit-count < dis) dis = limit-count;
			}
		}
	}
	cout << limit - dis;
}