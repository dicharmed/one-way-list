#include <iostream>
#include <fstream>
#include "menu.h"
using namespace std;

const int Nq = 256; //����������� ������ ������
char *FName = "title.txt"; //���� � �����

						   /*����� ������ �� ����� �� �����*/
void ReadFile()
{

	char Sw[Nq] = { "" }; //� S ����� ����������� ������
	ifstream in11("title.txt"); //������� ���� ��� ������
	while (!in11.eof()) //����� ������ ���������� ���� �� ������ �� ����� �����
	{
		in11.getline(Sw, Nq); //���������� ���������� ���������� � S
		cout << Sw << endl; //����� ��������� ������ �� �����
	}
	in11.close();  //������� �������� ����

}

void Menu()
{
	cout << endl;
	cout << endl;
	cout <<"-----------------------------------------------------------------------"<< endl;
	cout << endl;
	cout << "������� ����" << endl;
	cout << endl;
	cout << "1-������" << endl;
	cout << "2-������������" << endl;
	cout << "3-������������" << endl;
	cout << "0-�����" << endl << "-> ";
	cout << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	cout << endl;
	cout << endl;
}