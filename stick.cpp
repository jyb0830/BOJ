//
//  stick.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/13.
//  acmicpc.net/problem/1094

#include <iostream>

using namespace std;

int main(){
    int X,cnt=0;
    cin>>X;
    
    for(int i=0;(1<<i)<=X;i++){
        if(((1<<i)&X)!=0)
            cnt++;
    }
    cout<<cnt;
    return 0;
}
