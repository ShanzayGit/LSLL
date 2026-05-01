##Overview
# LSLL (Linear Singly Linked List)

This project implements a **singly linked list in C++** from scratch.  
It demonstrates fundamental concepts of **dynamic memory allocation, pointer manipulation, and linked data structures** without relying on STL containers.


## 📂 Folder Structure
LSLL/
- LSLL.h            # Header file implementing the singly linked list
- Node.h            # Header file defining the linked list node
- LSLL.sln          # Visual Studio solution file
- main.cpp          #Example usage
- Stack.h
- String.h
- String.cpp         #Add only if using any String related work
- .gitignore
- .gitattributes

## ⚙️ Build & Run Instructions

### 🔹 On Windows (Visual Studio)
1. Open `LSLL.sln` in Visual Studio.
2. Add `LSLL.h` and `Node.h` and `Stack.h` to your project.
3. Create a `main.cpp` file with sample usage.
4. Build and run with **Ctrl+F5**.

### 🔹 On Linux/Mac (g++)
Since the implementation is header-only, you just need a driver file:

g++ main.cpp -o lsll_app
./lsll_app

## 🧩 Example Usage
  LSLL<int> list;

  list.insertAtHead(10);
  list.insertAtTail(20);
  list.insertAtTail(30);

  cout << "List after insertions: ";
  list.display();   // Expected: 10 -> 20 -> 30

  list.deleteAtHead();
  cout << "After deleting head: ";
  list.display();   // Expected: 20 -> 30

  list.deleteAtTail();
  cout << "After deleting tail: ";
  list.display();   // Expected: 20

**Expected Output:**
List after insertions: 10 -> 20 -> 30
After deleting head: 20 -> 30
After deleting tail: 20

## 🚀 Features Implemented
- Insert at head
- Insert at tail
- Insert befor/after
- Delete at head
- Delete at tail
- Delete before/after
- Display/traverse list
- Header-only design for simplicity
- Some other functions like swap/mergeSortedList/removeDuplicates/findMiddlePoint/isJoing etc.

## 📌 Future Improvements
- Add search and insert-at-position functions.
- Add exception handling for empty list operations.
- Compare performance with STL `std::list`.


## 👤 Author
Developed by **Shanzay Malik**  
  

Would you like me to also sketch out a **diagram (nodes linked with arrows)** for the README so recruiters instantly see how your LSLL works?
