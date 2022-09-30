#include <iostream>fgfdggdfgd
#include <ctime>
using namespace std;

int level = 0; // 0 - легкий 1 - сложный
int const SIZE_FIELD = 3;
int field[SIZE_FIELD][SIZE_FIELD] = { 0 }; // 0 - пустое поле 1 - крестик 2 - нолик

void menu();
void showRules();
void startGame();
void showField();
void setPosition(int num[]);
void game();

void main() {
	setlocale(0, "rus");
	srand(time(NULL));
	cout << "Приветсвуем Вас в игре ''Крестики/нолики''!\n" << endl;
	menu();
}

void menu()
{
	int num[2];
	cout << "1) Начать игру\n2) Выбрать уровень сложности\n3) Очистить поле\n" << endl;
	cout << "Введите пункт меню: ";
	cin >> num[0];

	switch (num[0])
	{
		case 1:
		{
			system("cls");
			startGame();
			break;
		}
		case 2:
		{	
			system("cls");
			bool status = false;
			while(!status)
			{ 

				cout << "Выберите уровень сложности(учтите, что при смене уровня сложности весь прогресс сбрасывается):\n1) Легий\n2) Сложный\n3) Отмена\n" << endl;
				cout << "Введите пункт меню: ";
				cin >> num[1];
				switch (num[1])
				{
					case 1: {
						system("cls");
						status = true;
						level = 0;
						cout << "[Информация] Вы выбрали легкий уровень сложности!\n" << endl;
						menu();
						break;
					}
					case 2: {
						system("cls");
						status = true;
						level = 1;
						cout << "[Информация] Вы выбрали сложный уровень сложности!\n" << endl;
						menu();
						break;
					}
					case 3: {
						system("cls");
						status = true;
						cout << "[Информация] Вы отменили выбор уровня сложности!\n" << endl;
						menu();
						break;
					}
					default: {
						system("cls");
						cout << "[Ошибка] Выберите верный пункт меню!\n" << endl;
						break;
					}
				}
			}

			menu();
			break;
		}
		case 3:
		{
			system("cls");
			cout << "[Информация] Вы успешно очистили поле!\n" << endl;
			menu();
			break;
		}
		default:
		{
			system("cls");
			cout << "[Ошибка] Выберите верный пункт меню!\n" << endl;
			menu();
			break;
		}
	}
}

void startGame() {
	int num[3];
	cout << "Ваш уровень сложности: " << (level == 0 ? "легкий" : "сложный") << "\n" << endl;
	cout << "Желаете начать игру?\n1) Да\n2) Нет\n" << endl;
	cout << "Введите пункт меню: ";
	cin >> num[0];

	switch (num[0])
	{
		case 1:
		{
			system("cls");

			showRules();
			system("pause");

			game();
			break;
		}
		case 2:
		{
			system("cls");
			menu();
			break;
		}
		default:
		{
			system("cls");
			cout << "[Ошибка] Выберите верный пункт меню!\n" << endl;
			startGame();
			break;
		}
	}

	system("pause");
}

void showRules()
{
	cout << "Правила игры:\n" << endl;
	cout << "Вы указываете номер ряда и номер строки например: 1 и 3. Тогда у вас получится так: \n" << endl;
	cout << "00X\n000\n000\n" << endl;
}

void showField()
{
	if (!level)
	{
		/*field[2][0] = 1; 3 поле 1 ряда*/
		for (int i = 0; i < SIZE_FIELD; i++)
		{
			for (int j = 0; j < SIZE_FIELD; j++)
			{
				cout << field[j][i];
			}
			cout << endl;
		}
	}
	else
	{

	}
}

void game()
{
	int num[2];
	
	if (!level)
	{
		cout << "Вы играете за крестик(1), выберите нужный номер: "; // сначала ряд затем поле.
		cin >> num[0] >> num[1];



		if (num[0] > 3 || num[1] > 3 || num[0] < 1 || num[1] < 1)
		{
			cout << "[Ошибка] У Вас поле 3 на 3!\n" << endl;
			return game();
		}

		num[0]--;
		num[1]--;

		system("cls");
		
		setPosition(num);
	}
	else
	{

	}
}

void setPosition(int num[])
{
	if (field[num[1]][num[0]] != 0)
	{
		system("cls");
		cout << "[Ошибка] Данная позиция уже занята!\n" << endl;
		showField();
		return game();
	}

	field[num[1]][num[0]] = 1;

	if ((field[0][0] == 1 && field[1][0] == 1 && field[2][0] == 1) || 
		(field[0][1] == 1 && field[1][1] == 1 && field[2][1] == 1) ||
		(field[0][2] == 1 && field[1][2] == 1 && field[2][2] == 1) ||
		(field[0][0] == 1 && field[1][1] == 1 && field[2][2] == 1) || 
		(field[0][2] == 1 && field[1][1] == 1 && field[2][0] == 1) ||
		
		(field[0][0] == 1 && field[0][1] == 1 && field[0][2] == 1) || 
		(field[1][1] == 1 && field[1][1] == 1 && field[1][1] == 1) || 
		(field[0][2] == 1 && field[1][1] == 1 && field[2][0] == 1))
	{
		cout << "Вы победили!";
	}
	else
	{
		cout << "[Информация] Вы установили крестик на позицию ряда " << num[0] + 1 << " поля " << num[1] + 1 << "!\n" << endl;

		bool status = false;

		int num_ii[2];

		// Ход компьютера.
		while (!status)
		{
			num_ii[0] = rand() % 3;
			num_ii[1] = rand() % 3;


			if (field[num_ii[0]][num_ii[1]] == 0)
			{
				field[num_ii[0]][num_ii[1]] = 2;
				status = true;
			}
		}

		cout << "[Компьютер] Компьютер установил нолик на позицию ряда " << num_ii[1] + 1 << " поля " << num_ii[0] + 1 << "!\n" << endl;

		showField();
		game();
	}
}