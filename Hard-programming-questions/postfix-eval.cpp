#include <iostream>
#include <cctype>
using namespace std;

class Stack{
	private:
	int top;
	int* arr;
	int capacity;
	int size;
	
	public:
	Stack(int cap){
		top=-1;
		capacity = cap;
		arr = new int[capacity];
		size =0;
	}
	
	~Stack(){
		delete[] arr;
	}
	
	void push(int data){
		if(isFull()){
			cout<<"The Stack is Full, element cannot be added!";
			return;
		}
		arr[++top] = data;
		size++;
	}
	
	int pop(){
		if (isEmpty()){
			cout<<"The Stack is Empty cannot Pop";
			return -1;
		}
		int popped = arr[top--];
		size--;
		return popped;
	}
	
	int peek(){
		if (isEmpty()){
			cout<<"The Stack is Empty, no element to Peek";
			return -1;
		}
		
		int peek = arr[top];
		return peek;
	}
	
	bool isEmpty(){
		return top==-1;
	}
	
	bool isFull(){
		return top==capacity-1;
	}
};

int evaluatePostfix( string expr, int capacity){
	
	Stack st(capacity);
	
	for (int i=0; i<expr.length(); i++){
		char c = expr[i];
		
		if (c==' ') continue;
		if (isdigit(c)){
			st.push(c-'0');
		}
		
		else{
			int val2 = st.pop();
			int val1 = st.pop();
			
			switch(c){
				case '+': st.push(val1+val2); break;
				case '-': st.push(val1-val2);break;
				case '/': st.push(val1/val2);break;
				case '*': st.push(val1*val2);break;
			}
		}
	}
	return st.pop();
}

int main() {
    string expr = "231*+9-"; // Example: 2 + (3*1) - 9
    cout << "Postfix Expression: " << expr << endl;

    int result = evaluatePostfix(expr, 20);
    cout << "Result = " << result << endl;

    return 0;
}
