#include <iostream>
#include <vector>
#include <string>
using namespace std;

char getLast(string str){
	return str.at(str.size()-1);
}

string popStr(string str){
	str.pop_back();
	return str;
}

int longer(int a, int b){
	if(a >= b) return a;
	else return b;
}

int lcs(string m, string n){
	if(m.size()==0||n.size()==0) return 0;
	else if(getLast(m)==getLast(n)) return lcs(popStr(m),popStr(n))+1;
	else return longer(lcs(popStr(m),n),lcs(m,popStr(n)));
}

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	string m, n;
	cin >> m >> n;
	cout << lcs(m,n);
}

/*
문자열 M N에 대해

lcs(Mi,Nj)
1. 0
2. lcs(Mi-1,Nj-1)+1		-> 끝이 똑같음
3. longer(lcs(Mi-1,Nj), lcs(Mi,Nj-1))		-> 끝이 다름 case 1. Mi로 끝나는 경우 case2. Mi로 끝나지 않는 경우
*/