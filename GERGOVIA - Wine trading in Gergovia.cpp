#include<bits/stdc++.h>
using namespace std;

vector < long long > v;

int main(){
    long long a_i, b_i, temp, n, ans;
    while( cin>>n ){
        if( n==0 ) break;
        v.resize( n );
        for( a_i=0; a_i<n; a_i++ ) cin>>v[a_i];
        temp =0, ans =0;
        for( a_i=0; a_i<n; a_i++ ){
            temp+=v[a_i];
            ans+= abs( temp );
        }
        cout<<ans<<endl;
    }
}
