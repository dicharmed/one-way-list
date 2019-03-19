#include <iostream>
#include <fstream>
#include "menu.h"
using namespace std;

const int Nq = 256; //Константный размер строки
char *FName = "title.txt"; //Путь к файлу

						   /*Вывод текста из файла на экран*/
void ReadFile()
{

	char Sw[Nq] = { "" }; //В S будут считываться строки
	ifstream in11("title.txt"); //Открыли файл для чтения
	while (!in11.eof()) //Будем читать информацию пока не дойдем до конца файла
	{
		in11.getline(Sw, Nq); //Построчное считывание информации в S
		cout << Sw << endl; //Вывод очередной строки на экран
	}
	in11.close();  //Закрыли открытый файл

}

void Menu()
{
	cout << endl;
	cout << endl;
	cout <<"-----------------------------------------------------------------------"<< endl;
	cout << endl;
	cout << "ГЛАВНОЕ МЕНЮ" << endl;
	cout << endl;
	cout << "1-ТЕОРИЯ" << endl;
	cout << "2-ДЕМОНСТРАЦИЯ" << endl;
	cout << "3-ТЕСТИРОВАНИЕ" << endl;
	cout << "0-Выход" << endl << "-> ";
	cout << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	cout << endl;
	cout << endl;
}