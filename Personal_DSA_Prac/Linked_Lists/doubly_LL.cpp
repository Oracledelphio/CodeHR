#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class doublyLL{
    private:
    Node* head;
    public:
    doublyLL(){
        head = nullptr;
    }

    ~doublyLL(){
        Node* curr = head;
        while (curr != nullptr){
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }

    void insertAtHead(int val){
        Node* newNode = new Node(val);
        if (head != nullptr){
            head->prev = newNode;
        }
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int val){
        Node* newNode = new Node(val);
        if (head == nullptr){
            insertAtHead(val);
            return;
        }
        Node* temp = head;
        while (temp->next !=nullptr){
            temp = temp->next;
        }
        newNode->prev = temp;
        temp->next = newNode;
    }

    void deleteAtHead(){
        if (head==nullptr) return;
        Node* temp = head;
        head = head->next;
        if (head !=nullptr){
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteAtTail(){
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next !=nullptr){
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
    }

    void reverse(){
        if (head == nullptr || head->next == nullptr) return;
        Node* curr = head;
        Node* temp = nullptr;

        while (curr != nullptr){
            temp = curr->next;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    Node* findMiddle(){
        if (head == nullptr || head->next == nullptr) return;
        
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr and fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main() {
    doublyLL list;

    // Test Core Operations
    list.insertAtHead(10);
    list.insertAtHead(5);
    list.insertAtTail(15);
    list.insertAtTail(20);
 // 5 <-> 10 <-> 12 <-> 20 <-> NULL

    // Test Interview Classics
    list.reverse();
    Node* mid = list.findMiddle();
    if (mid != nullptr) {
        cout << "Middle element is: " << mid->data << "\n";
    }

    return 0;
}