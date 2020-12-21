//
//  bottle.cpp
//  baekjoon
//
//  Created by 지영본 on 2020/08/02.
//  Copyright © 2020 지영본. All rights reserved.
//

#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int main(){
    int N,K,n=0,a=0,temp,num=1,sum_a=0;
    stack<int> s, temp_s;
    
    
    cin>>N>>K;
    
    temp=N;
    while(temp!=0)
    {
        s.push(temp%2);
        if(temp%2==1)
            n++;
        temp=temp/2;
    }
    if(K>=n)
        cout<<-1<<"\n";
    else{
        temp_s=s;
        while(temp_s.top()==1)
        {
            temp_s.pop();
            a++;
            if(temp_s.empty())
                break;
        }
        
        if(K<=a)
        {
            while(num<N)
                num*=2;
            cout<<num-N<<"\n";
        }
        else
        {
            for(int i=0;i<temp_s.size()-1;i++)
                num*=2;
            cout<<num<<"\n";
        }
    }
    return 0;
}
