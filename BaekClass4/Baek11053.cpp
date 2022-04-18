#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class eleInfo{
public:
	int num;
	int time;
	eleInfo(int n, int t){
		num=n;
		time=t;
	}
};

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int num, input, max;
	vector<eleInfo> arr;
	cin >> num;
	arr.reserve(num);
	
	cin >> input;
	arr.push_back(eleInfo(input,1));
	
	for(int i=1;i<num;i++){
		cin >> input;
		max = 0;
		for(int j=0;j<arr.size();j++){
			if(arr.at(j).num<input && arr.at(j).time>=max) max=arr.at(j).time;
		}
		arr.push_back(eleInfo(input,max+1));
	}
	
	max=arr.at(0).time;
	for(int i=0;i<arr.size();i++){
		if(arr.at(i).time>max) max = arr.at(i).time;
	}
	cout << max;
}

/*
해당 input에서 가장 긴 수열을 찾으려면 어떻게 해야할까?

본인이 감당 가능한 과거의 가장 긴 수열 + 본인
*/