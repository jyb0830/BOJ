//
//  2-friend.cpp
//  BOJ
//
//  Created by 지영본 on 2020/12/22.
//  acmicpc.net/problem/1058

#include <iostream>
using namespace std;

int main(){
    int N,max=0;
    
    cin>>N;
    char frnd[N][N];
    int count_F[N];
    
    for(int i=0;i<N;i++)
    {
        count_F[i]=0;
        for(int j=0;j<N;j++)
            cin>>frnd[i][j];
    }
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(frnd[i][j]=='Y')
            {
                for(int k=i+1;k<N;k++)
                {
                    if(frnd[k][j]=='Y'&&frnd[i][k]=='N')
                    {
                        frnd[i][k]='F';
                        frnd[k][i]='F';
                    }
                }
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
            if(frnd[i][j]=='F'||frnd[i][j]=='Y')
            {
                count_F[i]++;
                count_F[j]++;
            }
    }
    for(int i=0;i<N;i++)
    {
        if(count_F[i]>max)
            max=count_F[i];
    }
    cout<<max;
    
    return 0;
}
