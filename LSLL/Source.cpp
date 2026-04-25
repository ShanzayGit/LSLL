#include<iostream>
#include"LSLL.H"
#include"Node.h"
#include"ANode.h"
#include"String.h"
#include"ArrayList.h"
using namespace std;
int main()
{
	LSLL<Node<int>*> a,b;
	Node<int> *n1=new Node<int>(10);
	Node<int>* n2=new Node<int>(20);
	//Node<int> n3(30);
	//Node<int> n4(40);
	//Node<int> n6(50);
	//Node<int> n5(60);
//	a.insertAtHead(n4);
	a.insertAtHead(n2);
//	a.insertAtHead(n5);
	//a.insertAtHead(n3);
	a.insertAtHead(n1);
	//a.insertAtHead(n6);
	a.print();
//	//a.insertAtHead("WHITE");
//	//a.insertAtHead("WHITE");
//	//a.insertAtHead("WHITE");
//	//a.insertAtHead("WHITE");
//	//a.insertAtHead("WHITE");
//	//a.insertAtHead("WHITE");
//	//a.insertAtTail("BLACK");
//	//a.insertAtTail("BLACK");
//	//a.insertAtTail("BLACK");
//	//a.insertAtTail("BLACK");
//
//	//cout << a.findMajorityColor(a, 6);
//	a.insertAtTail(1);
////	a.insertAtTail(7);
//	//a.insertAtTail(20);
//	//a.insertAtTail(5);
//	//a.insertAtTail(10);
//	a.insertAtTail(2);
//
//	a.insertAtTail(3);
//	a.insertAtTail(4);
////	a.insertAtTail(8);
//
//	//LSLL<int>c(a.mergeSortedList(b));
//	//a.insertAtTail(20);
//	//a.insertAtTail(-1);
//	//a.insertAtTail(7);
////	a.insertAtTail(12);
////	a.insertAtTail(8);
//	a.print();
//	a.reArrangeIntoABForm(a);
	//a.removeLargeAtRight(a);
	cout << "\n";
	//	a.reArrange(a);
		a.print();

	//b.insertAtTail(3);
	//b.insertAtTail(4);
	//b.insertAtTail(5);
	//b.insertAtTail(6);

	//cout<<a.isJoing(b);
	//cout << '\n';
	//b.print();
}
//int main()
//{
//	LSLL<int> a,b,c;
//	//a.insertAtTail(5);
//	//a.check();
//	//a.begin();
//	a.insertAtTail(3);
//	a.insertAtTail(2);
//	a.insertAtTail(6);
//	a.insertAtTail(5);
//	a.check();
//	//a.insertAtTail(7);
//	//a.splitList(b, c);
//	//b.print();
//	//cout << '\n';
//	//c.print();
//	//cout << '\n';
//	//a.delAlternate();
//	//a.print();
////	LSLL<int>b;
////	////b.insertAtTail(4);
////	////b.insertAtTail(7);
////	////b.insertAtTail(5);
////	////b.insertAtTail(6);
////	////b.insertAtTail(9);
////	//a.delAlternate();
////	a.print();
////	cout << '\n';
////	a.removeDuplicates();
////
////	//LSLL<int>LIST1, LIST2;
////	//a.splitList(LIST1,LIST2);
////	//LIST1.print();
////	//cout << '\n';
////	//LIST2.print();
////	//cout << '\n';
////
////	// a.createClone().print();
////	//LSLL<int>UNION = a.doUnion(b);
////	//UNION.print();
////	cout << "\n";
////	//a.insertAtTail(5);
////	//a.insertAtTail(2);
////	//a.insertAtTail(7);
////	//a.insertAtTail(8);
////
////	//b.removeBefore(4);
////	//b.print();
////	//	a.removeBefore(4);
////	//a.removeBefore(2);
////	//a.removeBefore(5);
////	//a.removeBefore(7);
////	//a.removeBefore(8);
////	//a.removeBefore(10);
////
////	
////	//a.removeAfter(4);
//////	a.removeAfter(2);
//////	a.removeAfter(5);
////	//a.removeAfter(7);
////	//a.removeAfter(8);
////	//a.removeAfter(10);
////
////	//a.remove(4);
////	//a.remove(5);
////	//a.remove(7);
//////	a.remove(8);
////	//a.remove(2);
////	//a.remove(9);
////
//////	a.insertAfter(4, 9);
//////	a.insertAfter(5, 9);
//////	a.insertAfter(2, 9);
////	//a.insertAfter(7, 9);
////	//a.insertAfter(8, 9);
////	//a.insertAfter(10, 9);
////
////
//////	b.insertBefore(4, 8);
////	//a.insertBefore(4,7);
////	//a.insertBefore(5, 7);
//////	a.insertBefore(2, 7);
////	//a.insertBefore(7, 7);
////	//a.insertBefore(8, 7);
////	//a.insertBefore(9, 7);
////	//a.selectionSortDataExchange();
////	
////	//a.swap(3,2);
////	//a.swap(3,4);
////	//a.swap(4, 5);
////	//a.swap(1, 2);
////	//a.swap(1, 5);
////	//b.print();
////	cout << '\n';
////	a.print();
//}