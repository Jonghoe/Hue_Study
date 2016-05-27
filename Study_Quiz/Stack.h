//
// Name: Joowon Byun
// Date: May 14th 2016
//
// code for Fundamentals of Data Structuers in C++ 3.2
// ADT class Stack as a container class
//

#ifndef STACK_H
#define STACK_H

template <class T>
class Stack {
public:
    Stack(int);
    ~Stack();

    int Size() const;       // Num of elements in Stack
    bool IsEmpty() const;   // return true if no element
    T& Top() const;         // return a element in Stack
    void Push(const T&);
    void Pop();
private:
	void ChangeCapacity(int K); // Change capacity Capacity *= K 
    T *stack;       // an array for stack elements
    int capacity;   // size of array
    int top;        // place of the top
};

template <class T>
     Stack<T>::Stack(int stackCapacity): capacity( stackCapacity) {
    if (capacity<1)
        throw "Stack must be >0";
    stack = new T [capacity];
    top = -1; // no element
}

template <class T>
     Stack<T>::~Stack() {
    delete []stack;
}

template <class T>
int  Stack<T>::Size() const {
    return top+1;
}

template <class T>
bool Stack<T>::IsEmpty() const {
    return top==-1;
}

template <class T>
T&   Stack<T>::Top() const {
    if (IsEmpty())
        throw "Stack is empty";
    return stack[top];
}
template< class T>
void Stack<T>::ChangeCapacity(int k){
	T* Temp = new T[capacity*k];
	for (int i = 0; i < capacity; i++)
		Temp[i] = stack[i];
	capacity *= k;
	delete stack;
	stack = Temp;
}
template <class T>
void Stack<T>::Push(const T& x) {
    if (capacity==top+1)
        this->ChangeCapacity(2);
    stack[++top]=x;
	
}

template <class T>
void Stack<T>::Pop() {
    if (IsEmpty())
        throw "Stack is empty, cannot delete";
    stack[top--].~T(); // T should be dynamically allocated??
}

#endif
