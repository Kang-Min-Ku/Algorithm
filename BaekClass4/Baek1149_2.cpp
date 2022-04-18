#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Color{
public:
	vector<int> color;
	Color(int _r, int _g, int _b){
		color.reserve(3);
		color.push_back(_r);
		color.push_back(_g);
		color.push_back(_b);
	}
};

int main(){
	int num_house;
	int r,g,b;
	vector<Color> dp_color_set;
	cin >> num_house;
	dp_color_set.reserve(num_house+1);
	for(int i=0;i<num_house;i++){
		cin >> r >> g >> b;
		dp_color_set.push_back(Color(r,g,b));
	}
	for(int i=1;i<dp_color_set.size();i++){
		Color prev = dp_color_set.at(i-1);
		if(prev.color[1]>prev.color[2]) dp_color_set[i].color[0]+=prev.color[2];
		else dp_color_set[i].color[0]+=prev.color[1];
		
		if(prev.color[2]>prev.color[0]) dp_color_set[i].color[1]+=prev.color[0];
		else dp_color_set[i].color[1]+=prev.color[2];
		
		if(prev.color[1]>prev.color[0]) dp_color_set[i].color[2]+=prev.color[0];
		else dp_color_set[i].color[2]+=prev.color[1];
	}
	
	vector<int> result = dp_color_set.back().color;
	int min = *min_element(result.begin(),result.end());
	cout << min;
}

/*
만약 집 n개를 칠할 때 각 색의 최소값을 알고 있으면 n+1의 각 색의 최소값도 알 수 있다.
*/

/*
		if(prev.color[1]>prev.color[2]) dp_color_set[i].color[0]+=prev.color[2];
		else dp_color_set[i].color[0]+=prev.color[1];
		
		if(prev.color[2]>prev.color[0]) dp_color_set[i].color[1]+=prev.color[0];
		else dp_color_set[i].color[1]+=prev.color[2];
		
		if(prev.color[1]>prev.color[0]) dp_color_set[i].color[2]+=prev.color[0];
		else dp_color_set[i].color[2]+=prev.color[1];
*/