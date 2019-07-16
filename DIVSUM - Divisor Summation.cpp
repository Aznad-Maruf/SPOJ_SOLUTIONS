#include<bits/stdc++.h>
using namespace std;

int main(){
    int testCase,n,a_i,ans;
    cin>>testCase;
    while(testCase--){
        cin>>n;
        ans=0;
        int l=sqrt(n);
        for(a_i=2;a_i<=l;a_i++){
            if(n%a_i==0){ans+=a_i;
            if(a_i!=n/a_i)ans+=(n/a_i);
            }
        }
        if(n>1)ans+=1;
        cout<<ans<<endl;
    }
}
