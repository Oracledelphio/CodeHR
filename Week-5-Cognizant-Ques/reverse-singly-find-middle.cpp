#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = nullptr;
    }
};

class Solution {
private:
    Node* head;

public:
    Solution() {
        head = nullptr;
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void reverseList() {
        Node* curr = head;
        Node* prev = nullptr;

        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        head = prev; // 🔥 important
    }
    
    int middleElement(){
		if (!head) return -1;
		
		Node* slow = head;
		Node* fast = head;
		
		while (fast && fast->next){
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow->val;
		
	bool hasCycle(){
		Node* slow = head;
		Node* fast = head;
		
		while(fast && fast->next){
			slow = slow->next;
			fast = fast->next->next;
			
			if (slow == fast){
				return true;
			}
		}
		return false;
	}
	
	int num_nodes(){
		int counter = 0;
		Node* temp = head;
		while(temp){
			counter++;
			temp = temp->next;
		}
		return counter;
};
