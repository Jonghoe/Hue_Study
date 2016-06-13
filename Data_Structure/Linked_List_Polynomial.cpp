#include<iostream>
using namespace std;
enum Triple{var,ptr,no};
class PolyNode{
private:
	PolyNode* Next;
	int exp;
	Triple trio;
	union{
		char vble;
		PolyNode* down;
		int coef;
	};
public:
	PolyNode(){
		Next = NULL;
		trio = var;
	}
	
};
int main(){

}