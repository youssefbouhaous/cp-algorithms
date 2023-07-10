#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int,vector<int>>OurGraph;
map<int,bool>visited;

void dfs(int s){
  cout<<s<<"::";
  visited[s]=true;
  for(int next:OurGraph[s]){
    if(visited[next]!=true){
      dfs(next);
    }
  }
}


int main(){
  dfs(0); //let's start from node 0
  return 0;
}
