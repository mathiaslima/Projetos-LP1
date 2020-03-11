#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <fstream>

#define EMPTY short(0)
#define SIZE 9

void print( short b[SIZE][SIZE] )
{
    // TODO: implement this function.
    for (int i(0); i < SIZE; ++i)
    {
        for (int j(0); j < SIZE; ++j)
        {
            std::cout << b[i][j] << " ";
        }
        std::cout << "\n";
    }

}
int CheckerRows( int v[SIZE] ){
    int array[]{0,0,0,0,0,0,0,0,0};
    for(int i(0); i < SIZE; i++){
        array[v[i]-1] += 1;
    }
    for(int i(0); i < SIZE; i++){
        if(array[i] == 0)
            return 0;
    }

    return 1;
}

bool is_valid( short b[SIZE][SIZE] )
{
    int vLine[SIZE];
    int cont(0);
    int step(0);
    // checker rows of board
    for (int i(0); i < SIZE; ++i){
        for (int j(0); j < SIZE; ++j){
              vLine[j] = b[i][j];
        }

        cont = CheckerRows(vLine);
        if(cont == 0){
            return false;
        }
    }
    // checker cols of board
    for (int i(0); i < SIZE; ++i){
        for (int j(0); j < SIZE; ++j){
              vLine[j] = b[j][i];
        }

        cont = CheckerRows(vLine);
        if(cont == 0){
            return false;
        }
    }

    for (int i(0); i < SIZE; i += 3){
        for (int c(0); c < SIZE; c += 3){
          step = 0;
          for (int j(i); j < i+3; ++j){
            for (int h(c); h < c+3; ++h){
               vLine[step] = b[j][h];
               step++;
            }
          }
            cont = CheckerRows(vLine);
            if(cont == 0){
                return false;
            }
        }

    }



    return true; // This is just a stub. Replace it as needed.
}


int main(void)
{
/*
    short boards[][SIZE][SIZE] {
        {
            { 1, 3, 4, 6, 7, 8, 5, 9, 2 },
            { 6, 7, 2, 1, 9, 5, 3, 4, 8 },
            { 5, 9, 8, 3, 4, 2, 1, 6, 7 },
            { 8, 5, 9, 7, 6, 1, 4, 2, 3 },
            { 4, 2, 6, 8, 5, 3, 9, 7, 1 },
            { 7, 1, 3, 4, 2, 9, 8, 5, 6 },
            { 9, 6, 1, 5, 3, 7, 2, 8, 4 },
            { 2, 8, 7, 9, 1, 4, 6, 3, 5 },
            { 3, 4, 5, 2, 8, 6, 7, 1, 9 }
        },

        {
            { 1, 6, 2, 8, 5, 7, 4, 9, 3 },
            { 5, 3, 4, 1, 2, 9, 6, 7, 8 },
            { 7, 8, 9, 6, 4, 3, 5, 2, 1 },
            { 4, 7, 5, 3, 1, 2, 9, 8, 6 },
            { 9, 1, 3, 5, 8, 6, 7, 4, 2 },
            { 6, 2, 8, 7, 9, 4, 1, 3, 5 },
            { 3, 5, 6, 4, 7, 8, 2, 1, 9 },
            { 2, 4, 1, 9, 3, 5, 8, 6, 7 },
            { 8, 9, 7, 2, 6, 1, 3, 5, 4 }
        },

        {
            { 5, 3, 4, 6, 7, 8, 9, 1, 2 },
            { 6, 7, 2, 1, 9, 5, 3, 4, 8 },
            { 1, 9, 8, 3, 4, 2, 5, 6, 7 },
            { 8, 5, 9, 7, 6, 1, 4, 2, 3 },
            { 4, 2, 6, 8, 5, 3, 7, 9, 1 },
            { 7, 1, 3, 9, 2, 4, 8, 5, 6 },
            { 9, 6, 1, 5, 3, 7, 2, 8, 4 },
            { 2, 8, 7, 4, 1, 9, 6, 3, 5 },
            { 3, 4, 5, 2, 8, 6, 1, 7, 9 }
        },

        // Problem
        {
            { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
            { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
            { 1, 8, 3, 4, 2, 9, 5, 6, 7 },
            { 8, 9, 7, 6, 1, 5, 4, 2, 3 },
            { 4, 6, 8, 5, 3, 2, 7, 9, 1 },
            { 5, 4, 6, 7, 8, 3, 9, 1, 2 },
            { 7, 3, 9, 2, 4, 1, 8, 5, 6 },
            { 9, 1, 5, 3, 7, 6, 2, 8, 4 },
            { 3, 5, 2, 8, 6, 4, 1, 7, 9 }

        },


        // Problem
        {
            { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
            { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
            { 1, 8, 3, 4, 2, 9, 5, 6, 7 },
            { 8, 9, 7, 6, 1, 5, 4, 2, 3 },
            { 4, 6, 8, 5, 3, 2, 5, 9, 1 },
            { 5, 4, 6, 7, 8, 3, 9, 1, 2 },
            { 7, 3, 9, 2, 4, 1, 8, 5, 6 },
            { 9, 3, 5, 3, 7, 6, 2, 8, 4 },
            { 3, 5, 2, 8, 6, 4, 1, 7, 9 }
        },

        // Problem
        {
            { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
            { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
            { 1, 8, 3, 4, 2, 19, 5, 6, 7 },
            { 8, 9, 7, 6, 1, 5, 4, 2, 3 },
            { 4, 6, 8, 5, 3, 2, 7, 9, 1 },
            { 5, 4, 6, 7, 8, 3, 9, 1, 2 },
            { 7, -3, 9, 2, 4, 1, 8, 5, 6 },
            { 9, 1, 5, 3, 7, 6, 2, 8, 4 },
            { 3, 5, 2, 8, 6, 4, 1, 7, 9 }
        },

        // Problem
        {
            { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
            { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
            { 1, 8, 3, 4, 2, 9, 5, 6, 7 },
            { 8, 9, 7, 6, 1, 5, 4, 2, 3 },
            { 4, 6, 8, 5, 3, 2, 7, 9, 1 },
            { 5, 4, 6, 7, 8, 3, 9, 1, 2 },
            { 7, 3, 9, 2, 4, 1, 0, 5, 6 },
            { 9, 1, 5, 3, 7, 6, 2, 8, 4 },
            { 3, 5, 2, 8, 6, 4, 1, 7, 9 }
        },

        // Problem
        {
            { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
            { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
            { 1, 8, 3, 4, 2, 9, 5, 6, 7 },
            { 8, 9, 7, 3, 1, 5, 4, 2, 3 },
            { 4, 6, 8, 5, 3, 2, 7, 9, 1 },
            { 5, 4, 6, 7, 8, 6, 9, 1, 2 },
            { 7, 3, 9, 2, 4, 1, 8, 5, 6 },
            { 9, 1, 5, 3, 7, 6, 2, 8, 4 },
            { 3, 5, 2, 8, 6, 4, 1, 7, 9 }
        }for(int i(0); i < SIZE; i++){
        for(int j(0); j < SIZE; j++){
            Take >> board[i][j];
        }
    }
    };
*/

    short board[SIZE][SIZE];
    // TODO: Make the code below work, instead of the ugly code above.
    std::ifstream Take;
    Take.open("boards.txt"); //here take is an text


    int n_boards{ 8 }; // Number of boards...
    for ( int i{0}; i < 8 ; ++i )
    {
        for(int i(0); i < SIZE; i++){
            for(int j(0); j < SIZE; j++){
                Take >> board[i][j];
            }
        }
        std::cout << "Board #" << (i+1) << ": \n";
        print( board );
        std::cout << "Is valid? " << std::boolalpha << is_valid( board ) << std::endl;
        std::cout << "\n";
    }

    Take.close();

    return 0;
}
