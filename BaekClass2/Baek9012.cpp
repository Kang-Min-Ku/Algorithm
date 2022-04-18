#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MAXSTRINGLEN 50
using namespace std;

//")(" 이런 케이스 조심
bool isVPS(string str){
	vector<bool> stack;
	stack.reserve(MAXSTRINGLEN);
	
	for(int i=0;i<str.length();i++){
		bool char_ = true; // '('는 true ')'는 false
		if(str[i]==')') char_ = false;
		
		if(str.size()==0) stack.push_back(char_);
		else if(char_==!stack.back()&&stack.back()) stack.pop_back();
		else stack.push_back(char_);
	}
	if(stack.size()>0) return false;
	else return true;
}

int main(){
	int len;
	cin >> len;
	string *strSet = new string[len];
	for(int i=0;i<len;i++) cin >> strSet[i];
	for(int i=0;i<len;i++){
		bool is = isVPS(strSet[i]);
		if(is) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}