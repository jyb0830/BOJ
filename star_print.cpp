//
//  star_print.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/24.
//  acmicpc.net/problem/1030

#include <iostream>
using namespace std;
char arr[2187][2187];
void star(int row, int col, int N){
    if(N==3){
        arr[row+1][col+1]=' ';
        return;
    }
    else{
        for(int i=row+(N/3);i<row+(N/3)*2;i++){
            for(int j=col+(N/3);j<col+(N/3)*2;j++){
                arr[i][j]=' ';
            }
        }
        for(int i=row;i<row+N;i+=(N/3)){
            for(int j=col;j<col+N;j+=(N/3)){
                star(i,j,N/3);
            }
        }
    }
}


int main(){
    int N;
    cin>>N;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
        arr[i][j]='*';
    }
    star(0,0,N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
        cout<<arr[i][j];
        }
        cout<<"\n";
    }
    
    return 0;
}
