#include<iostream>
#include<string>
#include<cctype>
#include"Stack.h"
using namespace std;
void Change_Suffix_to_PostFix(const string& Suf, string& Post){
	//	������ �����ص� ���� ����
	Stack<char> Operation(5);
	//	Suffix ���� ���� ó������ ������ ����
	for (auto Ch = Suf.begin(); Ch != Suf.end(); ++Ch){
		// ��ȣ���� �ƴ��� Ȯ��
		if (!isalnum(static_cast<int>(*Ch))){
			//	������ ��������� �ٷ� ���ÿ� Ǫ�� �ƴ� ��� ���̽��� ������ Ȯ��
			if (!Operation.IsEmpty()){
				// �켱������ ���Ͽ� ���ÿ� ���� �� ( + , - , * , / �� �켱������ ���� ����� ��� ������ �� )
				// �����ȣ * , /  �̰� ������ ž�� + , - �ΰ�� �׳� Push
				if ((*Ch == '*' || *Ch == '/') && (Operation.Top() == '+' || Operation.Top() == '-'))
					Operation.Push(*Ch);

				//	���� ��ȣ + , - �� ��� ������ �� Pop�� Push
				else if (*Ch == '+' || *Ch == '-'){
					while (!Operation.IsEmpty() && Operation.Top() != '('){
						Post.push_back(Operation.Top());
						Operation.Pop();
					}
					Operation.Push(*Ch);
				}
				// ���� ��ȣ * , / �� ��� ������ ž�� + , - �̰ų� �� ���� Pop�� Push
				else if ((*Ch == '*' || *Ch == '/') && (Operation.Top() == '*' || Operation.Top() == '/')){
					while (!Operation.IsEmpty() || Operation.Top() != '('||Operation.Top()!='+'||Operation.Top()!='-'){
						Post.push_back(Operation.Top());
						Operation.Pop();
					}
					Operation.Push(*Ch);
				}
				//	���� ��ȣ ) �� ��� (  ���� ����  Pop
				else if (*Ch == ')'){
					while (Operation.Top() != '('){
						Post.push_back(Operation.Top());
						Operation.Pop();
					}
					Operation.Pop();
				}
				
				else
					Operation.Push(*Ch);
			}
			//��ȣ�� �ƴ� ��� Post_Fix�� ����
			else
				Operation.Push(*Ch);
		}
		else
			Post.push_back(*Ch);
	}

	//���� ������ ���ÿ� �����ִ� ��ȣ ��� Post_Fix�� ����
	for (; !Operation.IsEmpty();){
		Post.push_back(Operation.Top());
		Operation.Pop();
	}
}
int main(){
	string suffix_Exp;
	string postfix_Exp;
	cin >> suffix_Exp;
	Change_Suffix_to_PostFix(suffix_Exp, postfix_Exp);
	cout << postfix_Exp << endl;
}