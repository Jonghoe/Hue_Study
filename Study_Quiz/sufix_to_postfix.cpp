#include<iostream>
#include<string>
#include<cctype>
#include"Stack.h"
using namespace std;
void Change_Suffix_to_PostFix(const string& Suf, string& Post){
	//	수식을 저장해둘 스택 생성
	Stack<char> Operation(5);
	//	Suffix 식의 값을 처음부터 끝까지 돌림
	for (auto Ch = Suf.begin(); Ch != Suf.end(); ++Ch){
		// 기호인지 아닌지 확인
		if (!isalnum(static_cast<int>(*Ch))){
			//	스택이 비어있으면 바로 스택에 푸시 아닐 경우 케이스를 나누어 확인
			if (!Operation.IsEmpty()){
				// 우선순위를 비교하여 스택에 저장 함 ( + , - , * , / 의 우선순위를 만들 방법이 없어서 손으로 함 )
				// 현재부호 * , /  이고 스택의 탑이 + , - 인경우 그냥 Push
				if ((*Ch == '*' || *Ch == '/') && (Operation.Top() == '+' || Operation.Top() == '-'))
					Operation.Push(*Ch);

				//	현재 부호 + , - 인 경우 끝까지 다 Pop후 Push
				else if (*Ch == '+' || *Ch == '-'){
					while (!Operation.IsEmpty() && Operation.Top() != '('){
						Post.push_back(Operation.Top());
						Operation.Pop();
					}
					Operation.Push(*Ch);
				}
				// 현재 부호 * , / 인 경우 스택의 탑이 + , - 이거나 끝 까지 Pop후 Push
				else if ((*Ch == '*' || *Ch == '/') && (Operation.Top() == '*' || Operation.Top() == '/')){
					while (!Operation.IsEmpty() || Operation.Top() != '('||Operation.Top()!='+'||Operation.Top()!='-'){
						Post.push_back(Operation.Top());
						Operation.Pop();
					}
					Operation.Push(*Ch);
				}
				//	현재 부호 ) 인 경우 (  까지 스택  Pop
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
			//기호가 아닌 경우 Post_Fix에 저장
			else
				Operation.Push(*Ch);
		}
		else
			Post.push_back(*Ch);
	}

	//식이 끝난후 스택에 남아있는 기호 모두 Post_Fix에 저장
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