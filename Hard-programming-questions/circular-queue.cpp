#include <iostream>
using namespace std;

class circularQueue{
	private:
	int front;
	int rear;
	int* arr;
	int capacity;
	
	public:
	circularQueue(int size){
		front=-1;
		rear=-1;
		capacity = size;
		arr = new int[capacity];
	}
	
	~circularQueue(){
		delete[] arr;
	}
	
	bool isEmpty(){
		return front==-1;
	}
	
	bool isFull(){
		return front==(rear+1)%capacity;
	}
	
	void enqueue(int data){
		if (isFull()){
			cout<<"The Queue is Full, cannot Enqueue";
			return;
		}
		if (isEmpty()){
			front=0;
		}
		rear = (rear + 1)%capacity;
		arr[rear] = data;
	}
	
	int dequeue(){
		if (isEmpty()){
			cout<<"The Queue is Empty cannot dequeue!";
			return -1;
		}
		int data = arr[front];
		if (front == rear){
			front=-1;
			rear=-1;
		}
		else{
			front = (front +1) % capacity;
		}
		return data;
	}
	
	int peek(){
		if (isEmpty()){
			cout<<"The Queue is empty!"<<endl;
			return -1;
		}
		return arr[front];
	}
	
	void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Elements in the queue: ";
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        } while (i != (rear + 1) % capacity);

        cout << endl;
    }
};

int main() {
    circularQueue cq(4);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display();

    cout << "Front element is: " << cq.peek() << endl;

    cout<<"The Dequeued element is: "<<cq.dequeue()<<endl;
    cq.display();

    cq.enqueue(40);
    cq.enqueue(50);
    cq.enqueue(60);
    cq.display();

    cout<<"The Dequeued element is: "<<cq.dequeue()<<endl;
    cout<<"The Dequeued element is: "<<cq.dequeue()<<endl;
    cq.display();
    
    cq.enqueue(70);
    cq.enqueue(80);
    cq.display();

    return 0;
}
		
