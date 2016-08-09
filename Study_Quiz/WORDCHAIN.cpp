#include<stdio.h>
#include<vector>
#include<string>
typedef struct node_tag Node;
typedef struct edge_tag Edge;
struct edge_tag{
	Node* start, *end;
	char word[11];
	int used;
	size_t id;
};
struct node_tag{
	char alpha;
	size_t nIn, nOut;
	std::vector<Edge*> OutE;
};
#define DIFF(x,y) ((x)-(y))*((x)-(y))
#define IS_OK(x,y) ((x)>0 ||(y)>0)
#define IS_Last(nIn,nOut) ((nIn == 1) && (nOut == 0))
#define IS_First(nIn,nOut) ((nIn == 0) && (nOut == 1))

int AnswerOrder[100];
int numWord;
Node* FindStart(Node* n, Edge* e){

	Node* Ret_V=NULL;
	Node* tmp=NULL;
	int FL=0;
	int FS=0;
	int i;
	for (i = 0; i < 26; ++i){
		//����� �Ǵ�
		if (FS == 0 && IS_First(n[i].nIn, n[i].nOut)){
			Ret_V = &n[i];
			FS = 1;
		}
		//��������� �Ǵܵ����� �̹� ������� �ִ°��
		else if (FS != 0 && IS_First(n[i].nIn, n[i].nOut))
			return NULL;

		//������ �Ǵ�
		if (FL == 0 && IS_Last(n[i].nIn, n[i].nOut)){
			FL = 1;
		}
		//���������� �Ǵܵ����� �̹� �������� �ִ°��
		else if (FL != 0 && IS_First(n[i].nIn, n[i].nOut))
			return NULL;

		//in , out ���̰� 1 �ʰ� �� ��尡 ������ �����ձ� �Ұ���
		if (DIFF(n[i].nIn, n[i].nOut) > 1)
			return NULL;
		//������� ã�����Ͽ��� ��� ��밡���� ������ ��������� ����
		if (tmp == NULL && IS_OK(n[i].nIn, n[i].nOut))
			tmp = &n[i];
	}

	return Ret_V == NULL ? tmp: Ret_V;
}

void FindNext(Node* Start, int& or){
	int i;

	for (i = 0; i < Start->nOut; ++i){
		Edge* edge = Start->OutE[i];
		Node* tNext = edge->end;
		//������� ���� edge �� ������ node�� ������ �ʴ� 
		if (edge->used ==false && !IS_Last(tNext->nIn, tNext->nOut)){
			AnswerOrder[or] = edge->id;
			edge->used = true;
			FindNext(tNext,++or);
			edge->used = false;
		}
		//������� ���� edge �̰� ������ ���� �ΰ��
		else if(edge->used == false && or == numWord -1 && IS_Last(tNext->nIn, tNext->nOut)){
			AnswerOrder[or] = edge->id;
			edge->used = true;
			return;
		}

	}
	--or;
}
int FindChain(Node* n, Edge* e){
	Node* First = FindStart(n, e);
	int i = 0;
	int or = 0;
	if (First == NULL)
		return false;
	FindNext(First, or);
	return true;
}
int main()
{
	int Case;
	scanf("%d", &Case);
	while (Case--){
		Edge Word[100];
		Node FW[26];
		int i;

		for (i = 0; i < 26; ++i){
			FW[i].alpha = 'a' + i;
			FW[i].nIn = 0;
			FW[i].nOut = 0;
		}

		scanf("%d", &numWord);
		
		for (i = 0; i < numWord; ++i){
			Node* Front,*End;
			scanf("%s", Word[i].word);
			Front = &FW[Word[i].word[0] - 'a'];
			End = &FW[Word[i].word[strlen(Word[i].word)-1] - 'a'];
			Word[i].start = Front;
			Word[i].end = End;
			Word[i].used = 0;
			Word[i].id = i;
			++(End->nIn);
			++(Front->nOut);
			Front->OutE.push_back(&Word[i]);
		}
		
		if (FindChain(FW, Word) == false)
			printf("IMPOSSIBLE");
		else
			for (i = 0; i < numWord; ++i)
				printf("%s ", Word[AnswerOrder[i]].word);
		printf("\n");
	}
	return 0;
}