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

	cout << a.findMajorityColor(a, 6);//WHITE
	cout << "\n"; a.print();// WHITE WHITE WHITE WHITE WHITE WHITE BLACK BLACK BLACK BLACK
	cout << "\n";

	LSLL<int>  b, c,d;
    b.insertAtTail(2);
	b.insertAtTail(3);
	b.insertAtTail(5);

	b.insertAtTail(6);
	c.insertAtTail(1);
	c.insertAtTail(5);
	c.insertAtTail(7);
	b.print(); //2 3 5 6 
	cout << '\n';
	c.print();//1 5 7
	cout << '\n';
	d=b.mergeSortedList(c);
	d.print(); //1 2 3 5 5 6 7
	d.removeDuplicates();
	cout << '\n';
	d.print(); // 1 2 3 5 6 7 
}
