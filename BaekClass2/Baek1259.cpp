#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isPallin(string str){
	for(int i=0;i<str.length()/2;i++){
		if(str.at(i) != str.at(str.length()-1-i)) return false;
	}
	return true;
}

int main(){
	vector<string> input;
	//input
	string temp = "";
	while(temp != "0"){
		cin >> temp;
		input.push_back(temp);
	}
	for(int i=0;i<input.size()-1;i++){
		if(isPallin(input[i])) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}