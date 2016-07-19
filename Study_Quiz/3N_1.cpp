#include<iostream>
using namespace std;

struct vector{
	int x, y;
};

vector subtract(const vector& v1, const vector& v2)
{
	vector t = { v1.x - v2.x, v1.y - v2.y };
	return t;
}

vector operator -(const vector& v1, const vector& v2){
	vector t = { v1.x - v2.x, v1.y - v2.y };
	return t;
}
vector operator - (const vector&v1)
{
	vector t = { -v1.x, -v1.y };
	return t;
}
int main()
{
	vector v1 = { 2, 4 }, v2 = { 1, 3 }, v3;
	v3 = subtract(v1, v2);
	cout << v3.x << ' ' << v3.y << endl;
	v3 = operator - (v1, v2);
	cout << v3.x << ' ' << v3.y << endl;
	v3 = v1 - v2;
	cout << v3.x << ' ' << v3.y << endl;

	v3 = operator-(v1);
	cout << v3.x << ' ' << v3.y << endl;

	v3 = -v1;
	cout << v3.x << ' ' << v3.y << endl;

	return 0;
}
