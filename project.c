#include <stdio.h>
#define ROW 2
#define COLUMN 2



//our table for tic-tac-toe
int playerMoves(char table[ROW][COLUMN], char player, int myRow, int myColumn, int status);

void display();

char table[ROW][COLUMN] = {};

//this status variable will be in use to see if tic tac toe game has been completed or not
char player;
int myRow, myColumn;

int main()
{
  int status = 1;
  myRow = myColumn = 0;
	//we are going to print the first move for player 1 here and get his move
	printf("Welcome to Tic-Tac-Toe\n");
	printf("======================\n");
	printf("Player 1 turn 'X'\n");

  while(status)
  {
    display();
	  status = playerMoves(table, 'X', myRow, myColumn, status);
  }

	return 0;
}

int playerMoves(char table[ROW][COLUMN], char player, int myRow, int myColumn, int status)
{

//	while (table[myRow][myColumn] == 'X' || table[myRow][myColumn] == 'O')
  printf("Which Row would you like?\n");
  scanf("%d", &myRow);

  printf("Which Column would you like?\n");
  scanf("%d", &myColumn);

  while (table[myRow][myColumn] == 'X' || table[myRow][myColumn] == 'O' || myRow > 2 || myColumn > 2)
	{
		printf("Illegal Move, enter a valid move\n");

		printf("Which Row would you like?\n");
		scanf("%d", &myRow);

		printf("Which Column would you like?\n");
		scanf("%d", &myColumn);
	}

	table[myRow][myColumn] = player;

	//if(((table[0][0] == player) && (table[0][1] == player) && table[0][2]))
	//lets actually create a function do to a true or false if the game has been completed

	for (int i = 0; i < 2; i++)
	{
		if(table[i][0] == table[i][1] && table[i][0] == table[i][2] || table[0][i] == table[1][i] && table[0][i] == table[2][i])
    {
      printf("%c Player Wins!", player);
      display();
      return 0;
    }

    if(table[0][0] == table [1][1] && table [0][0] || table[0][2] == table[1][1] && table[0][2] == table[2][0])
    {
      printf("%c Player Wins!", player);
      display();
      return 0;
    }
	}

  if(player == 'X')  { player = 'O';}

  else {player = 'X'; }


	return status;
}

void display()
{
  int row, column;

	// for (row = 0; row < ROW + 1; row++)
	// {
	// 	for (column = 0; column < COLUMN + 1; column++)
	// 	{
	// 		printf("%c", table[row][column]);
  //
	// 		if (column < 2) { printf("|"); }
  // 	}
  // 	printf("\n------\n");
  // }

  printf("\n%c|%c|%c\n", table[0][0], table[0][1], table[0][2]);
  printf("----------\n");

  printf("%c|%c|%c\n", table[1][0], table[1][1], table[1][2]);
  printf("----------\n");

  printf("%c|%c|%c\n", table[2][0], table[2][1], table[2][2]);

}