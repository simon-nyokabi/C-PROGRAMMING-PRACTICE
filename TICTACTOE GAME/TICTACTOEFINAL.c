#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//GLOBAL VARIABLES
char board[3][3];
char const PLAYER='X';
char const COMPUTER='O';

//FUNCTION PROTOTYPES
void refreshBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();

void refreshBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j]=' ';
        }        
    }    
}

void printBoard()
{
    for (int i = 0; i < 3; i++)
    {
        printf("\n");
        printf(" %c | %c | %c ",board[i][0],board[i][1],board[i][2]);
        if (i<2)
        {
            printf("\n---|---|---");
        }                
    }        
}

int checkFreeSpaces()
{
    int freeSpaces=0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j]==' ')
            {
                freeSpaces++;
            }            
        }
    }
    return freeSpaces;       
}

void playerMove()
{
    int x,y;
    do
    {
        //ROWS PROMPT
    printf("\nSelect a row (1-3): ");
    scanf("%d",&x);
    x--;
    //COLUMNS PROMPT
    printf("\nSelect a column (1-3): ");
    scanf("%d",&y);
    y--;

    //CHECK FOR VALIDITY OF THAT SPOT
    if (board[x][y]!=' ')
    {
        printf("\nInvalid choice. Try again!");
    }
    else
    {
        board[x][y]=PLAYER;
        break;
    }
    } while (board[x][y] != ' ');   
}

void computerMove()
{
    int x,y;
    //LOOK FOR A WIINNING CHANCE
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j]==' ')
            {
                board[i][j]=COMPUTER;
                if (checkWinner()==COMPUTER)
            {
                return;
            }
            board[i][j]=' ';
            }            
        }        
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j]==' ')
            {
                board[i][j]=PLAYER;
                if (checkWinner()==PLAYER)
                {
                    board[i][j]=COMPUTER;
                    return;
                }
                board[i][j]=' ';
            }            
        }       
    }

    if (checkFreeSpaces()>0)
    {
        do
        {
            x=rand()%3;
            y=rand()%3;
        } while (board[x][y]!=' ');
        board[x][y] =COMPUTER;     
    }    
}

char checkWinner()
{
    //ROWS CHECK
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0]==board[i][1] && board[i][0]==board[i][2] && board[i][0]!=' ')
        {
            return board[i][0];          
        }        
    }
    //COLUMNS CHECK
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i]==board[1][i] && board[0][i]==board[2][i] && board[0][i]!=' ')
        {
            return board[0][i];          
        }        
    }
    //DIAGONALS CHECK
    if (board[0][0]==board[1][1] && board[0][0]==board[2][2] && board[0][0]!=' ')
        {
            return board[0][0];          
        }
    if (board[0][2]==board[1][1] && board[0][2]==board[2][0] && board[0][2]!=' ')
        {
            return board[0][2];          
        }
    return ' '; //NO WINNER OR JUST A DRAW
}

int main()
{
    char winner=' ';
    srand(time(0));
    refreshBoard();
    while (winner==' ' && checkFreeSpaces()!=0)
    {
        printBoard();
        //PLAYER PLAYS
        playerMove();
        winner=checkWinner();
        if (winner!=' ' || checkFreeSpaces()==0) break;
        //COMPUTER PLAYS
        computerMove();
        winner=checkWinner();
        if (winner!=' ' || checkFreeSpaces()==0) break;
          
    }
    printBoard();

    //PRINT THE RESULTS
    if (winner==PLAYER)
    {
        printf("\nCONGRATULATIONS YOU WIN !!!CAN YOU DO IT AGAIN?");
    }
    else if (winner==COMPUTER)
    {
        printf("\nCOMPUTER WINS !!! WANNA TRY AGAIN?");
    }
    else
    {
        printf("\nTHAT'S A DRAW. WANNA TRY AGAIN?");
    }       
    
    return 0;
}