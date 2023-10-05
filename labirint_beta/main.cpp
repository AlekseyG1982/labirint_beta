#include<iostream>
#include<ctime>
#include<cstdlib>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>

HANDLE hConsole;

struct Monster
{
	int str = 5;
	int agl = 5;
	int end = 5;
	int armor = 0;
	int hp = end * 10;


};

void show_labirint(int* map[],int*monster[], int row, int col)
{
	std::cout << "\n";
	for (int i = 0; i < row; i++)
	{
		char symbol;
		std::cout << "                         ";
		for (int j = 0; j < col; j++)
		{
			if (map[i][j] == 0)
			{
				SetConsoleTextAttribute(hConsole, 15);
				symbol = ' ';
			}
			if (map[i][j] == 1)
			{
				SetConsoleTextAttribute(hConsole, 8);
				symbol = '#';
			}
			if (map[i][j] == 9)
			{
				SetConsoleTextAttribute(hConsole, 15);
				symbol = '#';
			}
			if (map[i][j] == 10)
			{
				SetConsoleTextAttribute(hConsole, 4);
				symbol = '^';
			}
			if (map[i][j] == 101)
			{
				SetConsoleTextAttribute(hConsole, 10);
				symbol = 'o';
			}
			
			if(monster[i][j] ==1)
			{
				SetConsoleTextAttribute(hConsole, 4);
				symbol = '*';
			}

			std::cout << symbol << " ";
		}
		std::cout << "\n";
	}
	SetConsoleTextAttribute(hConsole, 15);
}

void show_labirint_chit(int* map[],int *monster[], int row, int col, int x, int y)
{

	std::cout << "\n";
	for (int i = 0; i < row; i++)
	{
		char symbol;
		std::cout << "                         ";
		for (int j = 0; j < col; j++)
		{
			if (map[i][j] == 0)
			{
				SetConsoleTextAttribute(hConsole, 15);
				symbol = ' ';
			}
			if (map[i][j] == 1)
			{
				SetConsoleTextAttribute(hConsole, 8);
				symbol = '#';
			}
			if (map[i][j] == 9)
			{
				SetConsoleTextAttribute(hConsole, 15);
				symbol = '#';
			}
			if (map[i][j] == 10)
			{
				SetConsoleTextAttribute(hConsole, 4);
				symbol = '^';
			}
			if (map[i][j] == 101)
			{
				SetConsoleTextAttribute(hConsole, 10);
				symbol = 'o';
			}
			if (i == x and j == y)
			{
				SetConsoleTextAttribute(hConsole, 4);
				symbol = 'X';
			}
			if (monster[i][j] == 1)
			{
				SetConsoleTextAttribute(hConsole, 4);
				symbol = '*';
			}

			std::cout << symbol << " ";
		}
		std::cout << "\n";
	}
	SetConsoleTextAttribute(hConsole, 15);
}

void show_labirint_map(int* map[], int* map_real[], int row, int col, int x, int y)
{
	int n = 12; 
	int x_min = x - n;
	int x_max = x + n;
	int y_min = y - n;
	int y_max = y + n;

	if (x_min <= 0) x_min = 1;
	if (x_max > row - 3) x_max = row - 3;
	if (y_min <= 0) y_min = 1;
	if (y_max > col - 3) y_max = col - 3;
	std::cout << "\n";
	for (int i = x_min; i <= x_max; i++)
	{
		char symbol;
		std::cout << "                         ";
		for (int j = y_min; j <= y + n; j++)
		{
				if (map[i][j] == 0)
				{
					if (map_real[i][j] == 1)
					{
						SetConsoleTextAttribute(hConsole, 15);
						symbol = ' ';
					}
					else
					{
						SetConsoleTextAttribute(hConsole, 15);
						symbol = ' ';

					}


				}
				
				if (map[i][j] == 9)
				{
					if (map_real[i][j] == 1)
						{
						SetConsoleTextAttribute(hConsole, 15);
						symbol = '#';
						}
						else
						{
						SetConsoleTextAttribute(hConsole, 15);
						symbol = ' ';

						}
					
					
				}
				if (map[i][j] == 10)
				{
					if (map_real[i][j] == 1)
					{
						SetConsoleTextAttribute(hConsole, 4);
						symbol = '^';
						
					}
					else
					{
						SetConsoleTextAttribute(hConsole, 15);
						symbol = ' ';

					}
					
				}
				if (map[i][j] == 101)
				{
					if (map_real[i][j] == 1)
					{
						SetConsoleTextAttribute(hConsole, 10);
						symbol = 'o';

					}
					else
					{
						SetConsoleTextAttribute(hConsole, 15);
						symbol = ' ';

					}
					
				}
				if (i == x and j == y)
				{
					SetConsoleTextAttribute(hConsole, 4);
					symbol = 'X';
				}

				std::cout << symbol << " ";
			}
			std::cout << "\n";
		}
		SetConsoleTextAttribute(hConsole, 15);
	
}

void player_view(int* map[],int * monster[], int row, int col, int x, int y)
{
	int n = 2; //���� ������
	std::cout << "\n\n\n\n";
	for (int i = x - n; i <= x + n; i++)
	{
		char symbol;
		std::cout << "                         ";
		for (int j = y - n; j <= y + n; j++)
		{
			if (map[i][j] == 0)
			{
				SetConsoleTextAttribute(hConsole, 15);
				symbol = ' ';
			}

			if (map[i][j] == 9)
			{
				SetConsoleTextAttribute(hConsole, 15);
				symbol = '#';
			}
			if (map[i][j] == 10)
			{
				SetConsoleTextAttribute(hConsole, 4);
				symbol = '^';
			}
			if (map[i][j] == 101)
			{
				SetConsoleTextAttribute(hConsole, 10);
				symbol = 'o';
			}
			if (i == x and j == y)
			{
				SetConsoleTextAttribute(hConsole, 10);
				symbol = '*';
			}
			if (monster[i][j] == 1)
			{
				SetConsoleTextAttribute(hConsole, 4);
				symbol = '*';
			}

			std::cout << symbol << " ";
		}
		std::cout << "\n";
	}

	SetConsoleTextAttribute(hConsole, 15);
}

int plr_hit(int plr_str,int plr_agl, int plr_atk, int enemy_agl, int ememy_armor=0)
{
	int hit = 0;
	int n = 3;
	if (enemy_agl > plr_agl - n + rand() % (2 * n)) std::cout << "You are loose! " << "\n";
	else
	{
		std::cout << "You are hit! " << "\n";
		hit = plr_str - n + rand() % (2 * n) + plr_atk - ememy_armor;
		if (hit < 0) hit = 0;
		std::cout << "Damage - " <<hit<< "\n";
	}
	
	return hit;
	
}
int enm_hit(int enm_str, int enm_agl,  int plr_agl, int plr_armor,int enm_atk=0 )
{
	int hit = 0;
	int n = 3;
	if (plr_agl > enm_agl - n + rand() % (2 * n)) std::cout << "You are lucky gay! " << "\n";
	else
	{
		std::cout << "A - A - Aaaa ! " << "\n";
		hit = enm_str - n + rand() % (2 * n) + enm_atk - plr_armor;
		if (hit < 0) hit = 0;
		std::cout << "Damage - " << hit << "\n";
	}

	return hit;
	
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int set_color = 15;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Console ��������� ����������� ����
	SetConsoleTextAttribute(hConsole, set_color);// 0���� 1��� 3��� 4���� 5���� 6����� 7��� 8��� 9��� 10��� 11��� 12���� 
	// 13���� 14����-���� 15����� 


	int row = 32;
	//std::cout << "������� ������ ��������� (������� ������������� �� ����� 24) ->";
	//std::cin >> row;
	//int levels = 5;
	//std::cout << "������� ���������� ������� ->";
	//std::cin >> levels;

	
	//std::cout << "������� ����������� ��������� � ���� ( ������������� 3 ��� ������) ->";
	//std::cin >> n;
	
	int n = 3; //+(row%100);
	while (true)
	{

		int col = row;
		int** labirint = new int* [row];
		int size = row * col / n;

		for (int i = 0; i < row; i++) labirint[i] = new int[col];
		
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (i <= 1) labirint[i][j] = 9;
				else if (i >= row - 3) labirint[i][j] = 9;
				else if (j <= 1) labirint[i][j] = 9;
				else if (j >= col - 3) labirint[i][j] = 9;
				else labirint[i][j] = 1;
			}
		}

		//���� ��������

		int** labirint_map = new int* [row];
	
		for (int i = 0; i < row; i++) labirint_map[i] = new int[col];

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++) labirint_map[i][j] = 0;
						
		}

		//���� ��������

		int** monster_map = new int* [row];

		for (int i = 0; i < row; i++) monster_map[i] = new int[col];

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++) monster_map[i][j] = 0;

		}

		// ������� ������

		int enter_x = 4 + rand() % (row - 8);
		int enter_y = 4 + rand() % (col - 8);
		labirint[enter_x][enter_y] = 10;

		labirint[enter_x + 1][enter_y + 1] = 9;
		labirint[enter_x - 1][enter_y - 1] = 9;
		labirint[enter_x + 1][enter_y] = 9;
		labirint[enter_x - 1][enter_y] = 9;
		labirint[enter_x][enter_y - 1] = 9;
		labirint[enter_x][enter_y + 1] = 9;
		labirint[enter_x + 1][enter_y - 1] = 9;
		labirint[enter_x - 1][enter_y + 1] = 9;

		int first_cor = rand() % 3;
		if (first_cor == 0)  labirint[enter_x + 1][enter_y] = 0;
		if (first_cor == 1)  labirint[enter_x - 1][enter_y] = 0;
		if (first_cor == 2)  labirint[enter_x][enter_y + 1] = 0;
		if (first_cor == 3)  labirint[enter_x][enter_y - 1] = 0;

		for (int i = 0; i < size; i++)
		{
			while (true)
			{
				int cor_x = 1 + rand() % (row - 2);
				int cor_y = 1 + rand() % (col - 2);
				if (labirint[cor_x][cor_y] == 1)
				{
					if (labirint[cor_x + 1][cor_y] == 0)
					{
						labirint[cor_x][cor_y] = 0;
						break;
					}
					if (labirint[cor_x - 1][cor_y] == 0)
					{

						labirint[cor_x][cor_y] = 0;
						break;
					}
					if (labirint[cor_x][cor_y + 1] == 0)
					{
						labirint[cor_x][cor_y] = 0;
						break;
					}
					if (labirint[cor_x][cor_y - 1] == 0)
					{
						labirint[cor_x][cor_y] = 0;
						break;
					}

				}
			}
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					if (labirint[i][j] == 1)
					{
						int count = 0;
						if (labirint[i + 1][j] == 0) count++;
						if (labirint[i - 1][j] == 0) count++;
						if (labirint[i][j + 1] == 0) count++;
						if (labirint[i][j - 1] == 0) count++;
						if (labirint[i + 1][j - 1] == 0) count++;
						if (labirint[i - 1][j + 1] == 0) count++;
						if (labirint[i + 1][j + 1] == 0) count++;
						if (labirint[i - 1][j - 1] == 0) count++;
						if (count > 2) labirint[i][j] = 9;
					}
				}
			}


		}
		//�����
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (labirint[i][j] == 1) labirint[i][j] = 9;
			}
		}
		while (true)
		{
			int exit_x = 4 + rand() % (row - 8);
			int exit_y = 4 + rand() % (col - 8);


			if (labirint[exit_x][exit_y] == 0)
			{
				int count = 0;
				if (labirint[exit_x + 1][exit_y + 1] == 9) count++;
				if (labirint[exit_x - 1][exit_y - 1] == 9) count++;
				if (labirint[exit_x + 1][exit_y] == 9) count++;
				if (labirint[exit_x - 1][exit_y] == 9) count++;
				if (labirint[exit_x][exit_y + 1] == 9) count++;
				if (labirint[exit_x][exit_y - 1] == 9) count++;
				if (labirint[exit_x + 1][exit_y - 1] == 9) count++;
				if (labirint[exit_x - 1][exit_y + 1] == 9) count++;

				if (count > 6) { labirint[exit_x][exit_y] = 101; break; }

			}

		}
		////////////////////////////////////////

		//��������� ��������

		int num_monster = 3 + row * col / 500;

		for (int i = 0; i < num_monster; i++)
		{

			while (true)
			{
				int monster_x = 4 + rand() % (row - 8);
				int monster_y = 4 + rand() % (col - 8);

				if (labirint[monster_x][monster_y] == 0 and monster_map[monster_x][monster_y] == 0)
				{
					monster_map[monster_x][monster_y] = 1;
					break;
				}
			}
		}

		show_labirint(labirint, monster_map, row, col);
		system("pause");

		int player_x = enter_x;
		int player_y = enter_y;

		int plr_str = 5;
		int plr_agl = 5;
		int plr_end = 5;
		int plr_int = 5;
		int plr_hp_max = plr_end * 10;
		int plr_hp = 50;
		int plr_cargo_max = (plr_str + plr_end) * 2;
		int plr_cargo=0;
		int plr_mana_max = plr_int * 2;
		int plr_mana=0;
		int plr_coin = 0;
		int plr_atk = 1;
		int plr_armor = 1;
		int plr_xp = 0;


		int player_location = labirint[player_x][player_y];
		int Day = 1;

		while(true)
		{
			int move_p=12;

			while (true)
			{
				system("cls");
				player_view(labirint, monster_map, row, col, player_x, player_y);
				std::cout << "Days - " << Day << " Hours left - " << move_p << "\n";
				char player_move;
				if (player_location == 101)
				{
					std::cout << "5 - ��������� ���� \n";
					player_move = _getch();
					if (player_move == '5') break;
				}
				if (monster_map[player_x][player_y] == 1)
				{
					std::cout << "5 - Figth \n";
					player_move = _getch();

					if (player_move == '5')
					{
						
						int monster_str = 3 + (-1 + rand() % 3);
						int monster_agl = 3 + (-1 + rand() % 3);
						int monster_end = 3 + (-1 + rand() % 3);
						int monster_hp = monster_end * 10;
						
						std::cout << "Monster STR = " << monster_str << "  Monster AGL = " << monster_agl<<"  Monster END = " << monster_end<< "\n";
						system("pause");

						while (monster_hp >0)
						{
							std::cout << "You HP = " << plr_hp << "  Enemy HP = " << monster_hp << "\n";
							system("pause");
							monster_hp -= plr_hit(plr_atk,plr_agl,plr_atk,monster_agl);
							plr_hp -= enm_hit(monster_str, monster_agl, plr_agl, plr_armor);

						}
						monster_map[player_x][player_y] = 0;
					}

				}
				std::cout << "8 - ����� 2 - ���� 4 - ����� 6 - ������\n";
				player_move = _getch();

				if (player_move == 'c') { system("cls"); show_labirint_chit(labirint, monster_map, row, col, player_x, player_y); player_move = _getch(); }
				if (player_move == 'm') { system("cls"); show_labirint_map(labirint, labirint_map, row, col, player_x, player_y); player_move = _getch(); }
				if (player_move == '8')  player_x--;
				if (player_move == '4')  player_y--;
				if (player_move == '6')  player_y++;
				if (player_move == '2')  player_x++;

				player_location = labirint[player_x][player_y]; // �������� ������� �����������

				if (player_location == 9)
				{
					std::cout << "��� �����!!!";
					if (player_move == '8')  player_x++;
					if (player_move == '4')  player_y++;
					if (player_move == '6')  player_y--;
					if (player_move == '2')  player_x--;
					system("pause");
					break;
				}
				move_p--;
				// ��������� ������� ��������
				for (int i = player_x - 2; i <= player_x + 2; i++)
					for (int j = player_y - 2; j <= player_y + 2; j++) labirint_map[i][j] = 1;

				// ��������� �������� ��������

				if (move_p % 2 == 0)
				{
					for (int i = 0; i < num_monster; i++)
					{
						for (int i = 0; i < row; i++)
							for (int j = 0; j < col; j++)
							{
								if (monster_map[i][j] == 1)
								{
									while (true)
									{
										// ��� �� � ���� �� ���������� �������� ������������� ������
										/*
										int count = 0;
										int step;
										if (labirint[i + 1][j] == 0) count++;
										if (labirint[i - 1][j] == 0) count++;
										if (labirint[i][j+1] == 0) count++;
										if (labirint[i][j-1] == 0) count++;

										if (count > 3) step = 1 + rand() % 41;
										else step = rand() % 5;
										*/
										int step = 1 + rand() % 41;
										//if (step == 0) { monster_map[i][j] = 10; break; }
										if (step > 0 and step < 11)
										{
											if (labirint[i - 1][j] == 0 and monster_map[i - 1][j] == 0)
											{
												monster_map[i - 1][j] = 10;
												monster_map[i][j] = 0;
												break;
											}
										}
										if (step > 11 and step < 21)
										{
											if (labirint[i + 1][j] == 0 and monster_map[i + 1][j] == 0)
											{
												monster_map[i + 1][j] = 10;
												monster_map[i][j] = 0;
												break;
											}
										}
										if (step > 21 and step < 31)
										{
											if (labirint[i][j - 1] == 0 and monster_map[i][j - 1] == 0)
											{
												monster_map[i][j - 1] = 10;
												monster_map[i][j] = 0;
												break;
											}
										}
										if (step > 31 and step < 41)
										{
											if (labirint[i][j + 1] == 0 and monster_map[i][j + 1] == 0)
											{
												monster_map[i][j + 1] = 10;
												monster_map[i][j] = 0;
												break;
											}
										}
									}
								}
							}
					}
					for (int i = 0; i < row; i++)
						for (int j = 0; j < col; j++)
							if (monster_map[i][j] == 10) monster_map[i][j] = 1;
				}
				else
					if (move_p < 1)
					{
						Day++;
						break;
					}


			}
			if (player_location == 101) break;
		}
		////////////////////////////////////

		// ������ ������
		for (int i = 0; i < col; i++) delete[] labirint[i];
		delete[] labirint;

		for (int i = 0; i < col; i++) delete[] labirint_map[i];
		delete[] labirint_map;

		for (int i = 0; i < col; i++) delete[] monster_map[i];
		delete[] monster_map;
				
		row += 2;
	}
	return 0;
}