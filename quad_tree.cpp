//
//  quad_tree.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/25.
//  acmicpc.net/problem/1992

#include <iostream>
#include <stdio.h>
using namespace std;
int arr[65][65];

void compression(int row, int col, int N){
    int temp = arr[row][col];
    bool same=true;
    for(int i=row;i<row+N;i++){         //영역이 모두 0이거나 모두 1인경우 탐색
        for(int j=col;j<col+N;j++){
            if(temp!=arr[i][j]){
                same=false;
                break;
            }
        }
        if(!same)
            break;
    }
    if(same){
        cout<<arr[row][col];
        return;
    }
    else{
        cout<<"(";
        compression(row, col, N/2);
        compression(row, col+N/2, N/2);
        compression(row+N/2, col, N/2);
        compression(row+N/2, col+N/2, N/2);
        cout<<")";
    }
    return;
}

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%1d",&arr[i][j]);
        }
    }
    compression(0, 0, N);
    
    return 0 ;
}
