#include<iostream>

using namespace std;

void display_board(char board[5][11]){
        for(int i = 0; i <5; i++){
            for(int j = 0; j <11; j++){
                cout<<board[i][j];
            }
            cout<<endl;
        }
}

void place_X_O(char board[5][11]){
    char X_O;
    int choice;
    cout<<"Place: ";
    cin>>X_O;
    cout<<"At what place you want to keep it from 1-9: ";
    cin>>choice;
    switch(choice){
        case 1: board[0][1]=X_O; 
                break;
        case 2: board[0][5]=X_O; 
                break;
        case 3: board[0][9]=X_O; 
                break;
        case 4: board[2][1]=X_O; 
                break;
        case 5: board[2][5]=X_O; 
                break;
        case 6: board[2][9]=X_O; 
                break;
        case 7: board[4][1]=X_O; 
                break;
        case 8: board[4][5]=X_O; 
                break;
        case 9: board[4][9]=X_O; 
                break;
        defualt: cout<<"Something is not right:(";
    }
    display_board(board);
}

int main(){
    system("clear");

    char board[5][11]={
                ' ', ' ', ' ', '|',' ', ' ', ' ', '|', ' ', ' ', ' ',
                '-', '-', '-', '|', '-', '-', '-', '|', '-', '-', '-', 
                ' ', ' ', ' ', '|',' ', ' ', ' ', '|', ' ', ' ', ' ', 
                '-', '-', '-', '|', '-', '-', '-', '|', '-', '-', '-', 
                ' ', ' ', ' ', '|',' ', ' ', ' ', '|', ' ', ' ', ' '
                };
    
    display_board(board);

    place_X_O(board);
    return 0;
}