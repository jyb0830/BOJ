//
//  book_page.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/08.
//  acmicpc.net/problem/1019

#include <iostream>
using namespace std;
int arr[10];

void calc(int num, int ten){
    while(num>0){
        arr[num%10]+=ten;
        num/=10;
    }
}

void page_num(int A, int N, int ten){
    while(A%10!=0&&A<=N){
        calc(A,ten);
        A++;
    }
    if(A>N) return;
    
    while(N%10!=9&&N>=A){
        calc(N,ten);
        N--;
    }
    for(int i=0;i<10;i++)
        arr[i]+=(N/10-A/10+1)*ten;
    
    page_num(A/10, N/10, ten*10);
    
}
int main(){
    int N;
    cin>>N;
    page_num(1,N,1);
    for(int i=0;i<10;i++)
    cout<<arr[i]<<" ";
    return 0;
}
