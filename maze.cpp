//
//  maze.cpp
//  HW 3
//
//  Created by Anica Wang on 2/5/21.
//

//#include <iostream>
//#include <string>
//
//using namespace std;

class Coord
{
  public:
    Coord(int rr, int cc) : m_row(rr), m_col(cc) {}
    int r() const { return m_row; }
    int c() const { return m_col; }
  private:
    int m_row;
    int m_col;
};

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
          // Return true if there is a path from (sr,sc) to (er,ec)
          // through the maze; return false otherwise
{
    if (sr == er && sc == ec)
    {
        return true;
    }

    if (sr < 0 || sc < 0 || er < 0 || ec < 0)
    {
        return false;
    }

    maze[sr][sc] = '*';
    int r = sr;
    int c = sc;
    Coord coo(r, c);

    if (maze[coo.r() - 1][coo.c()] == '.' && pathExists(maze, nRows, nCols, coo.r() - 1, coo.c(), er, ec))
    {
        return true;
    }

    if (maze[coo.r() + 1][coo.c()] == '.' && pathExists(maze, nRows, nCols, coo.r() + 1, coo.c(), er, ec))
    {
        return true;
    }

    if (maze[coo.r()][coo.c() - 1] == '.' && pathExists(maze, nRows, nCols, coo.r(), coo.c() - 1, er, ec))
    {
        return true;
    }
    if (maze[coo.r()][coo.c() + 1] == '.' && pathExists(maze, nRows, nCols, coo.r(), coo.c() + 1, er, ec))
    {
        return true;
    }

    return false;
}

//int main()
//{
//    string maze[10] = {
//       //0123456789
//        "XXXXXXXXXX", //0
//        "X........X", //1
//        "XX.X.XXXXX", //2
//        "X..X.X...X", //3
//        "X..X...X.X", //4
//        "XXXX.XXX.X", //5
//        "X.X....XXX", //6
//        "X..XX.XX.X", //7
//        "X...X....X", //8
//        "XXXXXXXXXX"  //9
//       //0123456789
//    };
//
//    if (pathExists(maze, 10,10, 6,4, 1,1))
//        cout << "Solvable!" << endl;
//    else
//        cout << "Out of luck!" << endl;
//}

//int main()
//{
//    string maze[10] = {
//        "XXXXXXXXXX",
//        "X........X",
//        "XX.X.XXXXX",
//        "X..X.X...X",
//        "X..X...X.X",
//        "XXXX.XXX.X",
//        "X.X....XXX",
//        "X..XX.XX.X",
//        "X...X....X",
//        "XXXXXXXXXX"
//    };
//
//    assert(pathExists(maze, 10, 10, 6, 4, 7, 1) == 0);
//    string maze1[10] = {
//        "XXXXXXXXXX",
//        "X........X",
//        "XX.X.XXXXX",
//        "X..X.X...X",
//        "X..X...X.X",
//        "XXXX.XXX.X",
//        "X.X....XXX",
//        "X..XX.XX.X",
//        "X...X....X",
//        "XXXXXXXXXX"
//    };
//    assert(pathExists(maze1, 10, 10, 6, 4, 1, 7) == 1);
//    string maze2[10] = {
//        "XXXXXXXXXX",
//        "X........X",
//        "XX.X.XXXXX",
//        "X..X.X...X",
//        "X..X...X.X",
//        "XXXX.XXX.X",
//        "X.X....XXX",
//        "X..XX.XX.X",
//        "X...X....X",
//        "XXXXXXXXXX"
//    };
//    assert(pathExists(maze2, 10, 10, 6, 4, 1, 1) == 1);
//    cout << "Passed" << endl;
//}
