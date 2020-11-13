

#include<iostream>
#define SIZE 50
#define White 1
#define Black 0
int maze[SIZE][SIZE],maze2 [SIZE][SIZE], l=1;
void print(int n)
{
    int i,j;
    printf("STEP: %d\t\t\tGiven Maze was:\n\n",l);
    l++;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("  %d",maze2[i][j]);

        }
        printf("\t\t\t");

        for(int k=0; k<n; k++)
        {

            printf("  %d",maze[i][k]);
        }
        printf("\n") ;
    }
}
/*.....................Author.................
..................MD Jakir Hossain............
...Department of CSE at EWU....................
*/

int solutionmaze(int row, int column,int n)
{


    if((row==n-1) && (column==n-1))  //solve
    {

        maze2 [row][column] = 2;
        printf("\n\nCONGRATULATIONS ! THE MOUSE REACHED IT'S FINAL DESTINATION\n\n");

        return 1;
    }

    if(row>=0 && column>=0 && row<n && column<n && maze2[row][column] == White && maze[row][column] == White)
    {

        maze2[row][column] = 2;
        print(n);

        if(solutionmaze(row, column+1,n))  //right e
            return 1;

        if(solutionmaze(row+1, column,n)) // niche jabe
            return 1;


        if(solutionmaze(row, column-1,n)) // left e
            return 1;


        if(solutionmaze(row-1, column,n)) //upore
            return 1;


        maze2[row][column] = White;    //backtracking
        return 0;
    }
    return 0;

}



int main()
{
    int i,j,n;


    printf("\n\n\t\t\tRAT IN A MAZE \n\n\n");
    printf("\t\t\t |- * * * -|  \n");
    printf("\t\t\t |- - * * *| \n");
    printf("\t\t\t |* - - * *| \n");
    printf("\t\t\t |* - * * -| \n");
    printf("\t\t\t |- - - - -| \n\n");
    printf("NOTE: 1 means WHITE and 0 means BLACK");
    printf("\n\n Enter Your Maze Size:    \n\n");
    scanf("%d",&n);
    printf("\nEnter the Maze Structure :(%d*%d) \n",n,n);
    //input maze
    for( i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&maze[i][j]);
        }
    }
    //solution maze
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            maze2[i][j] = White;
        }
    }


    if (solutionmaze(0,0,n))
    {

        print(n);
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(maze2[i][j]==2)
                {
                    printf("%d,%d ",i,j);
                }

            }

        }

    }
    else
        printf("\n\n\nSORRY! No Available Paths To Reach The Destination!\n\n\n");
    return 0;
}
