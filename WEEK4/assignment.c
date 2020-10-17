#include <stdio.h>
 
void printMaze(char **maze, const int HT, const int WD); // prints the maze
 
int solveMaze(char **maze, const int HT, const int WD, int y, int x); // draws a path to the exit on the maze string
 
int main(){
    char mazeStr[] ="  ##############"
                    "#     #     ####"
                    "# ####* ### ####"
                    "#    ###### ####"
                    "#### # #### ####"
                    "#    # #### ####"
                    "#### # #### ####"
                    "####        ####"
                    "################";
    const int HT = 9;
    const int WD = 16; 
    char *maze[HT];

    for (int i = 0; i < HT ; i++)       // filling the 2D char array
        maze[i] = &mazeStr[i * WD];

    solveMaze(maze, HT, WD, 0, 0); 

    printMaze(maze, HT, WD);

    return 0;
}

int solveMaze(char **maze, const int HT, const int WD, int y, int x){ 
    
    const char *path = ".";     //marks the path
    const char *endp = "*";     //marks the end point
    const char *block = "#";    //marks the blocked
    const char *wpth = "X";     //marks the wrong path

    if(y < 0 || y >= WD || x < 0 || x >= HT)    //checks the bounds of the arrays
        return 0;
    if(*(*(maze + x) + y) == *endp)             //end point
        return 1;
    if(*(*(maze + x) + y) == *path)             //marked path
        return 0;
    if(*(*(maze + x) + y) == *block)            //blocked point
        return 0;

    *(*(maze + x) + y) = *path;

    if(solveMaze(maze, HT, WD, y, x - 1) ==1)       //up
        return 1;
    if(solveMaze(maze, HT, WD, y + 1, x) ==1)       //right
        return 1;
    if(solveMaze(maze, HT, WD, y, x + 1) ==1)       //down
        return 1;
    if(solveMaze(maze, HT, WD, y - 1, x) ==1)       //left
        return 1;

    *(*(maze + x) + y) = *wpth;

    return 0;
}


void printMaze(char **maze, const int HT, const int WD){
    for (int i = 0; i < HT ; i++){
        for(int j = 0; j < WD - 1; j++)
            printf("%c",maze[i][j]);
    printf("%c\n",maze[i][WD - 1]);
    }   
}
