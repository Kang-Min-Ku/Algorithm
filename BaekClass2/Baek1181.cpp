#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(string a, string b){
	if(a.length() == b.length()) return a<b;
	return a.length() < b.length();
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int len;
	cin >> len;
	string *input = new string[len];
	for(int i=0;i<len;i++) cin >> input[i];
	sort(input, input+len, comp);
	for(int i=0;i<len;i++){
		if(i!=0&&input[i]==input[i-1]) continue;
		cout << input[i] << endl;
	}
}