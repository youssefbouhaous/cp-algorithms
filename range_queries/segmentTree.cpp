#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

vector<int>tree;
int n,q;

int query(int a,int b){
    a+=n;b+=n;
    int ans=min(tree[a],tree[b]);
    while(a<=b){
        if(a%2==1) ans=min(ans,tree[a++]);
        if(b%2==0) ans=min(ans,tree[b--]);
        a/=2;b/=2;
    }
    return ans;
}

void add(int k,int x){
    k+=n;
    tree[k]=x;
    k/=2;
    while(k>=1){
        tree[k]=min(tree[k*2],tree[k*2+1]);
        k/=2;
    }
}

int main(){
    cin>>n>>q;
    tree.assign(2*n,1e9 +1);
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        add(i,a[i]);
    }
    while(q--){
        int op,l,r;
        cin>>op>>l>>r;
        if(op==1){
            add(l-1,r);
        }
        else{
            cout<<query(l-1,r-1)<<endl;
        }
    }
}
