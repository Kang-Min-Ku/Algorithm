#include <iostream>
#include <vector>
#define MAX 262144
using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int init, dst;
	cin >> init >> dst;
	vector<int> indexSec(MAX, MAX);
	indexSec[init]=1;
	vector<int> indexVisited;
	indexVisited.reserve(MAX);
	indexVisited.push_back(init);

	if(init > dst){
		cout << init-dst;
	}
	else{
		while(indexSec[dst]>=MAX){
			int range = indexVisited.size();
			for(int i=0;i<range;i++){
				if(indexSec[indexVisited[i]+1]>indexSec[indexVisited[i]]+1){
					if(indexSec[indexVisited[i]+1]==MAX) indexVisited.push_back(indexVisited[i]+1);
					indexSec[indexVisited[i]+1] = indexSec[indexVisited[i]]+1;
				}
				if(indexVisited[i]-1>=0){
					if(indexSec[indexVisited[i]-1]>indexSec[indexVisited[i]]+1){
						if(indexSec[indexVisited[i]-1]==MAX) indexVisited.push_back(indexVisited[i]-1);
						indexSec[indexVisited[i]-1] = indexSec[indexVisited[i]]+1;
					}
				}
				if(indexVisited[i]*2 <= MAX){
					if(indexSec[indexVisited[i]*2]>indexSec[indexVisited[i]]+1){
						if(indexSec[indexVisited[i]*2]==MAX) indexVisited.push_back(indexVisited[i]*2);
						indexSec[indexVisited[i]*2] = indexSec[indexVisited[i]]+1;
					}
				}
			}
		}
	
		cout << indexSec[dst]-1;
	}
}

/*
c++에서 조건문 확인 순서 A&&B면 A확인하고 안되면 컷인가
쓸모없는 계산이 많아져서 그런 듯
*/