//
//  find_square.cpp
//  baekjoon
//
//  Created by 지영본 on 2020/07/30.
//  Copyright © 2020 지영본. All rights reserved.
//  acmicpc.net/problem/1025
// 행과 열이 모두 등차수열을 이루는 수를 나열했을 때, 제곱이 되는 수

#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

bool search(int num)
{
    int root;
    root=(int)sqrt(num);
    if(root*root==num)
        return true;
    
    else
        return false;
}

int main(){
    int N, M, ans=-1;

    cin>>N>>M;

    int arr[N][M];

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            scanf("%1d",&arr[i][j]);
    
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            for(int a=-i;i+a<N;a++)
            {
                for(int b=-j;b+j<M;b++)
                {
                    int num1=0, num2=0; //num1은 정방향, num2는 역방향
                    if(a==0&&b==0)
                    {
                        if(search(arr[i][j])==true&&arr[i][j]>ans)
                        {
                            ans=arr[i][j];
                            continue;
                        }
                        
                        
                        else
                            continue;
                        
                    }
                    for(int k=0; i+a*k<N && i+a*k>=0 && j+b*k<M && j+b*k>=0 ; k++)
                    {
                        num1*=10;
                        num1+=arr[i+a*k][j+b*k];
                        if(search(num1)==true && num1>ans)
                            ans=num1;
                        
                        num2+=pow(10,k)*arr[i+a*k][j+b*k];
                        if(search(num2)==true && num2>ans)
                            ans=num2;
                    }
                }
            }
        }
    }
    if(ans==-1)
        cout<<"-1\n";
    
    else
        cout<<ans<<"\n";
    
    return 0;
}
