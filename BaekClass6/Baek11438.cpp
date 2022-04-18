#include <iostream>
#include <vector>
#include <string>

#define INITCHILDNUM 10
using namespace std;

class Node{
private:
	int value;
	int lv;
	vector<Node*> child;
	Node* parent;
public:
	Node(int v){
		value = v;
		lv = 1;
		child.reserve(INITCHILDNUM);
		parent = nullptr;
	}
	Node(int v,int l, Node* pNode){
		value = v;
		lv = l;
		child.reserve(INITCHILDNUM);
		parent = pNode;
		pNode->appendChild(this);
	}
	void appendChild(Node* node){
		if(child.size()>=child.capacity()) child.resize(child.capacity()+INITCHILDNUM);
		child.push_back(node);
	}
	int getVal(){return value;}
	int getLv(){return lv;}
	Node* getParent(){return parent;}
	void print(){
		cout << value << " " << lv << endl;
	}
	void printChildVal(){
		for(int i=0;i<child.size();i++) cout << child[i]->getVal() << " ";
		cout << endl;
	}
};

void printTree(vector<Node*> tree){
	for(int i=1;i<tree.size();i++){
		tree[i]->print();
		tree[i]->printChildVal();
		cout << endl;
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int numNode, numQuest;
	int val1, val2;
	vector<int> result;
	cin >> numNode;
	vector<Node*> nodeSet(numNode+1,nullptr);
	Node* root = new Node(1);
	nodeSet[1] = root;
	
	for(int i=1;i<numNode;i++){
		cin >> val1 >> val2;
		if(nodeSet[val1]==nullptr){
			Node* newNode = new Node(val1,nodeSet[val2]->getLv()+1,nodeSet[val2]);
			nodeSet[val1] = newNode;
		}
		else if(nodeSet[val2]==nullptr){
			Node* newNode = new Node(val2,nodeSet[val1]->getLv()+1,nodeSet[val1]);
			nodeSet[val2] = newNode;
		}
	}
	
	cin >> numQuest;
	result.reserve(numQuest);
	for(int i=0;i<numQuest;i++){
		cin >> val1 >> val2;
		while(val1!=val2){
			if(nodeSet[val1]->getLv()>nodeSet[val2]->getLv()) val1 = nodeSet[val1]->getParent()->getVal();
			else val2 = nodeSet[val2]->getParent()->getVal();
		}
		/*
		if(nodeSet[val1]->getVal()==nodeSet[val2]->getVal()){
			cout << nodeSet[val1]->getVal() << endl;
			continue;
		}
		*/
		while(nodeSet[val1]->getVal()!=nodeSet[val2]->getVal()){
			val1 = nodeSet[val1]->getParent()->getVal();
			val2 = nodeSet[val2]->getParent()->getVal();
		}
		cout << val1 << endl;
	}
}
/*
한쪽 레벨이 낮으면 같아질 때까지 맞춘다
-> 만약 레벨이 같은데 parent가 같으면 공통 parent겠지
Exception >> 한쪽이 한쪽의 parent인 경우
*/