#include <iostream>
#include "menu.h"
#include "theory.h"
#include "demo_menu.h"
#include "demo.h"
#include "testirovanie.h"

using namespace std;

//const int NotUsed = system("color F0");
//F--background; 0-text

int main()
{
	setlocale(0, "");
	int t, d, m, n, NewWord;
	ReadFile();   //Функция читает строки из файла и выводит их на экран
	Node *Head = NULL;//В начале работы в списке нет ни одного элемента, поэтому в указатель Head записывается нулевой адрес NULL.
	do {
		Menu();
		cin >> t;
		switch (t)
		{
		case 1:theory_file(); break;
		case 2:
			do {
				DemoMenu();				
				cin >> d;
				cout << endl;
				switch (d)
				{
				case 1: cout << "Введите количество чисел" << endl;
					cin >> n;
					Head = CreateList(Head, n); 
					//print
					cout << endl;
					cout <<"-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-"<<endl;
					cout <<"Список: "<<endl;
					cout << endl;
					if (Head)PrintList(Head);
					else cout << "Список пустой!!!" << endl;
					cout << endl;
					cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
					break;
				case 2:
					if (Head)
					{
						do {
							AddMenu();
							cin >> m;
							switch (m)
							{
							case 1://вставка элемента в начало списка
								if (Head)//добавить э-т в список
								{
									cout << "Введите число" << endl;
									cin >> NewWord;
									Node*q = C(NewWord);
									AddFirst(Head, q);
									//print
									cout << endl;
									cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
									cout << "Список: " << endl;
									cout << endl;
									if (Head)PrintList(Head);
									else cout << "Список пустой!!!" << endl;
									cout << endl;
									cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
								}
								else cout << "Список пустой!!!" << endl;
								break;

							case 2:
								if (Head)//добавить э-т в список
								{
									int NewWord, vel;
									cout << "Введите новый элемент списка" << endl;
									cin >> NewWord;
									cout << "Введите элемент списка, после которого нужно вставить новый элемент" << endl;
									cin >> vel;
									Node*q = Find(Head, vel);
									Node*u = C(NewWord);
									if (q)AddAfter(q, u);
									else cout << "Такого элемента нет в списке!" << endl;
									//print
									cout << endl;
									cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
									cout << "Список: " << endl;
									cout << endl;
									if (Head)PrintList(Head);
									else cout << "Список пустой!!!" << endl;
									cout << endl;
									cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
								}
								else cout << "Список пустой!!!" << endl;
								break;

							case 3:
								if (Head)//добавить э-т в список
								{
									int NewWord;
									cout << "Введите число" << endl;
									cin >> NewWord;
									Node*q = C(NewWord);
									AddEnd(Head, q);
									//print
									cout << endl;
									cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
									cout << "Список: " << endl;
									cout << endl;
									if (Head)PrintList(Head);
									else cout << "Список пустой!!!" << endl;
									cout << endl;
									cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
								}
								else cout << "Список пустой!!!" << endl;
								break;
							default:break;
							}
						} while (m);

					}
					else cout << "Список пустой!!!" << endl;
					break;
				case 3:
					if (Head)
					{
						//print
						cout << endl;
						cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
						cout << "Список: " << endl;
						cout << endl;
						if (Head)PrintList(Head);
						else cout << "Список пустой!!!" << endl;
						cout << endl;
						cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
						//--
						cout << "Введите число" << endl;
						cin >> NewWord;
						Node*q = Find(Head, NewWord);
						if (q)DeleteNode(Head, q);
						else cout << "Такого элемента нет в списке!" << endl;
						//print
						cout << endl;
						cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
						cout << "Список: " << endl;
						cout << endl;
						if (Head)PrintList(Head);
						else cout << "Список пустой!!!" << endl;
						cout << endl;
						cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
					}
					else cout << "Список пустой!!!" << endl;
					break;
				case 4:
					//print
					cout << endl;
					cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
					cout << "Список: " << endl;
					cout << endl;
					if (Head)PrintList(Head);
					else cout << "Список пустой!!!" << endl;
					cout << endl;
					cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
					break;
				case 5:
					if (Head)
					{
						Zapf(Head, "Name.txt");
						cout << "Файл записан" << endl;
					}
					else cout << "Список пустой!!!" << endl;
					break;

				case 6:
					if (Head)
					{
						DeleteList(Head);
						cout << "Cписок уничтожен" << endl;
					}
					else cout << "Список пустой!!!" << endl;
					break;

				case 7:
					if (Head)
					{
						cout << "Список удаляется..." << endl;
						DeleteList(Head);
					};
					Vost(Head, "Name.txt");
					if (Head)cout << "Cписок восстановлен из файла" << endl;
					break;

				default:break;
				}
			} while (d);
			break;

		case 3:students_data(); read_test_questions(); break;
		default:break;
		};
	} while (t);
	return 0;
}