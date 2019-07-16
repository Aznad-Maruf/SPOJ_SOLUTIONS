#include<bits/stdc++.h>
using namespace std;

vector < int > primes;
vector < vector < int > > graph;

void sieve(){

    vector < bool > temp( 10000, true );
    int a_i, b_i, s=10000, l=sqrt(s);
    for( a_i=2; a_i<=l; a_i++ ){
            if( temp[a_i] == false ) continue;
        for( b_i=a_i+a_i; b_i<=s; b_i+=a_i ){
            temp[b_i]=false;
        }
    }

    for( a_i=1000; a_i<=9999; a_i++ ) if( temp[a_i] ) primes.push_back(a_i);

}

void addEdge(){
    int a_i, b_i, c_i, temp, r1, r2, cont, s=primes.size();
    for( a_i=0; a_i<s; a_i++ ){
        for( b_i=0; b_i<s; b_i++){
            c_i=10;
            int n1=primes[a_i], n2=primes[b_i];
            cont=0;
            while( n1 > 0 ){
                r1=n1%c_i;
                r2=n2%c_i;
                n1/=c_i;
                n2/=c_i;
                if( r1 == r2 ) cont++;
                //cout<<n1<<endl;

            }
            if( cont == 3 ) graph[primes[a_i]].push_back( primes[b_i] );
        }
    }
}


int bfs( int n1, int n2 ){
    if( n1==n2 ) return 0;
    int a_i, b_i, c_i, temp, ans, limit=10e5, tp;
    queue< int > q;
    vector < int > d( 10e5, 0 );
    vector < int > is( 10e5, false );
    q.push(n1);
    while( !q.empty() ){
        tp=q.front();
        is[tp]=true;
        q.pop();
        temp=10;
        for( int x : graph[tp] ){
                if( is[x] ) continue;
                q.push(x);
            d[x]=d[tp]+1;
            //cout<<d[x]<<endl;
            if( x==n2 ) return d[x];
            //if( temp<0)return d[x];
            is[x]=true;
        }
        temp--;
    }

}

int main(){
    int a_i, b_i, n, temp, p, s, limit=100000, testCase, n1, n2;
    sieve();
    s=primes.size();
    graph.resize( limit );

    addEdge();

//cout<<"b";
    //for( int x : graph[1873] ) cout<<x<<endl;

    cin>>testCase;
    while( testCase-- ){
        cin>>n1>>n2;
        cout<<bfs( n1, n2 )<<endl;
    }

}
