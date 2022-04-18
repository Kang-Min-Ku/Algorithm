#include <iostream>
#include <vector>

#define DIVIDER 10007
using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int width, result, size=0;
	vector<int> seq;
	cin >> width;
	seq.reserve(width);
	
	if(width>=2){
		seq.push_back(1);
		seq.push_back(2);
		size+=2;
	}
	else{
		seq.push_back(1);
		size+=1;
	}
	
	while(size<width){
		int temp = (seq.at(seq.size()-2) + seq.at(seq.size()-1))%DIVIDER;
		seq.push_back(temp);
		size+=1;
	}
	result = seq.back();
	cout << result;
	return 0;
}