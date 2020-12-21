//
//  bridge.cpp
//  baekjoon
//
//  Created by 지영본 on 2020/07/02.
//  Copyright © 2020 지영본. All rights reserved.
//

#include <iostream>
using namespace std;

int bridge(int N, int M){
    int sum=0;
    if(N==1)
        return M;
    else if(N==M)
        return 1;
    else
    {
        sum=bridge(N-1,M-1)+bridge(N,M-1);
        return sum;
    }
    
}

int main(){
    int T, N, M;
    cin>>T;
    int sum[T];
    for(int j=0;j<T;j++)
    {
        cin>>N>>M;
        sum[j]=bridge(N, M);
    }
    for(int i=0;i<T;i++)
        cout<<sum[i]<<"\n";
    
    return 0;
}
