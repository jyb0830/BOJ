//
//  Z.cpp
//  BOJ
//
//  Created by 지영본 on 2020/12/24.
//  acmicpc.net/problem/1074

#include <iostream>
#include <cmath>
using namespace std;

int visit_num=0;

int find_visit(int N, int r, int c){
    
    if(N==1)
    {
        if(r==0&&c==0)
            return visit_num;
        else if(r==0&&c==1)
            return visit_num+1;
        else if(r==1&&c==0)
            return visit_num+2;
        else if(r==1&&c==1)
            return visit_num+3;
    }
    else
    {
        if(r<pow(2,N-1))
        {
            if(c<pow(2,N-1))
                return find_visit(N-1, r, c);
            else
            {
                visit_num+=pow(2,2*N-2);
                return find_visit(N-1, r, c-pow(2,N-1));
            }
        }
        else
        {
            if(c<pow(2,N-1))
            {
                visit_num+=pow(2,2*N-2)*2;
                return find_visit(N-1,r-pow(2,N-1),c);
            }
            else
            {
                visit_num+=pow(2,2*N-2)*3;
                return find_visit(N-1,r-pow(2,N-1),c-pow(2,N-1));
            }
        }
    }
    return 0;
}


int main(){
    int N,r,c, num;
    
    cin>>N>>r>>c;
    
    num=find_visit(N,r,c);
    cout<<num;
    return 0;
}
