#include<iostream>
#include<ctime>
#include<cstdlib>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>

HANDLE hConsole;

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
	int n = 2; //поле зрения
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


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int set_color = 15;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Console получение дискриптора окна
	SetConsoleTextAttribute(hConsole, set_color);// 0черн 1син 3гол 4крас 5фиол 6оранж 7бел 8сер 9син 10зел 11сал 12крас 
	// 13фиол 14блед-желт 15белый 


	int row = 32;
	//std::cout << "Введите размер лабиринта (квадрат рекомендовано не менее 24) ->";
	//std::cin >> row;
	//int levels = 5;
	//std::cout << "Ввкдите количесьво уровней ->";
	//std::cin >> levels;

	
	//std::cout << "Введите соотношение коридоров и стен ( рекомендовано 3 или больше) ->";
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

		//слой разведки

		int** labirint_map = new int* [row];
	
		for (int i = 0; i < row; i++) labirint_map[i] = new int[col];

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++) labirint_map[i][j] = 0;
						
		}

		//слой монстров

		int** monster_map = new int* [row];

		for (int i = 0; i < row; i++) monster_map[i] = new int[col];

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++) monster_map[i][j] = 0;

		}

		// входная группа

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
		//выход
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

		//генерация монстров

		int num_monster = 1 + row * col / 500;

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

		int player_location = labirint[player_x][player_y];

		while (true)
		{
			system("cls");
			player_view(labirint, monster_map, row, col, player_x, player_y);
			char player_move;
			if (player_location == 101)
			{
				std::cout << "5 - спустится вниз \n";
				player_move = _getch();
				if (player_move == '5') break;
			}
			std::cout << "8 - вврех 2 - вниз 4 - влево 6 - вправо\n";
			player_move = _getch();
			
			if (player_move == 'c') { system("cls"); show_labirint_chit(labirint,monster_map, row, col, player_x, player_y); player_move = _getch();}
			if (player_move == 'm') { system("cls"); show_labirint_map(labirint,labirint_map , row, col, player_x, player_y); player_move = _getch();}
			if (player_move == '8')  player_x--;
			if (player_move == '4')  player_y--;
			if (player_move == '6')  player_y++;
			if (player_move == '2')  player_x++;

			player_location = labirint[player_x][player_y]; // проверка статуса перемещения

			if (player_location == 9)
			{
				std::cout << "ТУТ СТЕНА!!!";
				if (player_move == '8')  player_x++;
				if (player_move == '4')  player_y++;
				if (player_move == '6')  player_y--;
				if (player_move == '2')  player_x--;
				system("pause");
			}
			// изменение статуса разведки
			for (int i = player_x - 2; i <= player_x + 2; i++)
				for (int j = player_y - 2; j <= player_y + 2; j++) labirint_map[i][j] = 1;
		
			// изменение движения монстров\

			for (int i = 0; i < num_monster ; i++)
			{
				for(int i=0;i<row;i++)
					for (int j = 0; j < col; j++)
					{
						if (monster_map[i][j] == 1)
						{
							while (true)
							{								
								// что бы в углы не забивались алгоритм обязательного выхода
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
								if (step > 0 and step <11)
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
									if (labirint[i][j-1] == 0 and monster_map[i][j-1] == 0)
									{
										monster_map[i][j-1] = 10;
										monster_map[i][j] = 0;
										break;
									}
								}
								if (step > 31 and step < 41)
								{
									if (labirint[i][j+1] == 0 and monster_map[i][j+1] == 0)
									{
										monster_map[i][j+1] = 10;
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
		////////////////////////////////////

		// удаляю массив
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