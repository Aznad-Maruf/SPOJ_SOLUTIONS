#include<bits/stdc++.h>
using namespace std;

#define VVi vector<vector<int> >

void addEdge(VVi &graph,int f1,int f2){
    graph[f1].push_back(f2);
    graph[f2].push_back(f1);
}

void dfs(VVi &graph,vector<bool> &isVisited,int n){
    if(isVisited[n])return;
    isVisited[n]=true;
    for(auto x: graph[n]){
        dfs(graph,isVisited,x);
    }
}

int main(){
    int testCase,students,friends,f1,f2,a_i;
    cin>>testCase;
    while(testCase--){
        cin>>students;
        VVi graph(students);
        cin>>friends;
        while(friends--){
            cin>>f1>>f2;
            addEdge(graph,f1,f2);
        }
        vector<bool> isVisited(students,false);
        int cont=0;
        for(a_i=0;a_i<students;a_i++){
            if(!isVisited[a_i]){
                cont++;
                dfs(graph,isVisited,a_i);
            }
        }
        cout<<cont<<endl;
    }
}
