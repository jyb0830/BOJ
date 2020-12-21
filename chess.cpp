//
//  chess.cpp
//  baekjoon
//
//  Created by 지영본 on 2020/07/01.
//  Copyright © 2020 지영본. All rights reserved.
//


#include <iostream>
using namespace std;

int main(){
    int T;
    
    cin>>T;
    int num[T];
    for(int i=0;i<T;i++)
    {
        int n, s_x,s_y, s_count=0, d_x, d_y,d_count=0;
        cin>>s_x>>s_y>>d_x>>d_y;
        cin>>n;
        int c_x[n],c_y[n], r[n],S[n],D[n];
        
        
        for(int j=0;j<n;j++)
            cin>>c_x[j]>>c_y[j]>>r[j];
        
        for(int k=0;k<n;k++)
        {
            int dist_s=((s_x-c_x[k])*(s_x-c_x[k]))+((s_y-c_y[k])*(s_y-c_y[k]));
            int dist_d=((d_x-c_x[k])*(d_x-c_x[k]))+((d_y-c_y[k])*(d_y-c_y[k]));
            if(dist_s<r[k]*r[k])
            {
                S[k]=1;
                s_count++;
            }
            else
                S[k]=0;
            if(dist_d<r[k]*r[k])
            {
                D[k]=1;
                d_count++;
            }
            else
                D[k]=0;
        }
        for(int k=0;k<n;k++)
        {
            if(S[k]==1&&D[k]==1)
            {
                s_count--;
                d_count--;
            }
        }
        num[i]=s_count+d_count;
    }
    for(int i=0;i<T;i++)
    {
        cout<<num[i]<<"\n";
    }
    return 0;
}
