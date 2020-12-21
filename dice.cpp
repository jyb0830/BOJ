//
//  dice.cpp
//  baekjoon
//
//  Created by 지영본 on 2020/07/31.
//  Copyright © 2020 지영본. All rights reserved.
//

//1차 오류 : 주사위 맞은편 칸을 고려하지 않고 최솟값 3개만을 찾음
//2차 오류 : index 초기화 실수
//3차 오류 : max 초기화 실수, 자료형 오버플로우

#include <iostream>

using namespace std;


int main(){
    long N,a,b,c,index,max, sum=0; // 주사위에 적혀있는 수의 합을 구할 때, 가장 작은 세 개의 수만 사용하므로 이를 저장하기 위한 변수 a,b,c
    
    cin>>N;
    
    long d[6],temp[6];
    for(long i=0;i<6;i++)
    {
        cin>>d[i];
        temp[i]=d[i];
    }
    a=d[0];
    index=0;
    max=d[0];
    for(long i=1;i<6;i++)
    {
        if(d[i]<a)
        {
            a=d[i];
            index=i;
        }
        if(d[i]>max)
            max=d[i];
    }
    d[index]=51;
    d[5-index]=51;
    
    
    
    b=d[0];
    index=0;
    for(long i=1;i<6;i++)
    {
        if(d[i]<b)
        {
            b=d[i];
            index=i;
        }
    }
    d[index]=51;
    d[5-index]=51;
    
    
    c=d[0];
    for(long i=1;i<6;i++)
        if(d[i]<c)
            c=d[i];

    
    if(N==1)
    {
        for(long i=0;i<6;i++)
            sum+=temp[i];
        
        sum-=max;
    }
    
    else
        sum=4*N*(b-a+a*N)+a*(N-2)*(N-2)+4*b*(N-2)+4*c;
    
    cout<<sum<<"\n";
    
    
    
    return 0;
}
