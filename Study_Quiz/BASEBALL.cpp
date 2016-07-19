#include<stdio.h>
#include<string>
int main()
{
	std::string ar = "asdf";
	printf("%d", ar[-1]);
}
//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	ifstream ifs("input.in");
//	int Case;
//	ifs >> Case;
//	while (Case--){
//		string name[8],tmp;
//		double rate[8];
//		int Index,i,Game;
//		for (int i = 0; i < 8; ++i){
//			int win,tmp;
//			ifs >> name[i];
//			ifs >> win;
//			rate[i] += win;
//			ifs >> tmp;
//			rate[i] += tmp;
//			ifs >> tmp;
//			rate[i] += tmp;
//			rate[i] = win / rate[i];
//		}
//		ifs >> tmp;
//		for (i = 0; i < 8 && !(name[i] == tmp); ++i);
//		Index = i;
//		ifs >> Game;
//
//	}
//}