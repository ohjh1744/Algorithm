#include <iostream>
using namespace std;

class Stack{
private :
	int* arr;
	int top;
	int capacity;
public:
	Stack(int size){
		arr = new int[size];
		capacity = size;
		top = -1;
	}
	~Stack(){
		delete[] arr;
	}
	
	void Push(int i){
		if(top == capacity -1){
			cout << "꽉 참"<< endl;
			return;
		}
		arr[++top] = i;
	}
	
	void Pop(){
		if(top == -1){
			cout << "비어 있음"<< endl;
			return;
		}
		top--;
	}
	
	int Top(){
		if(top == -1){
			cout << "비어 있음"<< endl;
		    return -1;
		}
		return arr[top];
	}
	
	bool IsEmpty(){
		if(top == -1){
			return true;
		}
		else{
			return false;
		}
	}	
};

class Queue{
private:
	int *arr;
	int front;
	int rear;
	int capacity;// 최대 용량 
public:
	// 5개의 공간을 원하면 실제로 한칸은 사용 못하므로 한칸공간 더늘려줌. 
	Queue(int n){
		arr = new int[n+1];
		capacity = n+1;
		front = 0;
		rear = 0;
	}
	~Queue(){
		delete[] arr;
 	}
	
	void Push(int i){
		//꽉참 실제론 한칸비어있지만 
		if((rear+1) % capacity == front){
			cout << "꽉참" << endl;
			return; 
		}
		
		arr[rear] = i;
		rear = (rear+1) % capacity;
	}
	
	void Pop(){
		// 비어있다면 
		if(rear == front){
			cout << "비어있다" << endl;
			return;
		}
		front = (front+1) % capacity;
	}
	
	int Top(){
		// 비어있다면 
		if(rear == front){
			cout << "비어있다" << endl;
			return -1;
		}
	
		return arr[front];
	}
	
	bool IsEmpty(){
		if(rear == front){
			cout << "비어있다" << endl;
			return -1;
		}
	}
};

int main(){
	
	Queue queue(5);
	queue.Push(1);
	queue.Push(2);
	queue.Pop();
	queue.Pop();
	queue.Push(3);
	queue.Push(4);
	queue.Push(2);
	queue.Push(5);
	queue.Push(6);
	queue.Push(5);
	cout << queue.Top() << endl;
}
