#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	
	Node(int val){
		data= val;
		next = nullptr;
	}
};

class floydalgo{
	public:
	Node* head;
	
	floydalgo(){
		head=nullptr;
	}
	
	void insert(int val){
		Node* newNode  = new Node(val);
		if (!head){
			head = newNode;
			return;
		}
		
		Node* temp = head;
		while(temp->next){
			temp=temp->next;
		}
		temp->next = newNode;
	}
	
	bool detectCycle() {  // We will be using slow and fast pointers for this
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;           // move 1 step
            fast = fast->next->next;     // move 2 steps

            if (slow == fast) {
                cout << "Cycle exists" << endl;
                return true;
            }
        }
        cout << "There exists no Cycle" << endl;
        return false;
    }
};

int main() {
    floydalgo list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);

    // Create a cycle manually for testing
    list.head->next->next->next->next = list.head->next;

    list.detectCycle(); 

    return 0;
}
