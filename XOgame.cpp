#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int turn = 0;
void draw(int data[3][3])
{
    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            char temp;
            if(data[i][j]== 0 ){
                temp = 'o';
            }
            else if(data[i][j]== 1)
                temp = 'x';
            else
                temp = ' ';
            if(j!=2)
            {
                cout<<"|"<<setw(5)<<temp<<setw(5);
            }

            else
                cout<<"|"<<setw(5)<<temp<<setw(5)<<"|";
        }
        cout<<endl;
        for(int k= 0;k<31;k++)
        {
            cout<<"-";
        }
            cout<<endl;
    }
}
// 1 is x    0 is o    3 is none
int checkWinner(int data[3][3]){
int followSame = 1;

//check by row
for(int i =0;i<3;i++){
    followSame = 1;
    for(int j = 0;j<2;j++)
    {
        if(data[i][j]!=data[i][j+1])
        {
            followSame = 0;
            break;
        }
    }
    if((followSame==1) && (data[i][0]==1)){
        return 1;
    }
    else if((followSame==1) && (data[i][0]==0)){
        return 0;
    }
}
//check by colum
for(int i =0;i<3;i++){
    followSame = 1;
    for(int j = 0;j<2;j++)
    {
        if(data[j][i]!=data[j+1][i])
        {
            followSame = 0;
            break;
        }
    }
    if((followSame==1) && (data[0][i]==1)){
        return 1;
    }
    else if((followSame==1) && (data[0][i]==0)){
        return 0;
    }
}
followSame = 1;
// check diagonal
for(int i = 0;i<2;i++)
{
    if(data[i][i]!=data[i+1][i+1])
    {
        followSame = 0;
        break;
    }
}
if(    (followSame==1)&&(data[0][0]==1)     )
    return 1;
else if(    (followSame==1)&&(data[0][0]==0)     )
    return 0;
followSame = 1;
int temp = 2;
for(int i = 0;i<2;i++)
{
    if(data[i][temp]!=data[i+1][temp-1])
    {
        followSame = 0;
        break;
    }
    temp--;
}
if(    (followSame==1)&&(data[0][2]==1)     )
    return 1;
else if(    (followSame==1)&&(data[0][2]==0)     )
    return 0;

return 3;

}
int isIn(int table[9],int data)
{
    for(int i = 0;i<9;i++){
        if (data == table[i])
        {
            table[i] = 10;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int input,gameEnd = 0;
    int table[9] = {1,2,3,4,5,6,7,8,9};
    int row,colum;
    int data[3][3] = {{2,2,2},{2,2,2},{2,2,2}};
    int check;
    do{
    if(turn % 2==0)
        cout<<"XO GAME player 1 turn \n\n";
    else
        cout<<"XO GAME player 2 turn\n\n";
    draw(data);
    if(turn % 2==0)
            cout<<" you are x"<<endl;
        else
            cout<<"you are o"<<endl;
    do{
        cout<<"choose your square (1-9): ";cin>>input;

        check = isIn(table,input);
        if(check ==0)
            cout<<"cant choose same square\n";

    }while(check==0);

    input-=1;
    row = input/3;
    colum = input % 3;
    if(turn % 2==0)
        data[row][colum] = 1;
    else
        data[row][colum] = 0;
    if(checkWinner(data)!=3){
        gameEnd = 1;
        draw(data);
        if(checkWinner(data)==1)
            cout<<"player 1 win\n";
        else
            cout<<"player 2 win\n";
    }
    turn++;
    }while(gameEnd==0);
}
