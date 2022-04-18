#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>
//포인터로도 구현해보기
#define MAX 1001
using namespace std;

bool isVisited[MAX] = {false,};

class VERTEX{
public:
	int index;
	vector<bool> edge;
	VERTEX(int i, int eSize){
		index = i;
		vector<bool> temp(eSize+1);
		edge.swap(temp);
	}
	void addEdge(int idx){
		edge[idx] = true;
	}
	void print(){
		cout << index << endl;
		for(int i=0;i<edge.size();i++) cout << edge[i] << " ";
		cout << "\n";
	}
};

int DFS(vector<VERTEX> graph, VERTEX V){
	int returnVal = 1;
	if(!isVisited[V.index]) {
		isVisited[V.index] = true;
		for(int i=1;i<V.edge.size();i++){
			if(V.edge[i] && !isVisited[i]){
				returnVal += DFS(graph, graph[i]);
			}
		}
		return returnVal;
	}
	else return 0;
}

int main(){
	int numV, numE, sP, eP, temp, result=0;
	//bool *isVisited;
	cin >> numV >> numE;
	//isVisited = new bool(numV+1);
	//memset(isVisited, false, numV+1);
	vector<VERTEX> graph;
	graph.reserve(numV+1);
	for(int i=0;i<=numV;i++){
		graph.push_back(VERTEX(i, numV));
	}
	for(int i=0;i<numE;i++){
		cin >> sP >> eP;
		graph[sP].addEdge(eP);
		graph[eP].addEdge(sP);
	}
	for(int i=1;i<=numV;i++){
		if(!isVisited[i]){
			temp = DFS(graph,graph[i]);
			result+=1;
		}
	}
	cout << result << "\n";
	//delete [] isVisited;
}