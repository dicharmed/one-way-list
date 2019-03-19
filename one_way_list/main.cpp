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
	ReadFile();   //������� ������ ������ �� ����� � ������� �� �� �����
	Node *Head = NULL;//� ������ ������ � ������ ��� �� ������ ��������, ������� � ��������� Head ������������ ������� ����� NULL.
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
				case 1: cout << "������� ���������� �����" << endl;
					cin >> n;
					Head = CreateList(Head, n); 
					//print
					cout << endl;
					cout <<"-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-"<<endl;
					cout <<"������: "<<endl;
					cout << endl;
					if (Head)PrintList(Head);
					else cout << "������ ������!!!" << endl;
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
							case 1://������� �������� � ������ ������
								if (Head)//�������� �-� � ������
								{
									cout << "������� �����" << endl;
									cin >> NewWord;
									Node*q = C(NewWord);
									AddFirst(Head, q);
									//print
									cout << endl;
									cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
									cout << "������: " << endl;
									cout << endl;
									if (Head)PrintList(Head);
									else cout << "������ ������!!!" << endl;
									cout << endl;
									cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
								}
								else cout << "������ ������!!!" << endl;
								break;

							case 2:
								if (Head)//�������� �-� � ������
								{
									int NewWord, vel;
									cout << "������� ����� ������� ������" << endl;
									cin >> NewWord;
									cout << "������� ������� ������, ����� �������� ����� �������� ����� �������" << endl;
									cin >> vel;
									Node*q = Find(Head, vel);
									Node*u = C(NewWord);
									if (q)AddAfter(q, u);
									else cout << "������ �������� ��� � ������!" << endl;
									//print
									cout << endl;
									cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
									cout << "������: " << endl;
									cout << endl;
									if (Head)PrintList(Head);
									else cout << "������ ������!!!" << endl;
									cout << endl;
									cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
								}
								else cout << "������ ������!!!" << endl;
								break;

							case 3:
								if (Head)//�������� �-� � ������
								{
									int NewWord;
									cout << "������� �����" << endl;
									cin >> NewWord;
									Node*q = C(NewWord);
									AddEnd(Head, q);
									//print
									cout << endl;
									cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
									cout << "������: " << endl;
									cout << endl;
									if (Head)PrintList(Head);
									else cout << "������ ������!!!" << endl;
									cout << endl;
									cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
								}
								else cout << "������ ������!!!" << endl;
								break;
							default:break;
							}
						} while (m);

					}
					else cout << "������ ������!!!" << endl;
					break;
				case 3:
					if (Head)
					{
						//print
						cout << endl;
						cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
						cout << "������: " << endl;
						cout << endl;
						if (Head)PrintList(Head);
						else cout << "������ ������!!!" << endl;
						cout << endl;
						cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
						//--
						cout << "������� �����" << endl;
						cin >> NewWord;
						Node*q = Find(Head, NewWord);
						if (q)DeleteNode(Head, q);
						else cout << "������ �������� ��� � ������!" << endl;
						//print
						cout << endl;
						cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
						cout << "������: " << endl;
						cout << endl;
						if (Head)PrintList(Head);
						else cout << "������ ������!!!" << endl;
						cout << endl;
						cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
					}
					else cout << "������ ������!!!" << endl;
					break;
				case 4:
					//print
					cout << endl;
					cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
					cout << "������: " << endl;
					cout << endl;
					if (Head)PrintList(Head);
					else cout << "������ ������!!!" << endl;
					cout << endl;
					cout << "-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%--%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%-" << endl;
					break;
				case 5:
					if (Head)
					{
						Zapf(Head, "Name.txt");
						cout << "���� �������" << endl;
					}
					else cout << "������ ������!!!" << endl;
					break;

				case 6:
					if (Head)
					{
						DeleteList(Head);
						cout << "C����� ���������" << endl;
					}
					else cout << "������ ������!!!" << endl;
					break;

				case 7:
					if (Head)
					{
						cout << "������ ���������..." << endl;
						DeleteList(Head);
					};
					Vost(Head, "Name.txt");
					if (Head)cout << "C����� ������������ �� �����" << endl;
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