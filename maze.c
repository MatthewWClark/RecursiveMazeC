#include <stdio.h>
#include <stdbool.h>
bool mazeGo(int x, int y, char maze[6][6])
{
    if (maze[x][y] == '#') 
    {
        return false;
    }
    if (maze[x][y]=='+')
    {
        return false;
    }
    if (x< 0 || y<0 || x>6 || y>6)
    {
        return false;
    }
    if (maze[x][y]=='G')
    {
        for(int i=0; i<6; i++)
    {
        for(int j=0; j<6;j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
        return true;
        
    }
    
    maze[x][y] = '+';
    
    // north south east and west
    if (mazeGo(x-1, y, maze))
    {
        return true;
    }
    
    if (mazeGo(x,y+1, maze))
    {
        return true;
    }
    
    if (mazeGo(x+1,y,maze))
    {
        return true;
    }
    
    if (mazeGo(x,y-1,maze))
    {
        return true;
    }
    
    //marking if backtracking
    maze[x][y] = 'b';
    return false;
    
    
}
int main()
{
    char maze[6][6] = {
        {'S','#','#','#','#','#'},
        {'.','.','.','.','.','#'},
        {'#','.','#','#','#','#'},
        {'#','.','#','#','#','#'},
        {'.','.','.','#','.','G'},
        {'#','#','.','.','.','#'}
    };
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6;j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
   mazeGo(0,0,maze);
    
    return 0;
    
}
