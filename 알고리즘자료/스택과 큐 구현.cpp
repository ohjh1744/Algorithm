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
			cout << "�� ��"<< endl;
			return;
		}
		arr[++top] = i;
	}
	
	void Pop(){
		if(top == -1){
			cout << "��� ����"<< endl;
			return;
		}
		top--;
	}
	
	int Top(){
		if(top == -1){
			cout << "��� ����"<< endl;
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
	int capacity;// �ִ� �뷮 
public:
	// 5���� ������ ���ϸ� ������ ��ĭ�� ��� ���ϹǷ� ��ĭ���� ���÷���. 
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
		//���� ������ ��ĭ��������� 
		if((rear+1) % capacity == front){
			cout << "����" << endl;
			return; 
		}
		
		arr[rear] = i;
		rear = (rear+1) % capacity;
	}
	
	void Pop(){
		// ����ִٸ� 
		if(rear == front){
			cout << "����ִ�" << endl;
			return;
		}
		front = (front+1) % capacity;
	}
	
	int Top(){
		// ����ִٸ� 
		if(rear == front){
			cout << "����ִ�" << endl;
			return -1;
		}
	
		return arr[front];
	}
	
	bool IsEmpty(){
		if(rear == front){
			cout << "����ִ�" << endl;
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
