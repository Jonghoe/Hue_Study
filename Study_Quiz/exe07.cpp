#include<iostream>
#include<typeinfo>

using namespace std;

int main(void)
{
	int a[3] = { 1, 2, 3 };
	int(&b)[3] = a;
	b[1] = 99;
	cout << sizeof(b) << ' ';
	cout << typeid(b).name() << endl;
	for (int i = 0; i < 3; ++i)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}