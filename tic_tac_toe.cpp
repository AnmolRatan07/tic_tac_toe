#include <iostream>
#include <cmath>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char current_marker;
int current_Player;
void drawboard()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "------------\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "------------\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}
bool placemarker(int slot)
{
    int row;
    if (slot % 3 == 0)
        row = (slot / 3) - 1;

    else
        row = slot / 3;

    int col;
    if (slot % 3 == 0)
        col = 2;
    else
        col = (slot % 3) - 1;
    if (board[row][col] != 'O' && board[row][col] != 'X')
    {       
            board[row][col]=current_marker;
            return true;
    }
    else
    return false;
}

int winner()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return current_Player;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return current_Player;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return current_Player;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return current_Player;

    return 0;
}
void swap()
{
    if (current_marker == 'X')
        current_marker = 'O';
    else
        current_marker = 'X';

    if (current_Player == 1)
        current_Player = 2;
    else
        current_Player = 1;
}
void game()
{
    cout << "player one, choose your mearker : X or O ";
    char marker;
    cin >> marker;
    cout<<endl;
    current_Player = 1;
    current_marker = marker;
    drawboard();
    int player_won;
    for (int i = 0; i < 9; i++)
    {
        cout << " It's players " << current_Player << "  turn , enter slot  1 - 9 ::  " << endl;
        int slot;
        cin >> slot;
        cout<<endl;
        if(slot < 1 || slot >9){
       cout<<"wrong slot \n";
       i--;
       continue;
       }

       if( ! placemarker(slot)){
       cout<<"slot is occupied \n";
       i--;
       continue;
       }
        drawboard();
        player_won = winner();
        if (player_won == 1)
        {
            cout << " player one won ";
            break;
        }
        if (player_won == 2)
        {
            cout << " player two won ";
            break;
        }
        swap();
    }
    if (player_won == 0)
        cout << "thats  tie ";
}
int main()
{
    game();
    return 0;
}