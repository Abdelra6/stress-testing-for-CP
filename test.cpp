#include<bits/stdc++.h>
using namespace std;
#define int long long
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
//returns random number between l and r but not ex
int rand_ex(int l, int r,int ex){
 set<int>st;
    uniform_int_distribution<int> uid(l, r);
    int x=uid(rng);
    while(x==ex)
        x=uid(rng);
    return x;
}
//returns random array
void num(int l, int r, int n) {
    for (int i = 0; i < n; ++i)
    {
        cout << rand(l,r) << " ";
    }
    cout<<"\n";
}
//returns n distinct numbers 
void num_dis(int l, int r, int n) {
    set<int>st;
    for (int i = 0; i < n; ++i)
    {
        int x=rand(l,r);
        while(st.find(x)!=st.end())
            x=rand(l,r);
        cout<<x<<" ";
        st.insert(x);

            }
    cout<<"\n";
}
//returns an increasing array
void inc_arr(int l,int r,int n)
{
    bool vis[r+1];
    for(int i=0;i<=r;i++)
        vis[i]=false;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int x=rand(l,r);
        while(vis[x])
x=rand(l,r);
vis[x]=true;
arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
//return a random permutation
void rand_permutation(int n)
{
    vector<int>arr;
    for(int i=1;i<=n;i++)
        arr.push_back(i);
    random_shuffle(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}
//returns random queries 
 void rand_queries(int q,int n)
 {
    for(int i=0;i<q;i++)
        {
            int l=rand(1,n),r=rand(l,n);
          if(l==n)
            cout<<l<<" "<<r<<"\n";
        else if((r-l+1)%2==1)
        {
            if(r==n)
                r--;
            else r++;
            cout<<l<<" "<<r<<"\n";
        }
        else cout<<l<<" "<<r<<"\n";
        }
 }
//Random n real numbers between l and r with dig decimal places
void real(int l, int r, int dig, int n) {
    for (int i = 0; i < n; ++i)
    {
        cout << rand(l,r) <<"."<<rand(0,pow(10,dig)-1)<< " ";
    }
}
// Random n strings of length l
void str(int l, int n) {
    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < l; ++j) {
           cout<<(char)rand('a','z');
        }
       cout<<"\n";
    }
}
//returns n random strings of length l with chars between ll and rr
void str(int l, int n,int ll,int rr) {
    ll--,rr--;
    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < l; ++j) {
           cout<<(char)((rand(ll,rr))+'A');
        }
       cout<<"\n";
    }
}
// Random n strings of max length l
void strmx(int mxlen, int n) {
    for (int i = 0; i < n; ++i)
    {
        int l = rand(1,mxlen);
        for(int j = 0; j < l; ++j) {
            int v = rand(1,150);
            if(3%3==0) cout<<(char)rand('a','z');
            else if(v%3==1) cout<<(char)rand('A','Z');
            else cout<<rand(0,9);
        }
        cout<<" ";
    }
}
  set<pair<int,int>>st;
  //return random graph
void rand_graph(int n,int m)
{

for(int i=0;i<m;i++)
{
    int x=rand(1,n),y=rand(1,n);
    while(st.find({x,y})!=st.end()||x==y)
    {
        x=rand(1,n),y=rand(1,n);
    }
    st.insert({x,y});
    st.insert({y,x});
    cout<<x<<" "<<y<<"\n";
}
} 
// Random tree of n nodes
void tree(int n) {
    int prufer[n];
    for ( int i = 0; i < n; i++ ){
        prufer[i] = rand(1,n);
    }
    int m = n-2;
    int vertices = m + 2; 
    int vertex_set[vertices]; 
    for (int i = 0; i < vertices; i++) 
        vertex_set[i] = 0; 
    for (int i = 0; i < vertices - 2; i++) 
        vertex_set[prufer[i] - 1] += 1; 
    int last=-1;
    int j = 0; 
    for (int i = 0; i < vertices - 2; i++) { 
        for (j = 0; j < vertices; j++) { 
            if (vertex_set[j] == 0) { 
                vertex_set[j] = -1; 
                st.insert({j+1,prufer[i]});
                cout << (j + 1) << " " << prufer[i] << '\n'; 
                vertex_set[prufer[i] - 1]--; 
                break; 
            } 
        } 
    } 
    j = 0; 
    for (int i = 0; i < vertices; i++) { 
        if (vertex_set[i] == 0 && j == 0) { 
            last=i+1;
            cout << (i + 1) << " "; 
            j++; 
        } 
        else if (vertex_set[i] == 0 && j == 1) {
            cout << (i + 1) << "\n"; 
            st.insert({last,i+1});
            last=-1;
        }
    }
}
bool notbalanced(string x)
{
    int zz=0,zzz=0;
    for(int i=0;i<x.size();i++)
    {
        zz=0,zzz=0;
        for(int j=i;j<x.size();j++)
        {
            if(x[j]=='L')
                zz++;
            else zzz++;
            if(abs(zz-zzz)>=3){

                return false;
            }
        }
    }
    return true;
}
signed main()
{
   // freopen("input_file","w",stdout);
    // cout<<1<<"\n";
int N=rand(1,(int)6);
cout<<N<<"\n";
num(1,1000,N);




}
