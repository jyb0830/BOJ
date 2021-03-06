//
//  easy_step_number.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/14.
//  acmicpc.net/problem/10844

#include <iostream>

using namespace std;

int main(){
    int N, sum=0;
    int arr[101][10]={};
    
    for(int i=1;i<10;i++) arr[1][i]=1;
    
    cin>>N;
    
    for(int i=2;i<=N;i++){
        for(int j=0;j<10;j++){
            if(j==0)
                arr[i][0]=arr[i-1][1];
            else if(j==9)
                arr[i][9]=arr[i-1][8];
            else{
                arr[i][j]=(arr[i-1][j-1]+arr[i-1][j+1])%1000000000;
            }
        }
    }
    for(int i=0;i<10;i++) sum= (sum+arr[N][i])%1000000000;
    
    cout<<sum;
    
    return 0;
}
