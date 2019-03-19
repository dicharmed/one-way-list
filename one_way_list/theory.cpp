#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "theory.h"

#define LINES 26
using namespace std;

HANDLE hConsole;
WORD saved_attributes, reversed_attributes;

void spec_print(const char *s)
{
	SetConsoleTextAttribute(hConsole, reversed_attributes);
	printf("%s", s);
	SetConsoleTextAttribute(hConsole, saved_attributes);
}
int theory_file()
{
	//LPCTSTR helpFile = "https://prog-cpp.ru/data-ols/";
	//ShellExecute(NULL, "open", helpFile, NULL, NULL, SW_SHOWNORMAL);
	//system("PAUSE");
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;
	reversed_attributes = ((saved_attributes & 0x0F) << 4) + ((saved_attributes & 0xF0) >> 4);

	int count = 0, c;//в начале функции где-нибудь


	FILE *ifp;
		int i;
	char buf[128];
		system("cls");
	if ((ifp = fopen("theory.txt", "r")) == NULL)
		return 1;
	
		i = 0;
		while (fgets(buf, sizeof(buf), ifp) != NULL) {
			fprintf(stdout, "%s", buf);
			i++;
			if (i >= LINES) {

				cout << endl;
				spec_print("q");
				printf(" Выход ");
				spec_print("SPACE");
				printf(" ");
				spec_print("n");
				printf(" Следующая страница ");
				//spec_print("ENTER");
				//printf(" Next Entry ");
				//spec_print("a");
				//printf(" Показать весь текст");
				cout << endl;
				//i = 0;
				//cout << "next" << endl;
				//_getch();

				i = 0;
				c = _getch();
				switch (c)
				{
				case ' ':
				case 'n':
				case 'N':
					count = 1;
					break;
				case 'a':
				case 'A':
					count = -1;
					break;
				case 13:
					break;
				case 'q':
				case 'Q':
					return 0;
				default:
					i = 1;
				}
			}
		}
	fclose(ifp);
	return 0;
}


