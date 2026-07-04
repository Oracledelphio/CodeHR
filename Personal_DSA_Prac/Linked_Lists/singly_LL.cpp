#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class singlyLL{
    private:
    Node* head;
    public:
    singlyLL(){
        head = nullptr;
    }
    ~singlyLL(){
        Node* current = head;
        while (current != nullptr){
            Node* next_node = current->next;
            delete current;
            current = next_node;
        }
    }

    void display(){
        Node* current = head;
        while (current != nullptr){
            cout<< current->data << "->";
            current = current->next;
        }
        cout<<"nullptr" << endl;
    }

    void insertHead(int data){
        Node* newNode = new Node(data);
        newNode->next = head;
        head= newNode;
    }

    int size(){
        Node* curr = head;
        int count=0;
        while(curr != nullptr){
            count++;
            curr = curr->next;
        }
        return count;
    }

    void append(int data){
        Node* newNode = new Node(data);
        if (head == nullptr){
            head = newNode;
            return;
        }
        Node* current = head;
        while (current -> next != nullptr){
            current = current->next;
        }
        current->next = newNode;
    }

    int deleteValue(int key){
        Node* current = head;
        Node* prev = nullptr;

        if (current == nullptr){
            return;
        }

        if (current->data == key){
            head = current->next;
            delete current;
            return;
        }

        while (current != nullptr && current->data !=key){
            prev = current;
            current = current->next;
        }
        if (current == nullptr){
            return;
        }
        prev->next = current->next;
        delete current;

    }

};

int main() {
    singlyLL list;
    
    list.append(10);
    list.append(20);
    list.append(5);
    list.display(); // Output: 5 -> 10 -> 20 -> nullptr
    
    list.deleteValue(10);
    list.display(); // Output: 5 -> 20 -> nullptr
    
    return 0;
}