#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
//클래스 안에 넣을라면 TREE 클래스가 하나 더 필요함
class NODE{
public:
	int val;
	NODE *left, *right, *p;
	NODE(int v){
		val = v;
	}
	NODE(){;}
};

void insertNode(NODE *heap, int v){
	NODE *newNode = new NODE(v);
	NODE *copyHeap = heap;
	int numNode = countNode(heap), treeLv = countLv(heap);
	//마지막 위치에 노드 넣기
	while(1){
		for(int i=treeLv;i>0;i--){
			if()
		}
	}
	while(1){
		if(newNode->p != NULL && newNode->val > newNode->p->val){
			int temp = newNode -> val;
			newNode -> val = newNode -> p -> val;
			newNode -> p -> val = temp;
			newNode = newNode -> p;
		}
		else break;
	}
}

int countLv(NODE *heap){
	int cnt = 1;
	if(heap != NULL) cnt = 1 + countLv(heap->left);
	return cnt;
}

int countNode(NODE *heap){
	int cnt = 0;
	if(heap != NULL) cnt = 1 + countNode(heap->left) + countNode(heap->right);
	return cnt;
}

int main(){
	int len, com;
	NODE *heap = new NODE(3);
	//cin >> len;
	//for(int i=0;i<len;i++){}
	//insertNode(heap, 3);
	cout << countNode(heap) << endl;
	insertNode(heap, 54);
	insertNode(heap, 6);
	insertNode(heap, 13);
}