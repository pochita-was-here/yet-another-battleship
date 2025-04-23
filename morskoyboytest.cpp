#include <vector>
#include <iostream>


using namespace std;

bool canPlaceShip(vector<char>& board, int x, int y, int size, int shipLength, char direction)
{
    int tempX = x;
    int tempY = y;


    if (direction == 'v')
    {
        for (int i = 0; i < shipLength; i++)
        {
            if (tempX < 1 || tempY < 1 || tempX > size || tempY > size)
            {
                return false;
            }
            
            if (board[(tempX - 1) + (size - tempY) * size] != '.')
            {
                return false;
            }
            else
            {
                tempY++;
            }
        }
    }

    if (direction == 'h')
    {
        for (int i = 0; i < shipLength; i++)
        {
            if (tempX < 1 || tempY < 1 || tempX > size || tempY > size)
            {
                return false;
            }

            if (board[(tempX - 1) + (size - tempY) * size] != '.')
            {
                return false;
            }
            else
            {
                tempX++;
            }
        }
    }

    return true;
}


void printBoard(vector<char>& board, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int k = 0; k < size; k++)
        {
            cout << board[k + (size * i)] << " ";
        }
        cout << endl;
    }
}


int cageIndex(int x, int y, int size)
{
    //if ((x < 0) || (y < 0) || (x > size) || (y > size))
    //{
    //    return -1;
    //}
    int res = (x-1) + (size - y) * size;
    return res;
}


void placeShip(vector<char>& board, int x, int y, int size, int shipLength, char direction)
{

    if (!canPlaceShip(board, x, y, size, shipLength, direction))
    {
        return;
    }
    else
    {
        for (int i = 0; i < shipLength; i++)
        {
           if (direction=='h')
           {
               board[cageIndex(x, y, size)] = 'O';
               x++;
           }
           else if (direction == 'v')
           {
               board[cageIndex(x, y, size)] = 'O';
               y++;
           }
        }
    }
}

void shoot(vector<char>& board, int x, int y, int size)
{
    if ((x < 1) || (y < 1) || (x > size) || (y > size))
        {
            return;
        }

    int index = cageIndex(x, y, size);


    if (board[index] == '.')
    {
        board[index] = '*';
        cout << "Miss!" << endl;
        return;
    }
    if (board[index] == 'O')
    {
        board[index] = 'X';
        cout << "Shot!" << endl;
        return;
    }
    if (board[index] == '*'|| board[index] == 'X')
    {
        cout << "Already shot!" << endl;
        return;
    }
}



int main()
{
    int boardSize = 10;

    vector<char> board(boardSize* boardSize, '.');

    printBoard(board, boardSize);

    int n;
    cout << "Vvedite kolichestvo korabley: " << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y, sh;
        char ch;
        bool valid = false;
        while (!valid)
        {
            cout << "Vvedite razmer " << i + 1 << " korablya." << endl;

            cin >> sh;

            cout << "Vvedite raspolojenie (horizontal/vertical) " << i + 1 << " korablya: h/v" << endl;

            cin >> ch;

            cout << "Vvedite nachalnie koordinati dlya " << i + 1 << " korablya." << endl;

            cin >> x >> y;

            if (canPlaceShip(board, x, y, boardSize, sh, ch))
            {
                placeShip(board, x, y, boardSize, sh, ch);
                valid = true;
            }
            else
            {
                cout << "Nevernoe raspolojenie!" << endl;
            }

        }

        printBoard(board, boardSize);
    }

    bool notOver = true;

    while (notOver)
    {
        cout << "Vvedite koordinati dlya vistrela v formate x y: " << endl;
        int x, y;
        cin >> x >> y;

        shoot(board, x, y, boardSize);

        printBoard(board, boardSize);

        if (find(board.begin(), board.end(), 'O')==board.end())
        {
            cout << "Victory! All ships sunk!" << endl;
            notOver = false;
        }
    }





    return 0;
}

