//
//  sum_sequence.cpp
//  baekjoon
//
//  Created by 지영본 on 2020/07/28.
//  Copyright © 2020 지영본. All rights reserved.
//

#include <iostream>

using namespace std;

int main(){
    int N, L;
    bool answer=false;
    cin>>N>>L;
    
    for(int i=L;i<=100;i++)
    {
        if(i%2==0)  //i가 짝수인 경우
        {
            if((N%i)==(i/2))    // N을 i로 나눈 나머지가 i/2인 경우
            {
                if(N/i-(i/2)+1>=0)
                {
                    answer=true;
                    L=i;
                }
            }
        }
        
        else if(i%2==1)        //i가 홀수인 경우
        {
            if(N%i==0)  //N이 i로 나누어떨어지는 경우
            {
                if(N/i-i/2>=0)
                {
                    answer=true;
                    L=i;
                }
            }
            
        }
        if(answer==true)
            break;
    }
    if(answer==false)
        cout<<"-1\n";
    
    else if(L%2==0)
    {
        for(int i=0;i<L;i++)
        {
            cout<<N/L-(L/2)+1+i<<" ";
        }
    }
    else if(L%2==1)
    {
        for(int i=0;i<L;i++)
        {
            cout<<N/L-L/2+i<<" ";
        }
    }
    return 0;
}

// 70 4 --> 16 17 18 19
