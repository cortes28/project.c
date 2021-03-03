#include <stdio.h>
#define ROW 3
#define COLUMN 3

//our table for tic-tac-toe
int playerMoves(char player, int status, int count);

void display();

char table[ROW][COLUMN];

//this status variable will be in use to see if tic tac toe game has been completed or not
//int myRow, myColumn;
int count;
//a counter to see if the table is maxed and no winner->Cat's game

int main()
{
  char player;
  int status = 1;
  count = 0;
  player = 'X';

  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j< 3; j++)
    {
      table[i][j] = ' ';
    }
  }
  //making the empty table


	//we are going to print the first move for player 1 here and get his move

	printf("Welcome to Tic-Tac-Toe\n");
	printf("======================\n");


  //while the game has not fully ended, we
  do
  {

    if(player == 'X')  { printf("Player 1 turn '%c'\n", player); }

    else { printf("Player 2 turn '%c'\n", player); }

    display();
    ++count;
	  status = playerMoves(player, status, count);

    if(player == 'X')  { player = 'O';}

    else { player = 'X'; }
  } while(status);

	return 0;
}

int playerMoves(char player, int status, int count)
{
int myRow, myColumn;
myRow = myColumn = 0;

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
  // display();
  //
  // printf("\nBefore insertion\n");
  //
  // // int row = myRow;
  // // int col = myColumn;
  //
	  table[myRow][myColumn] = player;

  //Check if game should be ended if player won
	for (int i = 0; i < 2 && count > 2; i++)
	{

      if(player == table[i][0] && player == table[i][1] && player == table[i][2] || player == table[0][i] && player == table[1][i] && player == table[2][i])
      {
      printf("%c Player Wins!", player);
      display();
      return 0;
      }

      if(player == table[0][0] && player == table[1][1] && player == table[2][2] || player == table[0][2] && player == table[1][1] && player == table[2][0] )
      {
      printf("%c Player Wins!", player);
      display();
      return 0;
      }
	}

  if(count == 8)
  {
    printf("\nCat's Game!\n");
    display();
    return 0;
  }

	return status;
}

void display()
{
  printf("\n");
  printf("%c|%c|%c\n", table[0][0], table[0][1], table[0][2]);
  printf("-----\n");

  printf("%c|%c|%c\n", table[1][0], table[1][1], table[1][2]);
  printf("-----\n");

  printf("%c|%c|%c\n", table[2][0], table[2][1], table[2][2]);
}
