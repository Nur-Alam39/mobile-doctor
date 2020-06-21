/* A simple Tic Tac Toe game. */
#include <stdio.h>
#include <stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<string.h>
int MOuse()
{
    int x, y;
    while(!ismouseclick(WM_RBUTTONDOWN))
        delay(50);
    getmouseclick(WM_LBUTTONDOWN, x,y);
    return x;
}
char matrix[3][3]; /* the tic tac toe matrix */
char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matrix(void);
int main(void)
{
    char done;
    int gd=DETECT,gm;
    initwindow(1360,760);
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    cleardevice();
    setfillstyle(XHATCH_FILL, BLUE);
    settextstyle(4,HORIZ_DIR,2);
    setcolor(WHITE);
    outtextxy(600,100,"Tic-Tac-Toe");
    settextstyle(4,HORIZ_DIR,1);
    setcolor(3);
    outtextxy(200,200,"This is the game of Tic Tac Toe.");
    outtextxy(200,220,"You will be playing against the computer.\n");
    done = ' ';
    init_matrix();
    do
    {
        disp_matrix();
        get_player_move();
        done = check(); /* see if winner */
        if(done!= ' ') break; /* winner!*/
        get_computer_move ();
        done = check(); /* see if winner */
    }
    while(done== ' ');
    if(done=='X')
        outtextxy(200,600,"You won!");
    else
        outtextxy(200,600,"I won!!!!");
    disp_matrix(); /* show final positions */
    return 0;
}
/* Initialize the matrix. */
void init_matrix(void)
{
    int i, j;
    for(i=0; i<3; i++)
        for(j=0; j<3; j++) matrix[i][j] = ' ';
}
/* Get a player's move. */
void get_player_move (void)
{
    int x, y;
    printf("Enter X,Y coordinates for your move: ");
    scanf("%d%*c%d", &x, &y);
    x--;
    y--;
    if(matrix[x][y]!= ' ')
    {
        printf("Invalid move, try again.\n");
        get_player_move();
    }
    else matrix[x][y] = 'X';
}
/* Get a move from the computer. */
void get_computer_move(void)
{
    int i, j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            if(matrix[i][j]==' ') break;
        if(matrix[i][j]==' ') break;
    }
    if(i*j==9)
    {
        printf("draw\n");
        exit(0);
    }
    else
        matrix[i][j] = 'O';
}
/* Display the matrix on the screen. */
void disp_matrix(void)
{
    int t;
    for(t=0; t<3; t++)
    {
        printf(" %c | %c | %c ",matrix[t][0], matrix[t][1], matrix [t][2]);
        if(t!=2)
            printf("\n---|---|---\n");
    }
    printf ("\n");
}
/* See if there is a winner. */
char check(void)
{
    int i;
    for(i=0; i<3; i++) /* check rows */
        if(matrix[i][0]==matrix[i][1] && matrix[i][0]==matrix[i][2])
                return matrix[i][0];
    for(i=0; i<3; i++) /* check columns */
        if(matrix[0][i]==matrix[1][i] && matrix[0][i]==matrix[2][i])
            return matrix[0][i];
    /* test diagonals */
    if(matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2])
        return matrix[0][0];
    if(matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0])
        return matrix[0][2];
    return ' ';
}
