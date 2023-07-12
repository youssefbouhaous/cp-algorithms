#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
map<int,vector>graph;
map<int,bool>visited;
void dfs(int start){
  visited[start]=true;
  queue<int>q;
  q.push(start);
  while(!q.empty()){
    int next=q.top();
    cout<<next<<" ";
    q.pop();
    for(int x:graph[next]){
      if(visited[x]!=true){
        q.push(x);
      }
    }
  }
}


int main(){
  return 0;
}
