#include <iostream>
//#include <stdio.h>

using namespace std;

struct Node {
	int data = 0;
	struct Node* nxt = nullptr;
	struct Node* pre = nullptr;
};

Node* findNode(int index, Node* head, Node* last, int N) {
	Node* target = nullptr; //삽입 시작될 노드
	if (index == 0) target = nullptr;
	else if (index > N / 2) { //삽입 인덱스가 절반 이후일때 뒤에서부터 탐색
		int idx = N;
		target = last;
		while (idx != index) {
			target = target->pre;
			idx--;
		}
	}
	else {
		int idx = 1;
		target = head;
		while (idx != index) {
			target = target->nxt;
			idx++;
		}
	}
	return target;
}

int main() {
	//freopen("input.txt", "r", stdin);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t = 1; t < 11; t++) {
		Node* head = nullptr;
		Node* last = nullptr;
		int N = 0;
		cin >> N;

		//암호문 입력받아서 이중연결리스트 생성
		for (int i = 0; i < N; i++) {
			int data = 0;
			cin >> data;
			Node* cur = new Node;
			cur->data = data;
			if (head == nullptr) {
				head = cur;
				last = cur;
				cur->nxt = nullptr;
				cur->pre = nullptr;
			}
			else {
				last->nxt = cur;
				cur->nxt = nullptr;
				cur->pre = last;
				last = cur;
			}
		}

		//명령 입력 및 처리
		int opN = 0;
		cin >> opN;
		for (int i = 0; i < opN; i++) {
			char op = 0;
			int index = 0;
			int num = 0;
			Node* target = nullptr;
			cin >> op;
			switch (op)
			{
			case 'I':
				cin >> index >> num;
				target = findNode(index, head, last, N);
				for (int j = 0; j < num; j++) {
					int data = 0;
					cin >> data;
					Node* temp = new Node;
					temp->data = data;
					if (target == last) {
						temp->nxt = nullptr;
						last->nxt = temp;
						temp->pre = last;
						last = temp;
					}
					else if (target == nullptr) {
						temp->nxt = head;
						head->pre = temp;
						temp->pre = nullptr;
						head = temp;
					}
					/*else if (target == head) {
						temp->nxt = head;
						temp->pre = nullptr;
						head->pre = temp;
						head = temp;
					}*/
					else {
						temp->nxt = target->nxt;
						target->nxt = temp;
						temp->pre = target;
						temp->nxt->pre = temp;
					}
					target = temp;
				}
				N += num;
				break;
			case 'A':
				cin >> num;
				for (int j = 0; j < num; j++) {
					int data = 0;
					cin >> data;
					Node* temp = new Node;
					temp->data = data;
					last->nxt = temp;
					temp->nxt = nullptr;
					temp->pre = last;
					last = temp;
				}
				N += num;
				break;
			case 'D':
				cin >> index >> num;
				target = findNode(index, head, last, N);
				for (int j = 0; j < num; j++) {
					if (target == head) {
						head = target->nxt;
						head->pre = nullptr;
						delete target;
						target = head;
					}
					else if (target == last) {
						cout << "last node : cannot delete\n";
					}
					else {
						Node* temp = target->nxt;
						target->nxt = temp->nxt;
						temp->nxt->pre = target;
						delete temp;
					}
				}
				N -= num;
				break;
			default:
				cout << op << "wrong input \n";
				break;
			}
		}

		Node* temp = head;
		cout << "#" << t << " ";
		for (int i = 0; i < 10; i++) {
			cout << temp->data << " ";
			temp = temp->nxt;
		}
		cout << endl;
	}
}
