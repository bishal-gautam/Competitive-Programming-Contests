///==================================================///
///                HELLO WORLD !!                    ///
///                  IT'S ME                         ///
///               BISHAL GAUTAM                      ///
///         [ bsal.gautam16@gmail.com ]              ///
///==================================================///
#include<bits/stdc++.h>
#define PI acos(-1.0)
#define X first
#define Y second
#define mpp make_pair
#define nl printf("\n")
#define SZ(x) (int)(x.size())
#define pb(x) push_back(x)
#define pii pair<int,int>
#define pll pair<ll,ll>
///---------------------
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define SL(a) scanf("%lld",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
///------------------------------------
#define all(v) v.begin(),v.end()
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define fr(i,a,n) for(int i=a;i<=n;i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; //Not Leap Year
///int dx[]= {1,0,-1,0};int dy[]= {0,1,0,-1}; //4 Direction
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
///int dx[]= {2,1,-1,-2,-2,-1,1,2};int dy[]= {1,2,2,1,-1,-2,-2,-1}; //Knight Direction
///==========CONSTANTS=============///
///  Digit     0123456789012345678 ///
#define MX     305
#define inf    10000000100000000LL
#define MD     1000000007LL
#define eps    1e-9
///===============================///
#define SQR(x) ((x)*(x))

ll r[MX+2],p[MX+2],pre[MX][MX],dp[MX+2][MX+2];
int n,k;

ll Optimum(int i,int j) {
    ll mn=inf;
    for(ll k=r[i]; k<=r[j]; k++) {
        ll sm=0LL;
        for(int id=i; id<=j; id++) {
            sm+=SQR( r[id]-k )*p[ id ];
        }
        mn=min(mn,sm);
    }
    return mn;
}

ll go(int p,int cnt) {
   // cout<<p<< " :: "<<cnt<<endl;
    if( cnt>k ) return inf;
    if( p==n+1 ) {
            return 0;
    }
    ll &ret=dp[ p ][ cnt ];
    if(ret!=-1) return ret;
    ret=inf;
    for(int i=p; i<=n; i++) {
        ret=min(ret, pre[ p ][ i ]+go( i+1, cnt+1 ) );
    }
    return ret;
}

int main() {
    S2(n,k);
    fr(i,1,n) {
        SL2( r[i],p[i] );
    }
    fr(i,1,n){
        fr(j,i,n){
            pre[i][j]=Optimum(i,j);
           // cout<<i<< " : "<<j<< " => "<<pre[i][j]<<endl;
        }
    }
    SET(dp);
    printf("%lld\n",go(1,0) );

    return 0;
}
