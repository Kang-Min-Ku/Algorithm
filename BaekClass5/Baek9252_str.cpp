#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> lcsTable;

string compStr(string str1, string str2){
	if(str1.size()>=str2.size()) return str1;
	else return str2;
}

void lcs(){
	for(int i=2;i<lcsTable.size();i++){
		for(int j=2;j<lcsTable[i].size();j++){
			if(lcsTable[i][0]==lcsTable[0][j]) lcsTable[i][j] = lcsTable[i-1][j-1]+lcsTable[i][0];
			else lcsTable[i][j]=compStr(lcsTable[i-1][j],lcsTable[i][j-1]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	string m, n;
	cin >> m >> n;
	lcsTable.assign(n.size()+2, vector<string>(m.size()+2,""));
	for(int i=2;i<lcsTable[0].size();i++) lcsTable[0][i] = m.at(i-2);
	for(int i=2;i<lcsTable.size();i++) lcsTable[i][0] = n.at(i-2);
	
	for(int i=0;i<lcsTable.size();i++){
		for(int j=0;j<lcsTable[i].size();j++){
			if(lcsTable[i][j]=="") cout << "? ";
			else cout << lcsTable[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	lcs();
	
	for(int i=0;i<lcsTable.size();i++){
		for(int j=0;j<lcsTable[i].size();j++){
			if(lcsTable[i][j]=="") cout << "? ";
			else cout << lcsTable[i][j] << " ";
		}
		cout << endl;
	}
	
	string lcs = lcsTable[n.size()+1][m.size()+1];
	cout << lcs.size() << endl;
	if(lcs.size()>0) cout << lcs;
}

/*
	for(int i=0;i<lcsTable.size();i++){
		for(int j=0;j<lcsTable[i].size();j++){
			if(lcsTable[i][j]=="") cout << "? ";
			else cout << lcsTable[i][j] << " ";
		}
		cout << endl;
	}
*/