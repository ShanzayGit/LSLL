#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include<iostream>
#include"ANode.h"
using namespace std;
template<typename T>
class ArrayList
{
	int head;//user list
	int avail;//list of available locations
	ANode<T> data[9];
	int getNewNode()
	{
		if (isEmpty())
		{
			exit(0);
		}
		int p = avail;
		avail = data[p].next;
		return p;
		//delete p;

	}
	void getItBack(int i)
	{

		int p = avail;
		avail = i;
		data[avail].next = p;

	}

public:
	ArrayList() :head(-1),avail(0)
	{
		data[0].next = 1;
		data[1].next = 2;
		data[2].next = 3;
		data[3].next = 4;
		data[4].next = 5;
		data[5].next = 6;
		data[6].next = 7;
		data[7].next = 8;
		data[8].next = -1;

	}
	void removeAtHead()
	{
		if (isEmpty())
		{
			return;
		}
		int p = head;
		head = data[head].next;
		getItBack(p);
	}
	void removeAtTail()
	{
		if (isEmpty())
			return;
		if (data[head].next==-1)
		{
			removeAtHead();
			return;
		}
		int p = head;
		while (data[data[p].next].next != -1)
			p = data[p].next;
		//Node<T>* q = p->next->next;
		getItBack(data[p].next);
		data[p].next = -1;
		//delete q;
	}
	void remove(T key)
	{
		if (isEmpty())
			return;
		if (data[head].info == key)
		{
			removeAtHead();
			return;
		}
		int x = data[head].next;
		int p = head;
		while (x != -1 && data[x].info != key)
		{

			p = data[p].next;
			x = data[x].next;

		}
		if (x!=-1)
		{
			int q = x;
			data[p].next = data[x].next;
			getItBack(q);
		}
	}
	void removeAfter(T key)
	{
		if (isEmpty())
			return;
		int p = head;
		int x = data[head].next;
		while (x!=-1 && data[p].info != key)
		{
			p = data[p].next;
			x = data[x].next;
		}
		if (x != -1)
		{
			int q = data[p].next;
			data[p].next = data[x].next;
			getItBack(q);
		}
	}
	void removeBefore(T key)
	{
		if (isEmpty())
		{
			return;
		}
		if (data[head].next && data[data[head].next].info == key)
		{
			removeAtHead();
			return;
		}
		int prev = head;
		int p = data[data[head].next].next;
		while (p!=-1 && data[p].info != key)
		{
			p = data[p].next;
			prev = data[prev].next;
		}
		if (p==-1)
			return;
		else
		{
			int q = data[prev].next;
			data[prev].next = p;
			getItBack( q);
		}
	}


	bool isEmpty()
	{
		if (avail == -1)
			return true;
		else return false;
	}
	void insertAtHead(T val)
	{
		if (avail == -1)
			return;
		int x = getNewNode();
		data[x].next = head;
		data[x].info = val;
		head = x;
	}
	void insertAtTail(T val)
	{
		if (avail == -1)
			return;
		if (head == -1)
		{
			int x = getNewNode();
			data[x].next = -1;
			data[x].info = val;
			head = x;
			return;
			// data[0].next = x;
		}
		int p=head;
		while (data[p].next != -1)
		{
			p = data[p].next;
		}
		int x = getNewNode();
		data[x].next = -1;
		data[x].info = val;
		data[p].next = x;

	}
	void insertAfter(T key, T val)
	{
		if (isEmpty())
			return;
		int p = head;
		while (p!=-1 && key != data[p].info)
		{
			p = data[p].next;
		}
		if (p==-1)
			return;
		int q = getNewNode();
		//Node<T>* q = new Node<T>(val);
		data[q].info = val;
		data[q].next = data[p].next;
		data[p].next = q;

	}
	void insertBefore(T key, T val)
	{
		if (isEmpty())
			return;
		if (data[head].info == key)
		{
			insertAtHead(val);
			return;
		}
		int p= head;
		while (data[p].next!=-1 && key != data[data[p].next].info)
		{
			p = data[p].next;
		}
		if (data[p].next!=-1)
		{

			int x = getNewNode();
			data[x].next = data[p].next;
			data[x].info = val;
			data[p].next = x;
		}

	}
	void print()
	{
		while (head!=-1)
		{
			cout << data[head].info;
			head = data[head].next;
		}
	}
};
#endif // !ARRAYLIST_H
