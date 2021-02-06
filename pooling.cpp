//
//  pooling.cpp
//  BOJ
//
//  Created by 지영본 on 2021/02/06.
//  acmicpc.net/problem/17829

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1024][1024];

int pooling(int n, int row, int col){
    if(n==2){
        int temp[4], idx=0;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++)
            temp[idx++]=arr[row+i][col+j];
        }
        sort(temp, temp+4);
        return temp[2];
    }
    
    else{
        int temp[4];
        temp[0]=pooling(n/2, row, col);
        temp[1]=pooling(n/2, row, col+n/2);
        temp[2]=pooling(n/2, row+n/2, col);
        temp[3]=pooling(n/2, row+n/2, col+n/2);
        sort(temp,temp+4);
        return temp[2];
    }
}

int main(){
    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<pooling(n, 0, 0);
    return 0;
}
