#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
vector<bool> set(21);
vector<bool> allTrue(21, 1);
vector<bool> allFalse(21);

class COMMAND{
public:
	string com;
	int num;
	COMMAND(string c, int n){com = c; num = n;}
};

void add(int x){
	if(x>=1&&x<=20) set.at(x) = true;
	}
void remove(int x){
	if(x>=1&&x<=20) set.at(x) = false;
	}
void check(int x){
	if(x>=1&&x<=20){
		if(set.at(x)) cout << 1 << endl;
		else cout << 0 << endl;
		}
	}
void toggle(int x){
	if(x>=1&&x<=20){
		set.at(x) = !set.at(x);
	}
}
void all(){
	set.swap(allTrue);
}
void empty(){
	set.swap(allFalse);
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int len, tempN;
	string tempS;
	cin >> len;
	vector<COMMAND> comSet;
	comSet.reserve(len);
	for(int i=0;i<len;i++){
		cin >> tempS;
		if(tempS == "all" || tempS == "empty"){
			comSet.push_back(COMMAND(tempS, 0));
		}
		else{
			cin >> tempN;
			comSet.push_back(COMMAND(tempS, tempN));
		}
	}
	for(int i=0;i<len;i++){
		if(comSet[i].com == "add") add(comSet[i].num);
		else if(comSet[i].com == "remove") remove(comSet[i].num);
		else if(comSet[i].com == "check") check(comSet[i].num);
		else if(comSet[i].com == "toggle") toggle(comSet[i].num);
		else if(comSet[i].com == "all") all();
		else if(comSet[i].com == "empty") empty();
	}
}