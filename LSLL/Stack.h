#ifndef STACK_H
#define STACK_H
#include<iostream>
using namespace std;
template <typename T>
class Stack
{
	T* data;
	int capacity;
	int top;
	void reSize(int newSize)
	{
		T* temp = new T[newSize];
		for (int i = 0; i < top; i++)
			temp[i] = data[i];
		int tempTop = top;
		this->~Stack();
		data = temp;
		capacity = newSize;
		top = tempTop;
	}
public:
	Stack()
	{
		data = nullptr;
		capacity = 0;
		top = 0;
	}
	~Stack()
	{
		delete[]data;
		capacity = 0;
		top = 0;
	}
	void push(T val)
	{
		if (isFull())
			reSize(capacity == 0 ? 1 : capacity * 2);
		data[top++] = val;
	}
	T pop()
	{
		if (isEmpty())
		{
			exit(0);
		}
		T val = data[--top];
		//	cout << "data[--top]==" << val<<'\n';
		if (top > 0 && top == capacity / 4)
			reSize(capacity / 2);
		return val;
	}
	T stackTop()
	{
		if (isEmpty())
			exit(0);
		return data[top - 1];
	}
	bool isEmpty()
	{
		return top == 0;

	}
	bool isFull()
	{
		return top == capacity;
	}
	int getCapacity()
	{
		return capacity;
	}
	int getNumberOfElements()
	{
		return top;
	}
};
#endif