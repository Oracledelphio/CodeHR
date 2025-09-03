#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	
	Node(int val){
		data = val;
		next = nullptr;
	}
};

Node* reverseList(Node* head){
	if (head == nullptr || head->next ==nullptr){
		return head;
	}
	
	Node* newHead = reverseList(head->next);
	
	head->next->next = head;
	head ->next = nullptr;
	
	return newHead;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
		
		
