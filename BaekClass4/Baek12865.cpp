#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int num, power, max=0;
	int itemWeight, itemValue;
	cin >> num >> power;
	vector<vector<int>> value(num,vector<int>(power+1,0)); 
	
	for(int i=0;i<num;i++){
		cin >> itemWeight >> itemValue;
		if(i==0){
			if(itemWeight <= power) value[0][itemWeight] = itemValue;
			continue;
		}
		for(int j=0;j<itemWeight;j++){
			value[i][j]=value[i-1][j];
		}
		for(int j=0;j<power+1-itemWeight;j++){
			if(value[i-1][j]+itemValue>value[i-1][j+itemWeight]){
				value[i][j+itemWeight]=value[i-1][j]+itemValue;
			}
			else value[i][j+itemWeight]=value[i-1][j+itemWeight];
		}
	}
	for(int i=0;i<value[num-1].size();i++){
		if(max<value[num-1][i]) max = value[num-1][i];
	}
	cout << max;
}

/*
무게의 관점에서 생각안해서 한동안 생각이 안난거.
어떻게 담으면 최대일까를 고민했지 어떤 무게에서 최대일까를 생각안해봤잖아.
이전의 최대값얻기 -> 이전의 최대값 알면 이번의 최대값도 알 수 있겠지
내가 사용할 수 있는게 뭔지
Pn+1 과 Pn 사이의 관계를 생각해야지

	for(int i=0;i<num;i++){
		cin >> itemWeight >> itemValue;
		if(itemWeight>power) continue;
		for(int j=0;j<power+1-itemWeight;j++){
			if(value[j]+itemValue>value[j+itemWeight]){
				value[j+itemWeight] = value[j]+itemValue;
			}
		}
	}
	for(int i=0;i<value.size();i++){
		if(max<value[i]) max = value[i];
	}
	cout << max;
	
		for(int i=0;i<num;i++){
		for(int k=1;k<power+1;k++){
			cout << value[i][k] << " ";
		}
		cout << endl;
	}
*/