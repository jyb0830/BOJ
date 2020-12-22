//
//  bottle.cpp
//  baekjoon
//
//  Created by 지영본 on 2020/12/22.
//  Copyright © 2020 지영본. All rights reserved.
//  acmicpc.net/problem/1052
#include <iostream>

using namespace std;

int main(){
    int N,K,purchase=0, num1=0;
    
    cin>>N>>K;
    if(N<=0 || K<=0 || N>10000000 || K>1000)
        cout<<"-1";
    else{
    while(1){
        num1=0;
        for(int i=N;i>0;i-=i&-i)
            num1++;
        if(num1<=K) break;
        
        purchase += N&-N;
        N += N&-N;
    }
        cout<<purchase;
    }
        
    return 0;
}
