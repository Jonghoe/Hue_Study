#include <iostream>
#include <list>
#include <string>
#include<stdarg.h>
#define SIZE 50
#define MAX 10
using namespace std;
typedef list<int> RangeList;
typedef int Point[MAX];
template <class T>
class index{
//	index ���� �޾� ���� ����
//  Point �κ��� �ִ� MAX �������� �ӽ÷� ����
//	mvValue �� �ε��� Value��
private:
	Point mvP;
	T mvValue;
	int mvDegree;
public:
	index(){ mvValue = 0; mvDegree = 0; }
//	Set,Get �Լ���
	void mSetDegree(int D){ mvDegree = D; }
	void mSetmvValue(T V){ mvValue = V; }
	void mSetV(T V){ mvValue = V; }
	int mGetmvDegree(){ return mvDegree; }
	Point* mGetmvP(){ return &mvP; }
	T mGetV(){ return mvValue; }
//
	bool mIs_Same(index<T>& I){
		for (int i = 0; i < this->mvDegree&&i < I.mGetmvDegree(); i++)
			if (mvP[i] != *(*(I.mGetmvP())+i))
				return false;
		return true;
	}
	void mPrint_Info(){
		for (int i = 0; i < mvDegree; i++)
			cout << mvP[i] << "  ";
		cout << " : " << mvValue<<" " ;
	}
};
template<class T>
class GeneralArray{
// RangeList�� ���� ũ�⸸ŭ Index �����Ҵ����� ����

private:
	index<T>* mvId;
	T mvInit_V;
	int mvSize;
	int mvDegree;
public:
	GeneralArray(){	}
	GeneralArray(int j, RangeList list, T initValue = 0){
		int* Degree_V = new int[j];
		int I = j - 1;
		auto iter = list.end();
		mvDegree = j;
		mvSize = 1;
		mvInit_V = initValue;
//	I �� ���� �� ���� �����Ͽ� ���� ���� ����
		do{
			iter--;
			if (I == mvDegree - 1)
				Degree_V[I] = (*iter);
			else if (I==j-2)
				Degree_V[I] = Degree_V[I + 1];
			else 
				Degree_V[I] = (*iter)*Degree_V[I + 1];
			mvSize *= (*iter);
			I--;
		} while (iter != list.begin());
//	mvSize ��ŭ �ε��� ���� �Ҵ�
		mvId = new index<T>[mvSize];
		for (int i = 0; i < mvSize; i++){
// index�� Degree�� ����
			mvId[i].mSetDegree(mvDegree);
			mvId[i].mSetmvValue(initValue);
			int Point_V = i;
			for (int i2 = 0; i2 < mvDegree-1; i2++){
				*(*(mvId[i].mGetmvP())+i2) = Point_V /Degree_V[i2];
				Point_V %=Degree_V[i2];
			}
			*(*(mvId[i].mGetmvP()) + mvDegree - 1) = i % Degree_V[mvDegree - 1];
		}

	}

	// index �� �����ڴ��� Ȯ��
	bool mExistIndex(index<T>& I){
		int i = 0;
		if (this->mvDegree != I.mGetmvDegree())
			return false;
		for (i = 0; i < mvSize; i++)
			if (I.mIs_Same(mvId[i]))
				return true;
		return false;
	}
	// index �ּҸ� ��ȯ
	index<T>* mFind(index<T>& I){
		for (int i =  0; i < mvSize; i++)
			if (I.mIs_Same(mvId[i]))
				return &mvId[i];
		return NULL;
	}
	// index I ��ġ�� �ε����� �ִٸ� ���� ��ȯ
	T Retrieve(index<T>& I){
		if (!mExistIndex(I))
			return 0;
		return mFind(I)->mGetV();
	}
	//	index I ��ġ�� �ε����� �ִٸ� ���� ����
	void Store(index<T>& I, T x){
		if (!mExistIndex(I))
			return;
		mFind(I)->mSetV(x);
	}
	void Print_All_Index(){
		cout << mvDegree << endl;

		for (int i = 0; i < mvSize; i++){
			if (i % 5 == 0)
				cout << endl;
			(mvId+i)->mPrint_Info();
			
		}
	}
};

int main(){
	GeneralArray<float>* GA;
	index<float> sample;
	RangeList list;
	int Degree=2;
	int P[2] = { 4, 4 };
	sample.mSetDegree(2);
	**(sample.mGetmvP() + 0) = P[0];
	*(*(sample.mGetmvP()) + 1) = P[1];
	list.push_back(5);
	list.push_back(5);
	GA = new GeneralArray<float>(Degree,list,0);
	GA->Store(sample, 10);
	GA->Print_All_Index();
	cout << GA->Retrieve(sample);
}
