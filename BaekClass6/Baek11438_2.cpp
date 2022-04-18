#include <iostream>
#include <vector>
#include <cmath>
#define MAX 100001
using namespace std;

vector<int> adj[MAX];
vector<vector<int>> parent;
vector<int> level;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void makeTreeByDFS(int curr){
	int next;
    for(int i=0;i<adj[curr].size();i++){
		next = adj[curr][i];
		if(level[next] == 0){
            parent[next][0]=curr;
            level[next] = level[curr] + 1;
            makeTreeByDFS(next);
        }
    }
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int numNode, numQuest;
	int val1, val2, tempLv, temp, maxLv;
	
	cin >> numNode;
	maxLv = (int)floor(log2(numNode));
	
	level.reserve(numNode+1);
	level.assign(numNode+1,0);
	level[1] = 1;
	parent.reserve(numNode+1);
	for(int i=0;i<=numNode;i++){
		parent[i].reserve(20);
		parent[i].assign(20,0);
	}
	//adj.reserve(numNode+1);
	//for(int i=0;i<=numNode;i++) adj[i].reserve(numNode+1);
	
	for(int i=0;i<numNode-1;i++){
		cin >> val1 >> val2;
		adj[val1].push_back(val2);
		adj[val2].push_back(val1);
	}
	makeTreeByDFS(1);
	for(int j=0;j<=numNode;j++){
		for(int i=2;i<=numNode;i++){
			if(parent[i][j]!=0){
				parent[i][j+1]=parent[parent[i][j]][j];
			}
		}
	}
	cin >> numQuest;
	for(int i=0;i<numQuest;i++){
		cin >> val1 >> val2;
		if(level[val1]<level[val2]) swap(&val1,&val2);
		
		while(level[val1]!=level[val2]){
			for(int i=0;i<parent[val1].size();i++){
				if(parent[val1][i]==0 || level[parent[val1][i]] < level[val2]){
					val1 = parent[val1][i-1];
					break;
				}
			}
		}
		int lca = val1;
		if(val1!=val2){
			for(int i=maxLv;i>=0;i--){
				if(parent[val1][i]!=parent[val2][i]){
					val1=parent[val1][i];
					val2=parent[val2][i];
				}
				lca = parent[val1][i];
			}
		}
		cout << lca << endl;
	}
	
}

/*
https://www.crocus.co.kr/660
1 ()
2 (1)
3 (2,1)
4 (3,2)
5 (4,3,1)
6 (5,4,2)
7 (6,5,3)
8 (7,6,4)
9 (8,7,5,1)
10 (9,8,6,2)

*/

/*
	for(int i=1;i<=numNode;i++){
		for(int j=0;j<parent[i].size();j++){
			if(parent[i][j]>0) cout << parent[i][j] << " ";
		}
		cout << endl;
	}
*/