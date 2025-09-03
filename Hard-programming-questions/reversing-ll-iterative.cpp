#include <iostream>
using namespace std;


// This Approach Below we will be Following Iteratively

struct Node{
	int data;
	Node* next;
	
	Node(int val){
		data = val;
		next = nullptr;
	}
};

Node* reverseList(Node* head){
	Node* prev = nullptr;
	Node* curr = head;
	Node* next = nullptr;
	
	while (curr !=nullptr){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example list: 1 -> 2 -> 3 -> 4 we created
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
	
	
