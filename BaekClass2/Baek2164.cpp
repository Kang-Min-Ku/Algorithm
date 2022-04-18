#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<bool> divider(int num){
	vector<bool> result;
	while(num>1){
		int temp = num%2; //홀수면 true, 짝수면 false
		result.push_back(temp);
		num/=2;
	}
	reverse(result.begin(),result.end());
	return result;
}
//error report: 자기 자신이 앞으로 가는 케이스가 있음
int prediction(vector<bool> phaseSet){
	int front = 0, back = 0;
	for(int i=0;i<phaseSet.size();i++){
		if(phaseSet[i]) { //다음수가 홀수
			if(back > 0){
				front+=1;
				back-=1;
			}
			else{ //자기 자신이 앞으로 가는 케이스
				back = front;
				front = 0;
			}
			front = front*2+1;
			back = back*2+1;
		}
		else{
			front = front*2+1;
			back *= 2;
		}
	}
	return front+1;
}

int main(){
	int size;
	cin >> size;
	vector<bool> phaseSet = divider(size);
	cout << prediction(phaseSet);
}