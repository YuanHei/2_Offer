#include <iostream>
using namespace std;

typedef struct Node
{
	int  data;
	Node *next;
}Node, *ListLink;

void InitList(ListLink *L, int n)
{
	//头插
	Node *p;
	srand(time_t());

	*L = (Node*)malloc(sizeof(Node));
	(*L)->next = NULL;

	for (int i = 0; i < n; ++i)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

//在O(1)时间删除链表结点

void DeleteNode(ListLink *L, ListLink *cur)
{
	if (*L == NULL || *cur == NULL)
	{
		//判空
		return;
	}
	if ((*cur)->next != NULL)
	{
		//在中间
		Node *p = (*cur)->next;
		(*cur)->data = p->data;
		(*cur)->next = p->next;

		delete p;
		p = NULL;
	}
	else if ((*L) == (*cur))
	{
		//只有一个结点
		delete *cur;
		*cur = NULL;
		*L = NULL;
	}
	else
	{
		//多个结点删除尾结点
		Node *p = *L;
		while (p->next != *cur)
		{
			p = p->next;
		}
		p->next = NULL;
		delete *cur;
		*cur = NULL;
	}
}

void Show(ListLink *L)
{
	if (*L == NULL)
	{
		return;
	}
	Node *p = (*L)->next;
	while (p != NULL)
	{
		cout << p->data << "-->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

int main()
{
	ListLink L;
	InitList(&L,10);
	Show(&L);
	DeleteNode(&L, &L->next);
	Show(&L);
	return 0;
}