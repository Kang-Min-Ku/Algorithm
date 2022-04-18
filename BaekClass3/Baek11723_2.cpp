#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int set = 0x0;

void add(int x){
	if(x>=1 && x <= 20) set = set | (0x1<<(x-1));
}
void remove(int x){
	if(x>=1 && x <= 20) set = set & (0xFFFFF ^ (0x1<<(x-1)));
}
void check(int x){
	if(x>=1 && x <= 20){
		if(set & (0x1<<(x-1))) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}
void toggle(int x){
	if(x>=1 && x <= 20){
		if(set & (1<<(x-1))) set = set & (0xFFFFF ^ (0x1<<(x-1)));
		else set = set | (0x1<<(x-1));
	}
}
void all(){
	set = 0xFFFFF;
}
void empty(){
	set = 0x0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int len;
	cin >> len;
	for(int i=0;i<len;i++){
		string com;
		int num;
		cin >> com;
		if(com != "all" && com != "empty") cin >> num;
		if(com == "add") add(num);
		else if(com == "remove") remove(num);
		else if(com == "check") check(num);
		else if(com == "toggle") toggle(num);
		else if(com == "all") all();
		else if(com == "empty") empty();
	}
}