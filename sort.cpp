//
//  sort.cpp
//  BOJ
//
//  Created by 지영본 on 2021/04/11.
//  acmicpc.net/problem/1083

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, s, cnt=0;
    cin>>n;
    vector<int> v, complete, temp;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    cin>>s;
    temp=v;
    sort(temp.begin(), temp.end());
    for(int i=(int)v.size()-1;i>=0;i--){
        complete.push_back(temp[i]);
    }
    int idx=0, m_idx=(int)v.size()-1;
    while(cnt<s && v!=complete){
//        cout<<"idx : "<<idx<<"\n";
//        cout<<"m_idx : "<<m_idx<<"\n";
//        cout<<"cnt : "<<cnt<<"\n";
//        cout<<"\n";
        for(int i=idx;i<v.size();i++){
            if(v[i]==temp[m_idx]){
                if(cnt+i-idx<=s){   //가장 큰 수를 idx 위치로 옮길 수 있을 때
                    int t=v[i];
                    for(int j=i;j>idx;j--){
                        v[j]=v[j-1];
                    }
                    v[idx]=t;
                    
                    cnt+=(i-idx);
                    idx++;
                    temp[m_idx]=0;
                    sort(temp.begin(), temp.end());
                    m_idx=(int)v.size()-1;
                    break;
                }
                
                else{
                    m_idx--;
                    break;
                }
            }
        }
    }
    
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    
    return 0;
}

