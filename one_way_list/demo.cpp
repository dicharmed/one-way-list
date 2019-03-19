#include <iostream>
#include <fstream>
#include "demo.h"
using namespace std;

Node *Head = NULL;//В начале работы в списке нет ни одного элемента, поэтому в указатель Head записывается нулевой адрес NULL.

struct Node//Объявление структуры узла.Структура являющаяся звеном списка
{
	int Num;//Значение Num будет передаваться в список.Информационное поле
	Node *Next;//Указатель на адрес следующего элемента списка
};
Node *C(int NewWord)//Создание эл-та списка.NewWord-значение первого узла
{
	Node *NewNode = new Node;//Выделение памяти под новый элемент структуры
	NewNode->Num = NewWord;//Записываем значение в структуру
	NewNode->Next = NULL;//Указываем, что изначально по следующему адресу пусто
	return NewNode;
}
Node* CreateList(Node *Head, int n)
{
	int NewWord;
	cout << "Введите число" << endl;
	cin >> NewWord;
	Node*q = C(NewWord);
	Head = q;
	for (int i = 1; i<n; i++)
	{
		cout << "Введите число" << endl;
		cin >> NewWord;//ввод значения
		Node*p = C(NewWord);
		q->Next = p;
		q = p;//ставим на p указатель q (послед.элемент)
	}
	return Head;
}
Node *Find(Node*Head, int NewWord)
{
	Node *q = Head;
	while (q && (q->Num != NewWord)) //пока нет искомого значения, проходим по списку
		q = q->Next;
	return q;
}
void DeleteList(Node*&Head)
{
	Node *q = Head;
	while (Head)//пока существует первый элемент
	{
		q = Head;
		Head = Head->Next; //переставляем указатель на след эл-т до техпор пока указатель не станет равен NULL, т.е. конец списка

		delete q; //элемент удалили
	}
}
void PrintList(Node*Head)
{

	Node *q = Head; //начало списка
	while (q != 0)
	{
		cout << q->Num << "\t";
		q = q->Next;//переход к след.эл
	}cout << endl;
}
void AddFirst(Node*&Head, Node*NewNode)//встали на первый элемент
{
	NewNode->Next = Head; //новый эл-т NewNode добавляем в начало
	Head = NewNode; //новый эл-т NewNode становится началом списка
}
void AddAfter(Node*p, Node*NewNode)
{
	NewNode->Next = p->Next; //p текущий элемент списка
	p->Next = NewNode;
}
void AddEnd(Node *Head, Node *NewNode)
{
	Node *q = Head;
	if (Head == NULL)//если список пуст/если нет последнего эл-та
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
	Node *q = Head; // указатель на первый эл-т
	if (Head == OldNode) //если первый элемент равен удаляемому
		Head = OldNode->Next; //тогда первым становится тот, что идет за удаляемым
	else
	{
		while (q&&q->Next != OldNode) //если нет, тогда ищем элемент списка и его следующий не равны удаляемому
			q = q->Next; //перемещаемся для поиска из текущего в следующий элемент

		if (q == NULL) //если конец списка
			return;

		q->Next = OldNode->Next; //q->Next - нашли удаляемый и вместо него ставим OldNode->Next, т.е тот,что идет после удаляемого
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
