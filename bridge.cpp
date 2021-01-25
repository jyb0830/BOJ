//
//  bridge.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/25.
//  acmicpc.net/problem/1010

#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int T;
    double N, M;
    cin>>T;
    double ans[T];
    
    for(int i=0;i<T;i++){
        ans[i]=1;
        cin>>N>>M;
        for(int j=0;j<N;j++) ans[i]*=(M-j)/(N-j);
    }
    for(int i=0;i<T;i++){
        printf("%.0lf\n",ans[i]);
    }
    return 0;
}
