#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MIL 1000000
using namespace std;

class PERSON{
private:
	string name;
public:
	PERSON(string n){name=n;}
	bool strcmp(string n){
		if(name==n) return true;
		else return false;
	}
};

class HASH{
private:
	vector<PERSON> pSet;
public:
	HASH(){
		pSet.reserve(3);
	}
	void push(PERSON p){
		if(pSet.capacity()<=pSet.size()) pSet.reserve(pSet.capacity()+3);
		pSet.push_back(p);
	}
	bool search(string str){
		for(int i=0;i<pSet.size();i++){
			if(pSet[i].strcmp(str)) return true;
		}
		return false;
	}
};

int hashing(string str, int p, int m){
	int val=0;
	int pow=1;
	for(int i=0;i<str.length();i++){
		val = (val+(str[i]-'a'+1)*pow) % m;
		pow = (pow * p) % m; 
	}
	return val;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	
	const int polynomial = 31;
	const int modulo = 500000;
	int lenD, lenB, tempInt, result=0;
	string tempStr;
	vector<HASH> hashSet(modulo+1,HASH());
	vector<string> output;
	//hashSet.reserve(modulo+1);
	
	cin >> lenD >> lenB;
	output.reserve(lenB);
	for(int i=0;i<lenD;i++){
		cin >> tempStr;
		tempInt = hashing(tempStr, polynomial, modulo);
		hashSet[tempInt].push(PERSON(tempStr));
	}
	for(int i=0;i<lenB;i++){
		cin >> tempStr;
		tempInt = hashing(tempStr, polynomial, modulo);
		if(hashSet[tempInt].search(tempStr)){
			output.push_back(tempStr);
			result+=1;
		}
	}
	sort(output.begin(), output.end());
	cout << result << '\n';
	for(int i=0;i<output.size();i++) cout << output[i] << "\n";
}