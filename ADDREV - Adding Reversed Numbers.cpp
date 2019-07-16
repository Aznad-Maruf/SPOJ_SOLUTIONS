#include<bits/stdc++.h>
using namespace std;

int main(){
    int testCase,n1,n2,sum,rn1,rn2,rs;
    cin>>testCase;
    while(testCase--){
        cin>>n1>>n2;
        rn1=0,rn2=0,rs=0;
        while(n1>0){
            int r=n1%10;
            n1/=10;
            rn1=rn1*10+r;
        }
        while(n2>0){
            int r=n2%10;
            n2/=10;
            rn2=rn2*10+r;
        }
        sum=rn1+rn2;
        while(sum>0){
            int r=sum%10;
            sum/=10;
            rs=rs*10+r;
        }
        cout<<rs<<endl;
    }
}
