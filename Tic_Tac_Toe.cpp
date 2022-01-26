#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

char board[5][11]={
            ' ', ' ', ' ', '|',' ', ' ', ' ', '|', ' ', ' ', ' ',
            '-', '-', '-', '|', '-', '-', '-', '|', '-', '-', '-', 
            ' ', ' ', ' ', '|',' ', ' ', ' ', '|', ' ', ' ', ' ', 
            '-', '-', '-', '|', '-', '-', '-', '|', '-', '-', '-', 
            ' ', ' ', ' ', '|',' ', ' ', ' ', '|', ' ', ' ', ' '
            };

void display_board(char board[5][11]){
        for(int i = 0; i <5; i++){
            for(int j = 0; j <11; j++){
                cout<<board[i][j];
            }
            cout<<endl;
        }
}

void switch_place(int choice, char board[5][11], int X_O){
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

void place_X_O(char board[5][11], char X_O){
    int choice;
    cout<<"At what place you want to keep it from 1-9: ";
    cin>>choice;
    switch_place(choice, board, X_O);
}

bool checker(char board[5][11], int pos, char X_O, char comp){
    switch(pos){
        case 1: {if(board[0][1]==X_O || board[0][1]==comp){
                    return false;
                }
                else 
                    return true;
        }
                break;
        
        case 2: {if(board[0][5]==X_O || board[0][5]==comp){
                    return false;
                }
                else 
                    return true;
        }
                break;

        case 3: {if(board[0][9]==X_O || board[0][9]==comp){
                    return false;
                }
                else 
                    return true;
        }
                break;

        case 4: {if(board[2][1]==X_O || board[2][1]==comp){
                    return false;
                }
                else 
                    return true;
        }
                break;

        case 5: {if(board[2][5]==X_O || board[2][5]==comp){
                    return false;
                }
                else 
                    return true;
        }
                break;

        case 6: {if(board[2][9]==X_O || board[2][9]==comp){
                    return false;
                }
                else 
                    return true;
        }
                break;

        case 7: {if(board[4][1]==X_O || board[4][1]==comp){
                    return false;
                }
                else 
                    return true;
        }
                break;

        case 8: {if(board[4][5]==X_O || board[4][5]==comp){
                    return false;
                }
                else 
                    return true;
        }
                break;

        case 9: {if(board[4][9]==X_O || board[4][9]==comp){
                    return false;
                }
                else 
                    return true;
        }
                break;

        default: cout<<"Something is wrong!!";
    }
}

bool winner(char board[5][11]){
    int flag = 0;
    for(int i=0; i<5; i=i+2){
        int j=1;
        if(board[i][j]=='X'&&board[i][j+4]=='X'&&board[i][j+8]=='X'){
            cout<<"\nX is winner\n";
            return true;
            break;
        }
        else if(board[i][j]=='O'&&board[i][j+4]=='O'&&board[i][j+8]=='O'){
            cout<<"\nO is winner\n";
            return true;
            break;
        }
        else{
            continue;
        }
    }
    for(int j=1; j<11; j=j+4){
        int i=0;
        if(board[i][j]=='X'&&board[i+2][j]=='X'&&board[i+4][j]=='X'){
            cout<<"\nX is winner\n";
            return true;
            break;
        }
        else if(board[i][j]=='O'&&board[i+2][j]=='O'&&board[i+4][j]=='O'){
            cout<<"\nO is winner\n";
            return true;
            break;
        }
        else{
            continue;
        }
    }
    if(board[0][1]=='X'&&board[2][5]=='X'&&board[4][9]=='X'){
        cout<<"\nX is winner\n";
        return true;
    }
    if(board[0][1]=='O'&&board[2][5]=='O'&&board[4][9]=='O'){
        cout<<"\nO is winner\n";
        return true;
    }
    if(board[0][9]=='X'&&board[2][5]=='X'&&board[4][1]=='X'){
        cout<<"\nX is winner\n";
        return true;
    }
    if(board[0][9]=='O'&&board[2][5]=='O'&&board[4][1]=='O'){
        cout<<"\nO is winner\n";
        return true;
    }
}

void random_place_X_O(char board[5][11], char X_O, char comp){
    int choice;
    bool checked_value;
    choice = rand() % 9 + 1;
    checked_value = checker(board, choice, X_O, comp);
    if(checked_value==true){
            switch_place(choice, board, comp);
    }
    if(checked_value==false){
        random_place_X_O(board, X_O, comp);
    }
}

void level_impossible(char board[5][11]){

}


int main(){

    bool check_result;
    int flag = 0 ;
    char X_O, comp;
    string play_first;
    srand (time(NULL));
    system("clear");
    
    display_board(board);

    cout<<"Play as X or O: ";
    cin>>X_O;

    if(X_O=='X'){
        comp = 'O';
    }
    if(X_O=='O'){
        comp = 'X';
    }

    cout<<"\nDo you want to play first? ";
    cin>>play_first;

    if(play_first=="y"||play_first=="yes"||play_first=="Y"||play_first=="YES"||play_first=="1"){
        for(int i=0; i<9 ;i++){
            if(i==0 || i%2==0){
                place_X_O(board, X_O);
                cout<<endl;
            }
            else{
                random_place_X_O(board, X_O, comp);
                cout<<endl;
            }
            check_result = winner(board);
            if(check_result==true){
                flag = 1;
                break;
            }
            else continue;
        }
    }
    else{
        for(int i=0; i<9 ;i++){
            if(i==0 || i%2==0){
                random_place_X_O(board, X_O, comp);
                cout<<endl;
            }
            else{
                place_X_O(board, X_O);
                cout<<endl;
            }
            check_result = winner(board);
            if(check_result==true){
                flag = 1;
                break;
            }
            else continue;
        }
    }

    if(flag==0){
        cout<<"It's a DRAW\n";
    }

    return 0;
}