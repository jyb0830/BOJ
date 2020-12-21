//
//  treasure.cpp
//  baekjoon
//
//  Created by 지영본 on 2020/07/31.
//  Copyright © 2020 지영본. All rights reserved.
//

#include <iostream>

using namespace std;

int main(){
    int N,S=0;
    
    cin>>N;
    
    int A[N],B[N];
    int A_arr[N], B_arr[N];
    
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
        A_arr[i]=0;
    }
    
    for(int i=0;i<N;i++)
    {
        cin>>B[i];
        B_arr[i]=0;
    }
    
    for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(A[i]>=A[j])
                A_arr[i]++;
            else
                A_arr[j]++;
            
            if(B[i]>=B[j])
                B_arr[j]++;
            else
                B_arr[i]++;
        }
    }
    for(int i=0; i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(A_arr[i]==B_arr[j])
            {
                S+=A[i]*B[j];
                continue;
            }
        }
    }
    cout<<S<<"\n";
    
    return 0;
}
