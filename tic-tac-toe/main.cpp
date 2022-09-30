#include <iostream>fgfdggdfgd
#include <ctime>
using namespace std;

int level = 0; // 0 - ������ 1 - �������
int const SIZE_FIELD = 3;
int field[SIZE_FIELD][SIZE_FIELD] = { 0 }; // 0 - ������ ���� 1 - ������� 2 - �����

void menu();
void showRules();
void startGame();
void showField();
void setPosition(int num[]);
void game();

void main() {
	setlocale(0, "rus");
	srand(time(NULL));
	cout << "����������� ��� � ���� ''��������/������''!\n" << endl;
	menu();
}

void menu()
{
	int num[2];
	cout << "1) ������ ����\n2) ������� ������� ���������\n3) �������� ����\n" << endl;
	cout << "������� ����� ����: ";
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

				cout << "�������� ������� ���������(������, ��� ��� ����� ������ ��������� ���� �������� ������������):\n1) �����\n2) �������\n3) ������\n" << endl;
				cout << "������� ����� ����: ";
				cin >> num[1];
				switch (num[1])
				{
					case 1: {
						system("cls");
						status = true;
						level = 0;
						cout << "[����������] �� ������� ������ ������� ���������!\n" << endl;
						menu();
						break;
					}
					case 2: {
						system("cls");
						status = true;
						level = 1;
						cout << "[����������] �� ������� ������� ������� ���������!\n" << endl;
						menu();
						break;
					}
					case 3: {
						system("cls");
						status = true;
						cout << "[����������] �� �������� ����� ������ ���������!\n" << endl;
						menu();
						break;
					}
					default: {
						system("cls");
						cout << "[������] �������� ������ ����� ����!\n" << endl;
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
			cout << "[����������] �� ������� �������� ����!\n" << endl;
			menu();
			break;
		}
		default:
		{
			system("cls");
			cout << "[������] �������� ������ ����� ����!\n" << endl;
			menu();
			break;
		}
	}
}

void startGame() {
	int num[3];
	cout << "��� ������� ���������: " << (level == 0 ? "������" : "�������") << "\n" << endl;
	cout << "������� ������ ����?\n1) ��\n2) ���\n" << endl;
	cout << "������� ����� ����: ";
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
			cout << "[������] �������� ������ ����� ����!\n" << endl;
			startGame();
			break;
		}
	}

	system("pause");
}

void showRules()
{
	cout << "������� ����:\n" << endl;
	cout << "�� ���������� ����� ���� � ����� ������ ��������: 1 � 3. ����� � ��� ��������� ���: \n" << endl;
	cout << "00X\n000\n000\n" << endl;
}

void showField()
{
	if (!level)
	{
		/*field[2][0] = 1; 3 ���� 1 ����*/
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
		cout << "�� ������� �� �������(1), �������� ������ �����: "; // ������� ��� ����� ����.
		cin >> num[0] >> num[1];



		if (num[0] > 3 || num[1] > 3 || num[0] < 1 || num[1] < 1)
		{
			cout << "[������] � ��� ���� 3 �� 3!\n" << endl;
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
		cout << "[������] ������ ������� ��� ������!\n" << endl;
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
		cout << "�� ��������!";
	}
	else
	{
		cout << "[����������] �� ���������� ������� �� ������� ���� " << num[0] + 1 << " ���� " << num[1] + 1 << "!\n" << endl;

		bool status = false;

		int num_ii[2];

		// ��� ����������.
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

		cout << "[���������] ��������� ��������� ����� �� ������� ���� " << num_ii[1] + 1 << " ���� " << num_ii[0] + 1 << "!\n" << endl;

		showField();
		game();
	}
}