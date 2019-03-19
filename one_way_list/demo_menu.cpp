#include <iostream>
#include "demo_menu.h"
using namespace std;

void DemoMenu()
{
	cout << endl;
	cout << endl;
	cout << "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-" << endl;
	cout << endl;
	cout << "МЕНЮ ДЕМОНСТРАЦИИ" << endl;
	cout << endl;
	cout << "1-Создание списка" << endl;
	cout << "2-Добавление элемента" << endl;
	cout << "3-Удаление элемента из списка (по заданному номеру)" << endl;
	cout << "4-Вывод списка на экран" << endl;
	cout << "5-Запись списка в файл" << endl;
	cout << "6-Уничтожение списка" << endl;
	cout << "7-Восстановление списка из файла" << endl;
	cout << "0-Назад" << endl << "-> ";
	cout << endl;
	cout << "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-" << endl;
	cout << endl;
	cout << endl;
}

void AddMenu()
{

	cout << endl;
	cout << "Добавление элемента в список" << endl;
	cout << endl;

	cout << "1-В начало списка" << endl;
	cout << "2-После заданного элемента" << endl;
	cout << "3-В конец списка" << endl;
	cout << "0-Назад" << endl << "-> ";
}