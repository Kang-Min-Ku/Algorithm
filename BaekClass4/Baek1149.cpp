#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class House{
public:
	char leftmost_color;
	char rightmost_color;
	int price;
	House(char lc, char rc, int p){
		leftmost_color = lc;
		rightmost_color = rc;
		price = p;
	}
};

class HouseSet{
public:
	vector<House> set;
	HouseSet(char c1, char c2, char c3, int p1, int p2, int p3){
		set.reserve(3);
		set.push_back(House(c1,c1,p1));
		set.push_back(House(c2,c2,p2));
		set.push_back(House(c3,c3,p3));
	}
};

int getExponent(int n){
	int result=0;
	while(n>1){
		n/=2;
		result+=1;
	}
	return result;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int num_house;
	int r,g,b;
	int num_loop;
	vector<HouseSet> input;
	cin >> num_house;
	num_loop = getExponent(num_house);
	input.reserve(num_house);
	
	for(int i=0;i<num_house;i++){
		cin >> r >> g >> b;
		input.push_back(HouseSet('r','g','b',r,g,b));
	}

	for(int i=0;i<num_loop;i++){
		//여기부터	
	}
}

/*

ㅁ ㅁ ㅁ ㅁ ㅁ ㅁ ㅁ ㅁ

ㅁㅁ ㅁㅁ ㅁㅁ ㅁㅁ

ㅁㅁㅁㅁ ㅁㅁㅁㅁ

ㅁㅁㅁㅁㅁㅁㅁㅁ

-> 이 방법이 졸라 큰 input에서는 더 좋음
*/