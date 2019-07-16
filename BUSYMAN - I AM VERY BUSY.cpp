#include<bits/stdc++.h>
using namespace std;

bool comp( pair < int, int > &p1, pair < int, int > &p2 ){
    return ( p1.second < p2.second );
}

int main(){
    int a_i, b_i, n, temp, testCase, n1, n2 ;
    cin>>testCase;
    while( testCase-- ){
        cin>>n;
        vector < pair < int, int > > v( n );
        for( a_i=0; a_i<n; a_i++ ){
            cin>>n1>>n2;
            v[a_i]=make_pair( n1, n2 );
        }

        sort ( v.begin(), v.end(), comp );

        int cont=0, mini=-1;

        for( a_i=0; a_i<n; a_i++ ){
            if( v[a_i].first >= mini ){
                cont++;
                mini = v[a_i].second;
            }
        }
        cout<<cont<<endl;
        v.clear();

    }
}
