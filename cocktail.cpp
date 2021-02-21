//
//  cocktail.cpp
//  BOJ
//
//  Created by 지영본 on 2021/02/17.
//  acmicpc.net/problem/1033

#include <iostream>

using  namespace std;

int64_t gcd(int64_t a, int64_t b){
    return b ? gcd(b, a%b) : a;
}

int64_t lcm(int64_t a, int64_t b){
    return a*b/gcd(a,b);
}

int main(){
    int64_t n, num=1;
    cin>>n;
    int64_t material[n];
    int64_t a[n-1],b[n-1],p[n-1],q[n-1];
    
    for(int i=0;i<n;i++){
        material[i]=0;
    }
    
    if(n==1) cout<<"1\n";
    
    else{
        for(int64_t i=0;i<n-1;i++){
            cin>>a[i]>>b[i]>>p[i]>>q[i];
            int64_t temp = gcd(p[i],q[i]);
            p[i]/= temp;
            q[i]/= temp;
            num*=p[i]*q[i];
        }
        material[a[0]]=num*p[0];
        material[b[0]]=num*q[0];
        int64_t count=2;
        while(count!=n){
            for(int64_t i=1;i<n-1;i++){
                if(material[a[i]]==0 && material[b[i]]==0) {
                    continue;
                }
                
                else if(material[a[i]]!=0 && material[b[i]]!=0) {
                    continue;
                }
                
                else if(material[a[i]]!=0) {
                    material[b[i]]=material[a[i]]/p[i]*q[i];
                    count++;
                }

                else if(material[b[i]]!=0) {
                    material[a[i]]=material[b[i]]/q[i]*p[i];
                    count++;
                }
            }
        }
        num=material[0];
        for(int64_t i=1;i<n;i++) num=gcd(num, material[i]);
        for(int64_t i=0;i<n;i++) cout<<material[i]/num<<" ";
    }
    
    return 0;
}
