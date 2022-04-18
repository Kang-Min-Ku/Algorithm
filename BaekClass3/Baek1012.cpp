#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MAX 50
using namespace std;

typedef struct{
	int xpos;
	int ypos;
}COORD;

class testCase{
public:
	int width;
	int height;
	int numVeg;
	bool land[MAX][MAX] = {false,};
	testCase(int w, int h, int n, vector<COORD> b){
		width = w;
		height = h;
		numVeg = n;
		for(int i=0;i<b.size();i++) land[b[i].ypos][b[i].xpos] = true;
	}
	testCase(){;}
};
//좀 더 나은 방법은 해시가 있겠네요
int main(){
	int numCase;
	cin >> numCase;
	testCase *test = new testCase[numCase];
	for(int i=0;i<numCase;i++){
		int width, height, num;
		vector<COORD> veg;
		veg.reserve(num);
		cin >> width >> height >> num;
		for(int j=0;j<num;j++){
			int x, y;
			cin >> x >> y;
			COORD temp = {x,y};
			veg.push_back(temp);
		}
		test[i] = testCase(width, height, num, veg);
	}
	
	//queue에 추가되는 방식 문제
	vector<COORD> queue;
	for(int i=0;i<numCase;i++){
		int result = 0;
		queue.reserve(test[i].width*test[i].height*4);
		for(int j=0;j<test[i].height;j++){
			for(int k=0;k<test[i].width;k++){
				if(test[i].land[j][k]){
					COORD temp_ = {j,k};
					queue.push_back(temp_);
					while(queue.size()>0){
						COORD front = queue.front();
						if(front.xpos > 0 && test[i].land[front.xpos-1][front.ypos]){
							COORD temp = {front.xpos-1, front.ypos};
							queue.push_back(temp);
						}
						if(front.ypos > 0 && test[i].land[front.xpos][front.ypos-1]){
							COORD temp = {front.xpos, front.ypos-1};
							queue.push_back(temp);
						}
						if(front.xpos < test[i].height - 1 && test[i].land[front.xpos+1][front.ypos]){
							COORD temp = {front.xpos+1, front.ypos};
							queue.push_back(temp);
						}
						if(front.ypos < test[i].width - 1 && test[i].land[front.xpos][front.ypos+1]){
							COORD temp = {front.xpos, front.ypos+1};
							queue.push_back(temp);
						}
						test[i].land[queue.front().xpos][queue.front().ypos] = false;
						queue.erase(queue.begin(), queue.begin()+1);
					}
					result+=1;
				}
			}
		}
		cout << result << endl;
		queue.clear();
	}
	
	delete [] test;
}