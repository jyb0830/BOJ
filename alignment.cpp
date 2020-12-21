//
//  alignment.cpp
//  baekjoon
//
//  Created by 지영본 on 2020/07/26.
//  Copyright © 2020 지영본. All rights reserved.
//  acmicpc.net/problem/1015

#include <iostream>

using namespace std;

int main(){
    int N;
    cin>>N;
    int A[N],B[N];
    
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
        B[i]=0;
    }
    
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(A[i]>A[j])
                B[i]++;
            else if(A[i]<A[j])
                B[j]++;
            else if(A[i]==A[j])
                B[j]++;
        }
    }
    
    for(int i=0;i<N;i++)
        cout<<B[i]<<" ";
    
    
    return 0;
}
