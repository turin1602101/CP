#include<bits/stdc++.h>
using namespace std;
#define X           first
#define Y           second
#define N           710
#define pb          push_back
#define pp          pop_back
#define mk          make_pair
#define PI          acos(-1)
#define EPS         1e-9
#define INF         1<<30
#define TC(t)       int t;cin>>t;while(t--)
#define line        '\n'
#define space       ' '
#define redian      180/PI
#define all(x)      (x.begin(),x.end())
#define Sort(x)     sort(all(x))
#define mem(a,b)    memset(a,b,sizeof(a))
#define loopv(p,v)  for(auto p:(v))
#define loop(a,b,c) for(int a=(b);a<(c);a++)
#define loopr(a,b,c)for(int a=(b);a>=(c);a--)
#define faster      ios_base::sync_with_stdio(0);cin.tie(0);

const int MOD=1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<ll,ll> pii;
typedef pair<int,string> psi;
typedef map<int,int>mii;
/*      direction
int x4[]= {1,-1,0,0};
int y4[]= {0,0,1,-1};
int x8[]= {0,0,+1,-1,-1,+1,-1,+1};
int y8[]= {-1,+1,0,0,+1,+1,-1,-1};
int kx[]={2,2,-2,-2,1,-1,1,-1};
int ky[]={1,-1,1,-1,2,2,-2,-2};*/
bool p[N];
vi prime;
int dp[500002];
void sieve()
{
    prime.pb(2);
    for(int i=3;i<N;i+=2)
    {
        if(!p[i])
        {
            for(int j=2*i;j<N;j+=i)p[j]=1;
            prime.pb(i);
        }
    }
}
int pfactor(int n)
{
    int i=0,pf=prime[i],ans=0;
    while(pf*pf<=n)
    {
        if(n%pf==0)
        {
            while(n%pf==0)n/=pf,ans+=pf;
        }
        pf=prime[++i];
    }
    if(n>1)ans+=n;
    return ans;
}
int dpsolve(int n)
{
    int i=pfactor(n);
    if(i==n)return 1;
    if(dp[n])return dp[n];
    return dpsolve(i)+1;
}
void solve()
{
    dp[2]=dp[3]=dp[4]=dp[5]=1;
    loop(i,6,500001)dp[i]=dpsolve(i);
}
int main() {
    faster
    sieve();
    solve();
    int cs=0,t;cin>>t;
    while(t--)
    {
        int l,u,mx=0;cin>>l>>u;
        if(l>u)swap(l,u);
        loop(i,l,u+1)mx=max(mx,dp[i]);
        cout<<"Case #"<<++cs<<":\n"<<mx<<line;
    }
    return 0;
    }
