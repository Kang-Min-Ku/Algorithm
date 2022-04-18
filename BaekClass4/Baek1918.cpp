#include <iostream>
#include <vector>
#include <stack>
#include <string>

#define LIM 100
using namespace std;

int getLv(string str){
	if(str=="+"||str=="-") return 1;
	else if(str=="*"||str=="/") return 2;
	return 0;
}

void inToPost(stack<string> *operand, stack<string> *sign){
	string str1 = (*operand).top();
	(*operand).pop();
	string str2 = (*operand).top();
	(*operand).pop();
	string new_top = str1 + str2 + (*sign).top();
	(*sign).pop();
	(*operand).push(new_top); 
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	string in;
	cin >> in;
	in = "(" + in;
	stack<string> input;
	stack<string> operand;
	stack<string> sign;
	for(int i=0;i<in.length();i++){
		input.push(in.substr(i,1));
	}
	sign.push(")");
	
	while(!input.empty()){
		string top_str = input.top();
		char top = input.top().at(0);
		input.pop();
		if(top>=65 && top<=90){
			operand.push(top_str);
			if(sign.top() != ")" && input.top() != "(" && getLv(sign.top())>getLv(input.top())){
				inToPost(&operand, &sign);
			}
			else if(input.top()=="("){
				while(sign.top()!=")") inToPost(&operand,&sign);
				sign.pop();
				input.pop();
			}
		}
		else{
			if(top_str=="("){
				while(sign.top()!=")") inToPost(&operand,&sign);
				sign.pop();
			}
			else if(input.top()==")"){
				sign.push(top_str);
				sign.push(input.top());
				input.pop();
			}
			else{
				while(getLv(top_str)<getLv(sign.top())){
					if(getLv(top_str)==0) break;
					inToPost(&operand,&sign);
				}
				sign.push(top_str);
			}
		}
	}
	cout << operand.top();
}
