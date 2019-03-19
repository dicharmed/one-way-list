#include <iostream>
#include <fstream>
#include "demo.h"
using namespace std;

Node *Head = NULL;//� ������ ������ � ������ ��� �� ������ ��������, ������� � ��������� Head ������������ ������� ����� NULL.

struct Node//���������� ��������� ����.��������� ���������� ������ ������
{
	int Num;//�������� Num ����� ������������ � ������.�������������� ����
	Node *Next;//��������� �� ����� ���������� �������� ������
};
Node *C(int NewWord)//�������� ��-�� ������.NewWord-�������� ������� ����
{
	Node *NewNode = new Node;//��������� ������ ��� ����� ������� ���������
	NewNode->Num = NewWord;//���������� �������� � ���������
	NewNode->Next = NULL;//���������, ��� ���������� �� ���������� ������ �����
	return NewNode;
}
Node* CreateList(Node *Head, int n)
{
	int NewWord;
	cout << "������� �����" << endl;
	cin >> NewWord;
	Node*q = C(NewWord);
	Head = q;
	for (int i = 1; i<n; i++)
	{
		cout << "������� �����" << endl;
		cin >> NewWord;//���� ��������
		Node*p = C(NewWord);
		q->Next = p;
		q = p;//������ �� p ��������� q (������.�������)
	}
	return Head;
}
Node *Find(Node*Head, int NewWord)
{
	Node *q = Head;
	while (q && (q->Num != NewWord)) //���� ��� �������� ��������, �������� �� ������
		q = q->Next;
	return q;
}
void DeleteList(Node*&Head)
{
	Node *q = Head;
	while (Head)//���� ���������� ������ �������
	{
		q = Head;
		Head = Head->Next; //������������ ��������� �� ���� ��-� �� ������ ���� ��������� �� ������ ����� NULL, �.�. ����� ������

		delete q; //������� �������
	}
}
void PrintList(Node*Head)
{

	Node *q = Head; //������ ������
	while (q != 0)
	{
		cout << q->Num << "\t";
		q = q->Next;//������� � ����.��
	}cout << endl;
}
void AddFirst(Node*&Head, Node*NewNode)//������ �� ������ �������
{
	NewNode->Next = Head; //����� ��-� NewNode ��������� � ������
	Head = NewNode; //����� ��-� NewNode ���������� ������� ������
}
void AddAfter(Node*p, Node*NewNode)
{
	NewNode->Next = p->Next; //p ������� ������� ������
	p->Next = NewNode;
}
void AddEnd(Node *Head, Node *NewNode)
{
	Node *q = Head;
	if (Head == NULL)//���� ������ ����/���� ��� ���������� ��-��
	{
		AddFirst(Head, NewNode);
		return;
	}
	while (q->Next)
		q = q->Next;
	AddAfter(q, NewNode);
}
void DeleteNode(Node *&Head, Node*OldNode)
{
	Node *q = Head; // ��������� �� ������ ��-�
	if (Head == OldNode) //���� ������ ������� ����� ����������
		Head = OldNode->Next; //����� ������ ���������� ���, ��� ���� �� ���������
	else
	{
		while (q&&q->Next != OldNode) //���� ���, ����� ���� ������� ������ � ��� ��������� �� ����� ����������
			q = q->Next; //������������ ��� ������ �� �������� � ��������� �������

		if (q == NULL) //���� ����� ������
			return;

		q->Next = OldNode->Next; //q->Next - ����� ��������� � ������ ���� ������ OldNode->Next, �.� ���,��� ���� ����� ����������
	}
	delete OldNode;
}
int Zapf(Node *Head, char Name[])
{
	ofstream f(Name);
	if (!f) { cout << "error" << endl; return 1; }
	Node *q = Head;
	while (q != 0) {
		f << q->Num << " ";
		q = q->Next;
	}
	f.close();
	return 0;
}
int Vost(Node *&Head, char Name[])
{
	ifstream f(Name);
	if (!f) { cout << "error" << endl; return 1; }
	int NewWord;
	f >> NewWord;
	Node*q = C(NewWord);
	Head = q;
	while (f >> NewWord) {
		Node*p = C(NewWord);
		q->Next = p;
		q = p;
	}

	f.close();
	return 0;
}
