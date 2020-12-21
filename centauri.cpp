//
//  centauri.cpp
//  baekjoon
//
//  Created by 지영본 on 2020/07/03.
//  Copyright © 2020 지영본. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int T;
    unsigned int s, d;
    
    cin>>T;
    int c[T];
    for(int i=0;i<T;i++)
    {
        int j=1;
        c[i]=0;
        cin>>s>>d;
        unsigned int dist=d-s;
        for(j=1;;j++)
        {
            if(j*j>dist)
                break;
        }
        if(dist==(j-1)*(j-1))
            c[i]=(j-1)*2-1;
        
        else if(dist-(j-1)*(j-1)<=(j*j-(j-1)*(j-1))/2)
            c[i]=j*2-2;
        else
            c[i]=j*2-1;
    }
    for(int i=0;i<T;i++)
    {
        cout<<c[i]<<"\n";
    }
    
    return 0;
}
