#include <iostream>
#include <fstream>
#include "testirovanie.h"
using namespace std;

const int N = 256; //Константный размер строки
char *ame = "Test.txt"; //Путь к файлу
char *me = "users_answers.txt"; //Путь к файлу
int w;
const int sum_questions = 15;//общее число вопросов

void students_data()
{
	char surname[100], name[100], group[100];
	cout << endl;
	cout << "ТЕСТИРОВАНИЕ НА ТЕМУ: <<Односвязные списки>>" << endl;
	cout << "В тесте " << sum_questions << " вопросов. На каждый вопрос только один вариант ответа." << endl;
	cout << endl;
	cout << "Фамилия: "; cin >> surname; cout << endl;
	cout << "Имя: "; cin >> name; cout << endl;
	cout << "Группа: "; cin >> group; cout << endl; cout << endl;
};
//write answers to aray
int answers_into_massiv(int n, int Array[], char Name[])
{
	ifstream f(Name);
	if (!f) { cout << "Error"; return 1; }
	for (int i = 0; i<n; i++)
		Array[i] = 0;
	for (int i = 0; i<n && (!f.eof()); i++)
		f >> Array[i];
	f.close();
	return 0;
};
int marks(int count_right_ans_pr, int mark_pr, int right_answers_pr[], int users_answers_pr[], double koef_right_ans_pr, int rrr)
{

	count_right_ans_pr = 0;
	koef_right_ans_pr = 0;//коэффициент правильных ответов

	for (rrr = 0; rrr < sum_questions; rrr++)
	{
		if (right_answers_pr[rrr] == users_answers_pr[rrr]) count_right_ans_pr++;	//количество правильных ответов	
	}
	cout << "Количество верных ответов: " << count_right_ans_pr << " из " << sum_questions << endl;
	//вычисляем процентную составляющую
	koef_right_ans_pr = double(100) / double(sum_questions);//процентная составляющая на 1 вопрос
	koef_right_ans_pr *= count_right_ans_pr;
	cout << "Вы ответили на: " << koef_right_ans_pr << "%" << endl;
	//оценивание
	if (koef_right_ans_pr <= 50) mark_pr = 2;
	else if (koef_right_ans_pr <= 80 && koef_right_ans_pr > 50) mark_pr = 3;
	else if (koef_right_ans_pr <= 95 && koef_right_ans_pr > 80) mark_pr = 4;
	else if (koef_right_ans_pr <= 100 && koef_right_ans_pr > 95) mark_pr = 5;
	cout << "Ваша оценка: " << mark_pr << endl;
	cout << endl;
	return 0;
};
/*Вывод текста из файла на экран*/
void read_test_questions()
{
	char S[N] = { "" }; //В S будут считываться строки
	ifstream in1(ame); //Открыли файл для чтения
	int el_users_answers_proto = 0;
	int answer_proto, users_answers_proto[sum_questions];
	int z = 0;
	while (!in1.eof()) //Будем читать информацию пока не дойдем до конца файла
	{
		in1.getline(S, N); //Построчное считывание информации в S
		cout << S << endl; //Вывод очередной строки на экран
		z++;
		if (z == 7)
		{
			z = 0;
			do
			{
				cout << "Введите ответ: ";
				cin >> answer_proto;//ввод пользователем ответа
				cout << endl;
				if (answer_proto < 5 && answer_proto>0)
				{
					users_answers_proto[el_users_answers_proto] = answer_proto;//записываем его ответ в массив
					el_users_answers_proto++;
				};

			} while (answer_proto > 4);
		}

	}
	in1.close();  //Закрыли открытый файл

				  //оценивание
	const int Nmax = 200;
	int right_answers[Nmax];
	answers_into_massiv(sum_questions, right_answers, "right_answers.txt");
	//проверка ответов
	int count_right_ans = 0;
	int mark = 0;
	int koef_right_ans = 0;//коэффициент правильных ответов
	int rrr = 0;
	marks(count_right_ans, mark, right_answers, users_answers_proto, koef_right_ans, rrr);
	//правильные ответы

	cout << endl;
	cout << "Проверьте себя!Правильные ответы:" << endl;
	int q = 1;
	for (int y = 0; y <sum_questions; y++)
	{

		cout << q << ")  " << right_answers[y] << endl;
		q++;
	};


};