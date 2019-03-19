#pragma once
struct Node;
Node *C(int NewWord);
Node* CreateList(Node *Head, int n);
Node *Find(Node*Head, int NewWord);
void DeleteList(Node*&Head);
void PrintList(Node*Head);
void AddFirst(Node*&Head, Node*NewNode);
void AddAfter(Node*p, Node*NewNode);
void AddEnd(Node *Head, Node *NewNode);
void DeleteNode(Node *&Head, Node*OldNode);
int Zapf(Node *Head, char Name[]);
int Vost(Node *&Head, char Name[]);



