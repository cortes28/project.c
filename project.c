#include <stdio.h>
#define ROW 3
#define COLUMN 3

//our table for tic-tac-toe
int playerMoves(char player, int status, int count);

//display tic-tac-toe table
void display();

//our 2D array table for our game
char table[ROW][COLUMN];

//a counter to see if the table is maxed and no winner->Cat's game
int count;

int main()
{
  //status set to 1 and count to 0 as the game will start
  char player;
  int status = 1;
  count = 0;
  player = 'X';

  //making the empty table
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j< 3; j++)
    {
      table[i][j] = ' ';
    }
  }

  printf("Welcome to Tic-Tac-Toe\n");
  printf("======================\n");

  //while the game has not ended (game ends if status equals 0)
  do
  {
    //print the player who is next
    if(player == 'X')  { printf("Player 1 turn '%c'\n", player); }

    else { printf("Player 2 turn '%c'\n", player); }
    //display and count how many moves have been done and go into playerMoves
    //function
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
  //our variables for getting the values of where the player wants to
  //draw an 'X' or 'O'
  int myRow, myColumn;
  myRow = myColumn = 0;

  //get values while the cell is available and the number is not out of bounds
  printf("Which Row would you like?\n");
  scanf("%d", &myRow);

  printf("Which Column would you like?\n");
  scanf("%d", &myColumn);

  while (table[myRow][myColumn] == 'X' || table[myRow][myColumn] == 'O' ||
         myRow > 2 || myRow < 0 || myColumn > 2 || myColumn < 0)
	{
		printf("Illegal Move, enter a valid move\n");

		printf("Which Row would you like?\n");
		scanf("%d", &myRow);

		printf("Which Column would you like?\n");
		scanf("%d", &myColumn);
	}

  //plug into the table once the value is valid
  table[myRow][myColumn] = player;

  //Check if game should be ended if player won
  //checks if player won across a column or row
	for (int i = 0; i < 2 && count > 2; i++)
	{
    if(player == table[i][0] && player == table[i][1] && player == table[i][2] ||
       player == table[0][i] && player == table[1][i] && player == table[2][i])
    {
    printf("%c Player Wins!", player);
    display();
    return 0;
    }
  }
  //checks if player won diagonally
  if(player == table[0][0] && player == table[1][1] && player == table[2][2] ||
     player == table[0][2] && player == table[1][1] && player == table[2][0] )
  {
 	 printf("%c Player Wins!", player);
 	 display();
  	return 0;
  }
  //if the counter has reached 8 meaning all moves have been done
  //we end the game.
  if(count == 9)
  {
    printf("\nCat's Game!\n");
    display();
    return 0;
  }
  //returns status while the game continues
return status;
}
//our function to display our table of tic-tac-toe
void display()
{
  printf("\n");
  printf("%c|%c|%c\n", table[0][0], table[0][1], table[0][2]);
  printf("-----\n");

  printf("%c|%c|%c\n", table[1][0], table[1][1], table[1][2]);
  printf("-----\n");

  printf("%c|%c|%c\n", table[2][0], table[2][1], table[2][2]);
  printf("\n");
}
