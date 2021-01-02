//
//  prime_sequence_sum.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/01.
//  acmicpc.net/problem/1644

#include <iostream>
using namespace std;

int main(){
    int N, size=4000001,sum=0, idx=2, cnt=0;
    cin>>N;
    
    bool prime[size+1];
    for(int i=2;i<size+1;i++)
        prime[i]=true;
    
    for(int i=2;i*i<=size;i++)
        if(prime[i])
            for(int j=i*i;j<=size;j+=i)
                prime[j]=false;
    
    for(int i=2;i<size+1;i++){
        if(prime[i])
            sum+=i;
        else
            continue;
        while(sum>N) {
            prime[idx]?sum-=idx++:idx++;
            if(prime[idx])
                sum-=idx++;
            else
                idx++;
        }
        cnt+=(sum==N);
    }
    cout<<cnt<<"\n";
    return 0;
}
