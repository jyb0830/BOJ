//
//  num_square.cpp
//  baekjoon
//
//  Created by 지영본 on 2020/08/02.
//  Copyright © 2020 지영본. All rights reserved.
//  acmicpc.net/problem/1051

#include <iostream>

using namespace std;

int main(){
    int N, M, max, count=0;
    
    cin>>N>>M;
    
    char arr[N][M];
    
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>arr[i][j];
    
    if(N<M)
        max=N;
    else
        max=M;
    
    for(int k=max-1;k>=0;k--)
    {
        count=0;
        for(int i=0;i+k<N;i++)
        {
            for(int j=0;j+k<M;j++)
            {
                if(arr[i][j] == arr[i][j+k] && arr[i][j+k] == arr[i+k][j] && arr[i+k][j] == arr[i+k][j+k])
                    count++;
                else
                    continue;
            }
        }
        if(count>0)
        {
            cout<<(k+1)*(k+1)<<"\n";
            break;
        }
    }
    
    
    return 0;
}
