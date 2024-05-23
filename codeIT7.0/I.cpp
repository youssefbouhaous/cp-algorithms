#include <iostream>
#include <vector>
#include <map>
using namespace std;



map<int,vector<int>>graph;

map<int,bool>visited;

bool solve(int a,int b){
    visited[a]=true;
    for(auto x:graph[a]){
        if(x==b){
            cout<<"YES\n";
            return true;
        }
        if(!visited[x]){
            if(solve(x,b)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        graph[x].push_back(y);
    }

    while (q--)
    {
        int a,b;cin>>a>>b;
        if(!solve(a,b)){
            cout<<"NO\n";
        }
        visited.clear();
    }
    return 0;
}
