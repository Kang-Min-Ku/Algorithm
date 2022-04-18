#include <iostream>
#include <algorithm>
#include <vector>
#define SIZE 1001

using namespace std;

int main(){
	int len, result=0, preTime = 0;
	cin >> len;
	vector<int> time(SIZE);
	for(int i=0;i<len;i++){
		int temp;
		cin >> temp;
		time[temp] += 1;
	}
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<time[i];j++){
			preTime += i;
			result += preTime;
		}
	}
	cout << result;
}