#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Loc{
public:
	int h;
	int w;
	int t;
	Loc(int h_, int w_, int t_){
		h = h_;
		w = w_;
		t = t_;
	}
};

bool isOver(int num, int lim){
	if(num >= 0 && num < lim) return true;
	return false;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int w, h;
	int counter = 0, total = 0, result=0;
	vector<vector<int>> table;
	queue<Loc> queue;
	cin >> w >> h;
	table.reserve(h);
	for(int i=0;i<h;i++) table[i].reserve(w);
	total = w*h;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin >> table[i][j];
			switch(table[i][j]){
				case 1:
					queue.push(Loc(i, j, 0));
					counter+=1;
					break;
				case -1:
					total -= 1;
					break;
				default:
					break;
			}
		}
	}
	//cout << counter << " " << total << " " << queue.size() << endl;
	vector<Loc> neighbor;
	neighbor.reserve(4);
	neighbor.push_back(Loc(1,0,0));
	neighbor.push_back(Loc(-1,0,0));
	neighbor.push_back(Loc(0,1,0));
	neighbor.push_back(Loc(0,-1,0));
	while(queue.size()>0){
		Loc front = queue.front();
		queue.pop();
		if(result < front.t) result = front.t;
		
		for(int i=0;i<neighbor.size();i++){
			if(neighbor[i].h != 0){
				if(isOver(front.h+neighbor[i].h,h) && table[front.h+neighbor[i].h][front.w]==0){
					queue.push(Loc(front.h+neighbor[i].h,front.w,front.t+1));
					table[front.h+neighbor[i].h][front.w]=1;
					counter+=1;
				}
			}
			else{
				if(isOver(front.w+neighbor[i].w,w) && table[front.h][front.w+neighbor[i].w]==0){
					queue.push(Loc(front.h,front.w+neighbor[i].w,front.t+1));
					table[front.h][front.w+neighbor[i].w]=1;
					counter+=1;
				}
			}
		}
	}
	if(counter==total) cout << result;
	else cout << -1;
	return 0;
}