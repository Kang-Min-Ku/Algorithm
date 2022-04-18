#include <iostream>
#include <vector>
#include <queue>
#define MAX 1000001
using namespace std;



int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int num;
	cin >> num;
	queue<int> jobQueue;
	jobQueue.push(num);
	vector<int> minSet(num+1, MAX);
	minSet[num] = 0;
	while(minSet[1]>=MAX){
		int front = jobQueue.front();
		jobQueue.pop();
		if(front%3==0 && minSet[front/3] > minSet[front]+1){
			jobQueue.push(front/3);
			minSet[front/3]=minSet[front]+1;
		}
		if(front%2==0 && minSet[front/2] > minSet[front]+1){
			jobQueue.push(front/2);
			minSet[front/2]=minSet[front]+1;
		}
		if(minSet[front-1] > minSet[front]+1){
			jobQueue.push(front-1);
			minSet[front-1]=minSet[front]+1;
		}
	}
	cout << minSet[1];
}