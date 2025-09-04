#include <iostream>
using namespace std;

class Stack{
	int capacity;
	int top;
	int* arr;
	
	public:	
	Stack(int size){
		capacity =size;
		top=-1;
		arr = new int[capacity];
	}
	
	~Stack(){
		delete[] arr;
	}
	
	void push(int val){
		if (isFull()){
			cout<<"The Stack is Full cannot Push!";
			return;
		}
		arr[++top] = val;
	}
	
	int pop(){
		if (isEmpty()){
			cout<<"The Stack is Empty cannot Pop";
			return -1;
		}
		int element = arr[top--];
		return element;
	}
	
	int peek(){
		if (isEmpty()){
			cout<<"The Stack is Empty cannot Pop";
			return -1;
		}
		
		return arr[top];
	}
	
	bool isEmpty(){
		return top==-1;
	}
	
	bool isFull(){
		return top == capacity-1;
	}
	
};

class Queue {
	Stack s1, s2;
	
	public:
	Queue(int size): s1(size), s2(size){}
	
	void enqueue(int val){
		s1.push(val);
	}
	
	int dequeue(){
		if (s1.isEmpty() && s1.isEmpty()){
			cout<<"The Queue is Empty cannot Dequeue"<<endl;
			return -1;
		}
		
		if (s2.isEmpty()){
			while (!s1.isEmpty()){
				s2.push(s1.pop());
			}
		}
		
		return s2.pop();
	}
	
	bool isEmpty(){
		return s1.isEmpty() && s2.isEmpty();
	}
};

int main() {
    Queue q(10);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    q.enqueue(40);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl; 

    return 0;
}
