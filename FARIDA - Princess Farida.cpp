#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL maxi;
LL maxiCoin( vector< int > & v, int p, int n, vector< LL > &d ){
    if(p>=n)return 0 ;
    if(d[p]!=-1) return d[p];
    //cout<<maxi<<endl;
    return d[p]=maxi = max( v[p]+maxiCoin( v, p+2, n, d ) , maxiCoin( v, p+1, n, d ) );
    //cout<<p<<"----> "<<maxi<<endl;
}
int main(){
    int testCase, a_i, b_i, a_t=0, temp, n, m;
    cin>>testCase;
    while(testCase-- ){
        cin>>n;
        vector < int > v(n);
        vector< LL > d( n , -1);
        for( a_i=0; a_i< n; a_i++ )cin>>v[a_i];

        maxi=0;
        cout<<"Case "<<++a_t<<": "<<maxiCoin( v, 0, n, d )<<endl;;


    }
}
