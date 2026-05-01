#ifndef LSLL_H
#define LSLL_H
#include"NODE.h"
#include"Stack.h"
#include"String.h"
#include<iostream>
using namespace std;
template<typename T>
class LSLL
{
	Node<T>* head;
	void reverse(Node<T>* p)
	{
		if (p == nullptr)
			return;
		reverse(p->next);
		cout << p->info << '\t';
	}
	void reverseListRecer(Node<T>* p, Node<T>* q, Node<T>* r)
	{
		if (r == nullptr)
		{
			q->next = p;
			head = q;
			return;
		}
		q->next = p;
		p = q;
		q = r;
		r = r->next;
		reverseListRecer(p, q, r);
	}
public:
	class iterator
	{
		Node<T>* curr;
	public:
		iterator():curr(nullptr)
		{}
		iterator( Node<T>*Head):curr(Head)
		{}
		bool operator !=(iterator other)
		{
			return this->curr != other.curr;
		}
		typename iterator& operator ++()
		{
			if (curr)
			{
				curr = curr->next;
				return *this;
			}
			else
				exit(0);
		}
		typename iterator operator++(int)
		{
			Node<T>* temp = curr;
			curr = curr->next;
			return temp;
		}
		T& operator *()
		{
			if (curr == nullptr)
				exit(0);
			return curr->info;
		}
		
	};
	iterator begin()
	{
		return iterator(head);
	}
	iterator end()
	{
		return iterator(nullptr);
	}

	void print()
	{
		if (isEmpty())
			return;
		Node<T>* p = head;
		while (p->next)
		{
			cout << p->info<<"\t";
			p = p->next;
		}
		cout << p->info;

	}
	LSLL():head(nullptr)
	{}
	~LSLL()
	{
		while (head)
			removeAtHead();
	}
	bool isEmpty()
	{
		return head == nullptr;
	}
	void insertAtHead(T val)
	{
		Node<T>* p = new Node<T>(val);
		p->next = head;
		head = p;
	}
	void insertAtTail(T val)
	{
		if (isEmpty())
		{
			head = new Node<T>(val);
			return;
		}
		Node<T>* p = head;
		while (p->next != nullptr)
			p=p->next;
		p->next = new Node<T>(val);
	}
	void insertAfter(T key, T val)
	{
		if (isEmpty())
			return;
		Node<T>* p = head;
		while (p && key != p->info)
		{
			p = p->next;
		}
		if (!p)
			return;
		Node<T>* q = new Node<T>(val);
		q->next = p->next;
		p->next = q;
	}
	void insertBefore(T key, T val)
	{
		if (isEmpty())
			return;
		if (head->info == key)
		{
			insertAtHead(val);
			return;
		}
		Node<T>* p = head;
		while (p->next && key != p->next->info)
		{
			p = p->next;
		}
		if (p->next)
		{
			Node<T>* x = new Node<T>(val);
			x->next = p->next;
			p->next = x;
		}
	}
	void remove(T key)
	{
		if (isEmpty())
			return;
		if (head->info == key)
		{
			removeAtHead();
			return;
		}
		Node<T>* x = head->next;
		Node<T>* p = head;
		while (x!=nullptr && x->info != key)
		{

			p = p->next;
			x = x->next;

		}
		if (x)
		{
			Node<T>* q = x;
			p->next = x->next;
			delete q;
		}

	}
	void removeAtHead()
	{
		if (isEmpty())
		{
			return;
		}
		Node<T>* p = head;
		head = head->next;
		delete p;
	}
	void removeBefore(T key)
	{
		if (isEmpty())
		{
			return;
		}
		if (head->next && head->next->info == key)
		{
			removeAtHead();
			return;
		}
		Node<T>* prev = head;
		Node<T>* p = head->next->next;
		while (p && p->info != key)
		{
			p = p->next;
			prev = prev->next;
		}
		if (!p)
			return;
		else
		{
			Node<T>* q=prev->next;
			prev->next = p;
			delete q;
			return;
		}
	}
	void removeAtTail()
	{
		if (isEmpty())
			return;
		if (head->next == nullptr)
		{
			removeAtHead();
			return;
		}
		Node<T>* p = head;
		while (p->next->next != nullptr)
			p=p->next;
		//Node<T>* q = p->next->next;
		p->next= nullptr;
		return;
		//delete q;
	}
	void removeAfter(T key)
	{
		if (isEmpty())
			return;
		Node<T>* p = head;
		Node<T>* x = head->next;
		while (x&& p->info != key)
		{
			p = p->next;
			x = x->next;
		}
		if (x)
		{
			Node<T>*q= p->next;
			p->next = x->next;
			delete q;
			return;
		}
		else
		{
			return;
		}
	}
	void selectionSortDataExchange()
	{
		if (isEmpty())
			return;
		Node<T>* q = head;
		while(q->next)
		{
			Node<T>* min = q;

			Node<T>* p = q;

			while (p->next)
			{
				if (p->next->info < min->info)
					min = p->next;
				p = p->next;
			}
			
			T t = min->info;
			min->info = q->info;
			q->info = t;
			q = q->next;
		}
	}
	T findMiddlePoint(LSLL<T>& a)
	{
		if (head == nullptr)
			exit(0);
		if (head->next == nullptr)
			return head->info;
		Node<T>* p = head;
		Node<T>* q = head;
		while (q->next != nullptr)
		{
			if (q->next->next != nullptr)
			{
				p = p->next;
				q = q->next->next;
			}
			else
				q = q->next;
		}
		return p->info;
	}
	void reArrange(LSLL<T>& A)
	{
		if (head->next == nullptr || head == nullptr||head->next->next==nullptr)
			return;
		Node<T>* p = head;
		while (p->next)
		{
			Node<T>* e = p;
			while (e->next->next)//e to 2nd last element
			{
				e = e->next;
			}
			if (e == p)//if even number of elements
				return;
			Node<T>* temp = p->next;//storing p->next to move p to next element
			e->next->next = p->next;
			p->next = e->next;
			e->next = nullptr;
			p = temp;
		}
	}
	void removeLargeAtRight(LSLL<T>& a)
	{
		if (head == nullptr || head->next == nullptr)
			return;
		Node<T>* p = head;

		if (p->next->info > p->info)
		{
			removeAtHead();
			p = head;
		}
		while (p->next)
		{
			Node<T>* temp = p->next;
			if (p->info < p->next->info)
			{
				remove(p->info);
				p = temp;
			}
			else
			    p = p->next;
		}
	}
	void reArrangeIntoABForm(LSLL<T>& l)
	{
		if (isEmpty()||head->next==nullptr)
			return;
		Node<T>* p = head;
		int a = 1;
		while (p)
		{
			if (p->info > p->next->info)
			{
				swap(a, a + 1);
				a++;
			}
			else
			{
				a++;
				p = p->next;
			}
			if (p->next)
			{
				if (p->info < p->next->info)
				{
					swap(a, a + 1);
					a++;
				}
				else
				{
					p = p->next;
					a++;
				}
			}
			if (p->next == nullptr)//if last 2 get swapped or p is at last element 
				p = p->next;
		}
	}
	String findMajorityColor(LSLL<T>& a, int N)
	{
		Node<T>* p = head;
		Stack<String> white, black;
		while (p)
		{
			if ((p->info == "WHITE") == 0)
				white.push(p->info);
			else
				black.push(p->info);
			p = p->next;
		}
		if (white.getNumberOfElements() == black.getNumberOfElements())
			return "equal";
		if (white.getNumberOfElements() > black.getNumberOfElements())
			return "white";
		else 
			return "black";
	}
	void Join(LSLL<T>&l2,Node<T>*s)
	{
		Node<T>* p = l2.head;
		while (p->next)
		{
			p = p->next;
		}
		p->next = s;
	}
	bool isJoing(LSLL<T>& list2)
	{
		Node<T>* r = head->next->next->next;
		Join(list2, r);

		LSLL::iterator i(this->begin());
		LSLL::iterator j(list2.begin());
		while (i!=this->end())
		{
			LSLL::iterator j(list2.begin());
			while (j!=list2.end())
			{
				if (j != i)
					j++;
				else
				{
					cout << *j<<"\n";
					return true;
				}
			}
			i++;
		}
		return false;
	}
	void selectionSortLinkExchange()
	{
		if (isEmpty())
			return;
		Node<T>* q = head;
		int i = 1;
		while (q->next)
		{
			Node<T>* min = q;
			Node<T>* p = q;
			int minNo = i;
			int maxNo = i;
			int count = i + 1;

			while (p->next)
			{
				if (p->next->info < min->info)
				{
					maxNo = count;
					min = p->next;
				}
				p = p->next;
				count++;
			}
			q = q->next;
			swap(minNo, maxNo);
			i++;

		}

	}

	LSLL(const LSLL<T>& X) :LSLL()
	{
		if (X.head == nullptr)
			return;
		Node<T>* xh = X.head;//head of X
		insertAtHead(xh->info);
		Node<T>* orH = head;//head of calling object
		xh=xh->next;
		while (xh)
		{
			orH->next = new Node<T>(xh->info);
			xh = xh->next;
			orH = orH->next;
		}
	}
	LSLL<T>& operator =(const LSLL<T>& x)
	{
		if (this == &x)
			return *this;
		this->~LSLL();
		Node<T>* xh = x.head;//head of X
		insertAtHead(xh->info);
		Node<T>* orH = head;//head of calling object
		xh = xh->next;
		while (xh)
		{
			orH->next = new Node<T>(xh->info);
			xh = xh->next;
			orH = orH->next;
		}
		return *this;
	}
	LSLL<T> doUnion(LSLL<T>& list2)
	{
		if (list2.head == nullptr)
			return *this;
		else if (head == nullptr)
			return list2;
		else
		{
			LSLL<T> un=list2;
			Node<T>* uh = head;
			while (uh)
			{
				Node<T>* l2h = un.head;
				while (l2h && uh->info != l2h->info)
				{
					l2h = l2h->next;
				}
				if (l2h==nullptr)//no match found
				{
					un.insertAtHead(uh->info);
				}
				uh = uh->next;
			}
			return un;
		}
	}
	bool isEqual(LSLL<T>& list2)
	{
		if (list2.head == nullptr && this->head == nullptr)
			return true;
		else if (list2.head != nullptr && this->head == nullptr)
			return false;
		else if (list2.head == nullptr && this->head != nullptr)
			return false;
		else
		{
			Node<T>* temp1 = head;
			Node<T>* l2 = list2.head;
			while (temp1 && l2)
			{
				//cout << "1";
				Node<T>* l1 = head;
				while (l1 && l1->info != l2->info)
					l1 = l1->next;
				if (l1 == nullptr)
					return false;
				else
				{
					l2 = l2->next;
					temp1 = temp1->next;
				}
			}
			if (!temp1 && !l2)
				return true;
			else
				return false;
		}

	}
	LSLL<T> createClone()
	{
		if (head == nullptr)
		{
			return *this;
		}
		LSLL x;
		Node<T>* h = head;//head 
		x.insertAtHead(h->info);
		Node<T>* orH = x.head;//head of returning object clone
		h = h->next;
		while (h)
		{
			orH->next = new Node<T>(h->info);
			h = h->next;
			orH = orH->next;
		}
		return x;
	}
	void delAlternate()
	{
		if (head == nullptr)
			return;
		Node<T>* p = head;
		while (p->next!=nullptr)
		{
			Node<T>* temp = p->next->next;
			Node<T>* q = p->next;
			p->next = temp;
			delete q;
			if(temp!=nullptr)
			   p = temp;
		}
	}
	void splitList(LSLL<T>& list1, LSLL<T>& list2)
	{
		if (head == nullptr)
			return;
		Node<T>* p = head;
		Node<T>* q = head;
		while (q->next!=nullptr)
		{
			//p = p->next;
			if (q->next->next != nullptr)
			{
				p = p->next;
				q = q->next->next;
			}
			else
				q = q->next;
		}
		list1.head = head;
		list2.head = p->next;
		p->next = nullptr;
		head = nullptr;
	}
	void removeDuplicates()
	{
		if (head == nullptr||head->next==nullptr)
			return;
		Node<T>* p = head;//keeping track of value to being checked
		Node<T>* x = head;//previous index when duplicate found
		while (p)
		{
			T val = p->info;//value we are checking
			x = p;
			//p = p->next;//entry from which we will start checking
			if (!p)
				return;
			Node<T>* temp = p->next;//temp to move across the list
			while (temp && val != temp->info)
			{
				x = x->next;
				temp = temp->next;
			}
			if (temp != nullptr)
			{
				Node<T>* q = temp;
				x->next = temp->next;
				delete q;
			}
			else
				p = p->next;
		}
	}
	LSLL<T> mergeSortedList(LSLL<T>& list2)
	{
		if (isEmpty())
			return list2;
		else if (list2.isEmpty())
			return *this;
		LSLL<T> res;
		Node<T>* x = res.head;//start of resultant list
		Node<T>* t = head;//start of this calling list
		Node<T>* l = list2.head;//start of list2
		while (t && l)
		{
			if (t->info < l->info)
			{
				if (!x)
				{
					res.insertAtHead(t->info);
					x = res.head;
				}
				else
				{
					Node<T>* n = new Node<T>(t->info);
					x->next = n;
					x = n;
				}
				t = t->next;

			}
			else if (t->info >= l->info)
			{
				if (!x)
				{
					res.insertAtHead(l->info);
					x = res.head;
				}
				else
				{
					Node<T>* n = new Node<T>(l->info);
					x->next = n;
					x = n;
				}
				l = l->next;

			}
		}
		while (l)
		{
			Node<T>* n = new Node<T>(l->info);
			x->next = n;
			x = n;
			l = l->next;
		}
		while (t)
		{
			Node<T>* n = new Node<T>(t->info);
			x->next = n;
			x = n;
			t = t->next;
		}
		return res;

	}
	void reversePrintRec()
	{
		reverse(head);
		//if (!head)
		//	return;
		//T val = head->info;
		//head = head->next;
		//reversePrintRec();
		//cout << val << '\t';
	}
	void reversePrint()
	{
		Stack<T> s;
		if (!head)
			return;
		Node<T>* p = head;
		while (p)
		{
			s.push(p->info);
			p = p->next;
		}
		while (!s.isEmpty())
			cout << s.pop()<<'\t';
	}
	void reverseList()
	{
		if (isEmpty() || head->next == nullptr)
			return;
		Node<T>* p = head;
		Node<T>* q = head->next;
		Node<T>* r = head->next->next;
		p->next = nullptr;
		while (r)
		{
			q->next = p;
			p = q;
			q = r;
			r = r->next;
		}
		q->next = p;
		head = q;
	}
	void reverseListRec()
	{
		if (isEmpty() || head->next == nullptr)
			return;
		Node<T>* p = head;
		Node<T>* q = head->next;
		Node<T>* r = head->next->next;
		p->next = nullptr;

		reverseListRecer(p, q, r);
	}
	
	void swap(int n1, int n2)
	{
		if (isEmpty())
			return ;
		if (n1 == n2)
			return;
		Node<T>* P = head;
		int Tcount = 0;
		while (P)
		{
			Tcount++;
			P = P->next;
		}
		if (n1 > Tcount || n2 > Tcount)
			return ;
		int first, second;
		if (n1 < n2)
		{
			first = n1;
			second = n2;
		}
		else
		{
			first = n2;
			second = n1;
		}
		Node<T>* p = head;
		Node<T>* q = head;
		int i = 1;
		while (i < first - 1)
		{
			p = p->next;
			i++;
		}
		i = 1;
		while (i < second - 1)
		{
			q = q->next;
			i++;
		}
		if (first == 1&& second!=2 )//swap first with any
		{
			Node<T>* A = p->next;
			Node<T>* B = q->next->next;
			Node<T>* C = q->next;
			head = C;
			q->next->next = A;
			q->next = p;
			p->next = B;
		}
		else if (n1 - n2 == 1 || n1 - n2 == -1)//swapping two consecutives
		{
			if (first != 1)
			{
				Node<T>* A = p->next;
				Node<T>* B = q->next;
				Node<T>* C = q->next->next;
				p->next = B;
				q->next->next = A;
				q->next = C;
			}
			else if (first == 1)
			{
				Node<T>* A = p->next;
				Node < T > *B = q->next->next;
				head = A;
				q->next->next = p;
				p->next = B;

			}
		}
		else
		{
			Node<T>* A = p->next;
			Node<T>* B = p->next->next;
			p->next->next = q->next->next;
			p->next = q->next;
			q->next->next = B;
			q->next = A;
		}
	}
};
#endif