#include<iostream>
using namespace std;
class A{
private:
	int B;
public:
	void print(){ cout << B << endl; }
};
class B{
public:
	int a;
	void print(){ cout << a << endl; }
};

int main(){
	A a;
	B b;
	a.print();
	b.print();
}