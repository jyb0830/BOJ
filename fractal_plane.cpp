//
//  fractal_plane.cpp
//  BOJ
//
//  Created by 지영본 on 2021/02/06.
//  acmicpc.net/problem/1030

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int s,n,k,r1,r2,c1,c2;
    cin>>s>>n>>k>>r1>>r2>>c1>>c2;
    
    char plane[r2-r1+1][c2-c1+1];
    
    for(int i=0;i<r2-r1+1;i++){
        for(int j=0;j<c2-c1+1;j++)
        plane[i][j]='0';
    }
    if(s==0) cout<<"0\n";
    
    else{
        while(s>0){
            int size=pow(n,s);
            int b_size=k*pow(n,s-1);
            for(int i=r1;i<=r2;i++){
                for(int j=c1;j<=c2;j++){
                    if(i%size>=(size-b_size)/2 && i%size<=size-((size-b_size)/2+1)){
                        if(j%size>=(size-b_size)/2 && j%size<=size-((size-b_size)/2+1)){
                            plane[i-r1][j-c1]='1';
                        }
                    }
                }
            }
            s--;
        }
        
        for(int i=0;i<r2-r1+1;i++){
            for(int j=0;j<c2-c1+1;j++){
                cout<<plane[i][j];
            }
            cout<<"\n";
        }
    }
    
    return 0;
}
