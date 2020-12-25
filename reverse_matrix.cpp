//
//  reverse_matrix.cpp
//  BOJ
//
//  Created by 지영본 on 2020/12/24.
//  acmicpc.net/problem/1080

#include <iostream>
using namespace std;

char A[50][50];
char B[50][50];

void reverse_matrix(int a,int b){
    for(int i=a;i<=a+2;i++)
    {
        for(int j=b;j<=b+2;j++)
        {
            if(A[i][j]=='0')
                A[i][j]='1';
            else
                A[i][j]='0';
        }
        
    }
}

int main(){
    int N,M,cost=0;
    
    cin>>N>>M;
    
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>A[i][j];
    
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>B[i][j];
    
    if(N<3||M<3)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(A[i][j]!=B[i][j])
                {
                    cout<<-1;
                    return 0;
                }
            }
        }
        cout<<0;
        return 0;
    }
    else
    {
        for(int i=0;i<N-2;i++)
        {
            for(int j=0;j<M-2;j++)
            {
                if(A[i][j]!=B[i][j])
                {
                    reverse_matrix(i,j);
                    cost++;
                }
                if(j==M-3)
                    if(A[i][j+1]!=B[i][j+1]||A[i][j+2]!=B[i][j+2])
                    {
                        cout<<-1;
                        return 0;
                    }
            }
            
        }
        for(int i=N-2;i<N;i++)
        {
            for(int j=0;j<M;j++)
                if(A[i][j]!=B[i][j])
                {
                    cout<<-1;
                    return 0;
                }
        }
        cout<<cost;
    }
    return 0;
}
