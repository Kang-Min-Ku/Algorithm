#include <bits/stdc++.h>
using namespace std;
const int MAX = 18;
int N, M;
int parents[100000][MAX];
int depth[100000];
vector<int> adj[100000];
void MakeTreeDFS(int curr){
	for(int next: adj[curr]){
		if(depth[next]==-1){
			parents[next][0] = curr;
			depth[next] = depth[curr]+1;
			MakeTreeDFS(next);
		}
	}
}
int main(){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
cin >> N;
for (int i = 0; i < N-1; ++i){
	int a, b;
	cin >> a >> b;
	a--;
	b--;
	adj[a].push_back(b);
	adj[b].push_back(a);
}
memset(parents,-1,sizeof(parents));
fill(depth,depth+N, -1);
depth[0] = 0;
MakeTreeDFS(0);
for (int j = 0; j < MAX-1; ++j){
	for (int i = 1; i < N; ++i){
		int k = parents[i][j];
		if(k!=-1) parents[i][j+1] = parents[k][j];
	}
}
cin >> M;
for (int i = 0; i < M; ++i){
	int a, b;
	cin >> a >> b;
	a--; 
	b--;
	if(depth[a] < depth[b]) swap(a,b);
	int diff = depth[a] - depth[b];
	int j = 0;
	while(diff){
		if(diff%2) {
			a = parents[a][j];
		}
		j++;
		diff/=2;
	}
	if(a!=b){
		for (int j = MAX-1; j>=0; j--){
			if(parents[a][j]!=parents[b][j]){
				a = parents[a][j];
				b = parents[b][j];
			}			
		}
		a = parents[a][0];  
	}
	cout << a+1 << '\n';
}
return 0;
}

/*
line 46
2^n으로 뛰어 갈 수 있을 때 최소 회수

line 53
올라가기 단, 전체봐서 쓸모없는 반복 줄이기
-> 이 알고리즘이 logN이 나오는 이유
*/