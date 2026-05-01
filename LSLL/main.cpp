#include<iostream>
#include"LSLL.H"
#include"Node.h"
#include"ANode.h"
#include"String.h"
using namespace std;
int main()
{
	LSLL<String> a;
	a.insertAtHead("WHITE");
	a.insertAtHead("WHITE");
	a.insertAtHead("WHITE");
	a.insertAtHead("WHITE");
	a.insertAtHead("WHITE");
	a.insertAtHead("WHITE");
	a.insertAtTail("BLACK");
	a.insertAtTail("BLACK");
	a.insertAtTail("BLACK");
	a.insertAtTail("BLACK");

	cout << a.findMajorityColor(a, 6);
	cout << "\n"; a.print();
	cout << "\n";

	LSLL<int>  b, c,d;
    b.insertAtTail(2);
	b.insertAtTail(3);
	b.insertAtTail(5);

	b.insertAtTail(6);
	c.insertAtTail(1);
	c.insertAtTail(5);
	c.insertAtTail(7);
	b.print();
	cout << '\n';
	c.print();
	cout << '\n';
	d=b.mergeSortedList(c);
	d.print();
	d.removeDuplicates();
	cout << '\n';
	d.print();
}