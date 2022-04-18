#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
/*
Baek10814_2.cpp:34:24: error: no matching function for call to ‘info::info()’
   34 |  userSet = new info[len];
constructor 함수 빈걸로 하나 추가해주니가 됫다 23
*/
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
	info(){}
	void print(){
		cout << age << " " << name << endl;
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
	info* userSet;
	userSet = new info[len];
	for(int i=0;i<len;i++){
		int ti;
		string ts;
		cin >> ti >> ts;
		userSet[i] = info(ti,ts,i);
	}
	sort(userSet, userSet+len, comp);
	for(int i=0;i<len;i++) userSet[i].print();
	delete [] userSet;
}