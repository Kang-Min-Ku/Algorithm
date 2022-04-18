#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class info{
public:
	int age;
	string name;
	int order;
	info(int a, string n, int o){
		age = a;
		name = n;
		order = o;
	}
	void print(){
		cout << age << " " << name << "\n";
	}
};

bool comp(info a, info b){
	if(a.age == b.age) return a.order < b.order;
	else return a.age < b.age;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int len;
	cin >> len;
	vector<info> userSet;
	userSet.reserve(len);
	for(int i=0;i<len;i++){
		int ti;
		string ts;
		cin >> ti >> ts;
		userSet.push_back(info(ti, ts, i));
	}
	sort(userSet.begin(), userSet.end(), comp);
	for(int i=0;i<len;i++) userSet[i].print();
}