#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<cctype>

using namespace std;

struct Move
{
    int row, col;
};

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

bool checker(char board[5][11], int pos){
    switch(pos){
        case 1: {if(board[0][1]==' '){
                    return true;
                }
                else 
                    return false;
        }
                break;
        
        case 2: {if(board[0][5]==' '){
                    return true;
                }
                else 
                    return false;
        }
                break;

        case 3: {if(board[0][9]==' '){
                    return true;
                }
                else 
                    return false;
        }
                break;

        case 4: {if(board[2][1]==' '){
                    return true;
                }
                else 
                    return false;
        }
                break;

        case 5: {if(board[2][5]==' '){
                    return true;
                }
                else 
                    return false;
        }
                break;

        case 6: {if(board[2][9]==' '){
                    return true;
                }
                else 
                    return false;
        }
                break;

        case 7: {if(board[4][1]==' '){
                    return true;
                }
                else 
                    return false;
        }
                break;

        case 8: {if(board[4][5]==' '){
                    return true;
                }
                else 
                    return false;
        }
                break;

        case 9: {if(board[4][9]==' '){
                    return true;
                }
                else 
                    return false;
        }
                break;

        default: cout<<"Something is wrong!!";
    }
}

char winner(char board[5][11]){
    char X = 'X';
    char O = 'O';
    char tie = 'T';

    for(int i=0; i<5; i=i+2){
        int j=1;
        if(board[i][j]=='X'&&board[i][j+4]=='X'&&board[i][j+8]=='X'){
            return X;
            break;
        }
        else if(board[i][j]=='O'&&board[i][j+4]=='O'&&board[i][j+8]=='O'){
            return O;
            break;
        }
        else{
            continue;
        }
    }
    for(int j=1; j<11; j=j+4){
        int i=0;
        if(board[i][j]=='X'&&board[i+2][j]=='X'&&board[i+4][j]=='X'){
            return X;
            break;
        }
        else if(board[i][j]=='O'&&board[i+2][j]=='O'&&board[i+4][j]=='O'){
            return O;
            break;
        }
        else{
            continue;
        }
    }
    if(board[0][1]=='X'&&board[2][5]=='X'&&board[4][9]=='X'){
        return X;
    }
    if(board[0][1]=='O'&&board[2][5]=='O'&&board[4][9]=='O'){
        return O;
    }
    if(board[0][9]=='X'&&board[2][5]=='X'&&board[4][1]=='X'){
        return X;
    }
    if(board[0][9]=='O'&&board[2][5]=='O'&&board[4][1]=='O'){
        return O;
    }
    bool checked_place;
    for(int i=1; i<=9; i++){
        checked_place = checker(board, i);
        if(checked_place==false){
            continue;
        }
        else{
            return 0;
        }
    }
    return tie;
}

void random_place_X_O(char board[5][11], char X_O, char ai){
    int choice;
    bool checked_value;
    choice = rand() % 9 + 1;
    checked_value = checker(board, choice);
    if(checked_value==true){
            switch_place(choice, board, ai);
    }
    if(checked_value==false){
        random_place_X_O(board, X_O, ai);
    }
}

int minimax(char board[5][11], int depth, bool isMaximizing, char ai, char player){
    char result = winner(board);
    if(ai == 'X'){
        if(result=='X'){
        return 1;
    }
    if(result=='O'){
        return -1;
    }
    if(result=='T'){
        return 0;
    }
    }
    else
    if(result=='X'){
        return -1;
    }
    if(result=='O'){
        return 1;
    }
    if(result=='T'){
        return 0;
    }
    
    if(isMaximizing){
        int bestScore = -1000;
        for(int i = 0; i < 5; i= i+2){
            for(int j = 1; j <10; j=j+4){
                if(board[i][j]==' '){
                    board[i][j] = ai;
                    int score = minimax(board, depth+1, false, ai, player);
                    bestScore = max(score, bestScore);
                    board[i][j] = ' ';
                }
            }
        }
        return bestScore;
    }
    else{
        int bestScore = 1000;
        for(int i = 0; i < 5; i= i+2){
            for(int j = 1; j <10; j=j+4){
                if(board[i][j]==' '){
                    board[i][j] = player;
                    int score = minimax(board, depth+1, true, ai, player);
                    bestScore = min(score, bestScore);
                    board[i][j] = ' ';
                }
            }
        }
        return bestScore;
    }
}

void level_impossible(char board[5][11], char ai, char player){
    int bestScore = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    for(int i = 0; i < 5; i= i+2){
        for(int j = 1; j <10; j=j+4){
            if(board[i][j]==' '){
                board[i][j] = ai;
                int score = minimax(board, 0, false, ai, player);
                board[i][j] = ' ';
                if(score > bestScore){
                    bestScore = score;
                    bestMove.row = i;
                    bestMove.col = j;
                }
            }
        }
    }
    board[bestMove.row][bestMove.col] = ai;
    cout<<endl;
    display_board(board);
}

int first_turn(char board[5][11], char X_O, char ai, int level){
    char check_result;
    for(int i=0; i<9 ;i++){
        if(i==0 || i%2==0){
            if(level==1){
                place_X_O(board, X_O);
            }
            else if(level==2){
                cout<<endl<<"Player 1 your turn\n";
                place_X_O(board, X_O);
            }
            else if(level==3){
                place_X_O(board, X_O);
            }
            cout<<endl;
        }
        else{
            if(level==1){
                random_place_X_O(board, X_O, ai);
            }
            else if(level==2){
                cout<<endl<<"Player 2 your turn\n";
                place_X_O(board, ai);
            }
            else if(level==3){
                level_impossible(board, ai, X_O);
            }
            else cout<<"Something is wrong";
            cout<<endl;
        }
        check_result = winner(board);
        if(check_result=='X'||check_result=='O'||check_result=='T'){
            break;
        }
        else continue;
    }
    return check_result;
}

int second_turn(char board[5][11], char X_O, char ai, int level){
    char check_result;
    for(int i=0; i<9 ;i++){
        if(i==0 || i%2==0){
            if(level==1){
                random_place_X_O(board, X_O, ai);
            }
            else if(level==2){
                cout<<endl<<"Player 2 your turn\n";
                place_X_O(board, ai);
            }
            else if(level==3){
                level_impossible(board,ai, X_O);
            }
            cout<<endl;
        }
        else{
            if(level==1){
                place_X_O(board, X_O);
            }
            else if(level==2){
                cout<<endl<<"Player 1 your turn\n";
                place_X_O(board, X_O);
            }
            else if(level==3){
                place_X_O(board, X_O);
            }
            cout<<endl;
        }
        check_result = winner(board);
        if(check_result=='X'||check_result=='O'||check_result=='T'){
            break;
        }
        else continue;
    }
    return check_result;
}

int main(){

    char flag;
    int level;
    char X_O, ai;
    string play_first;
    srand (time(NULL));
    system("clear");

    display_board(board);

    cout<<endl<<"1. Play with computer"<<endl;
    cout<<endl<<"2. Play with friend"<<endl;
    cout<<endl<<"3. Impossible to defeat"<<endl;
    cout<<endl<<"Please select your mode: ";
    cin>>level;
    switch(level){
        case 1: {
                cout<<"\nPlay as X or O: ";
                cin>>X_O;

                if(X_O=='X'){
                    ai = 'O';
                }
                if(X_O=='O'){
                    ai = 'X';
                }

                cout<<"\nDo you want to play first? ";
                cin>>play_first;

                if(play_first=="y"||play_first=="yes"||play_first=="Y"||play_first=="YES"||play_first=="1"){
                    flag = first_turn(board, X_O, ai, level);
                    if(flag == 'X')
                        cout<<"X is WINNER!!!";
                    else if(flag == 'O')
                        cout<<"O is WINNER!!!";
                    else if(flag == 'T')
                        cout<<"It's a TIE!!!";
                }
                else{
                    flag = second_turn(board,X_O, ai, level);
                    if(flag == 'X')
                        cout<<"X is WINNER!!!";
                    else if(flag == 'O')
                        cout<<"O is WINNER!!!";
                    else if(flag == 'T')
                        cout<<"It's a TIE!!!";
                }
        }
        break;

        case 2: {
                cout<<"\nPlayer 1 play as X or O: ";
                cin>>X_O;
                cout<<"\nPlayer 2 play as X or O: ";
                cin>>ai;

                cout<<"\nWhich player wants to play first? ";
                cin>>play_first;

                string temp(1, X_O);

                if(play_first=="first"||play_first=="1"||play_first=="first player"||play_first=="player 1"||play_first==temp){
                    flag = first_turn(board, X_O, ai, level);
                    if(flag == 'X')
                        cout<<"X is WINNER!!!";
                    else if(flag == 'O')
                        cout<<"O is WINNER!!!";
                    else if(flag == 'T')
                        cout<<"It's a TIE!!!";
                }
                else{
                    flag = second_turn(board,X_O, ai, level);
                    if(flag == 'X')
                        cout<<"X is WINNER!!!";
                    else if(flag == 'O')
                        cout<<"O is WINNER!!!";
                    else if(flag == 'T')
                        cout<<"It's a TIE!!!";
                }

        }
        break;

        case 3: {
                char ai;
                char checker_value;
                int flag = 0;
                cout<<"\nPlay as X or O: ";
                cin>>X_O;

                if(X_O=='X'){
                    ai = 'O';
                }
                if(X_O=='O'){
                    ai = 'X';
                }

                cout<<"Do you wish to play first move? ";
                cin>>play_first;

                if(play_first=="y"||play_first=="yes"||play_first=="Y"||play_first=="YES"||play_first=="1"){
                    flag = first_turn(board, X_O, ai, level);
                    if(flag == 'X')
                        cout<<"X is WINNER!!!";
                    else if(flag == 'O')
                        cout<<"O is WINNER!!!";
                    else if(flag == 'T')
                        cout<<"It's a TIE!!!";
                }
                else{
                    flag = second_turn(board,X_O, ai, level);
                    if(flag == 'X')
                        cout<<"X is WINNER!!!";
                    else if(flag == 'O')
                        cout<<"O is WINNER!!!";
                    else if(flag == 'T')
                        cout<<"It's a TIE!!!";
                }
        }
        break;

        default: cout<<"Something is not right:(";
    }


    return 0;
}