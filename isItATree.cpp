#include<bits/stdc++.h>
using namespace std;
bool is;
void addEdge(vector<vector<int> > &graph,int n1,int n2){
    graph[n1].push_back(n2);
    graph[n2].push_back(n1);
}
void dfs(vector<vector<int> > &graph,vector<bool> &isVisited,int n){
    if(isVisited[n])return;
    isVisited[n]=true;
    //cout<<n<<endl;
    for(auto x: graph[n])dfs(graph,isVisited,x);
}
bool isTree(vector<vector<int> > &graph,vector<bool> &isVisited,int n){
    if(isVisited[n]||is==false){
        is=false;
        return is;
    }
    //for(auto x: graph)is=isTree(x);
    return is;
}

int main(){
    int n,e,n1,n2,e2,a_i;
    cin>>n>>e;
    vector<vector<int> > graph(n+1);
    e2=e;
    while(e--){
        cin>>n1>>n2;
        addEdge(graph,n1,n2);
    }
    vector<bool> isVisited(n+1,false);
    dfs(graph,isVisited,1);
    bool is =true;
    for(a_i=1;a_i<n;a_i++){
        if(!isVisited[a_i]){
                is=false;
                break;
        }
    }
    if(e2+1==n&&is)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}
