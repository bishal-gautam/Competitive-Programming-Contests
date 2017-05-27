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
///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; //Not Leap Year
///int dx[]= {1,0,-1,0};int dy[]= {0,1,0,-1}; //4 Direction
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
///int dx[]= {2,1,-1,-2,-2,-1,1,2};int dy[]= {1,2,2,1,-1,-2,-2,-1}; //Knight Direction
///==========CONSTANTS=============///
///  Digit     0123456789012345678 ///
#define MX     5005
#define inf    1000000010
#define MD     1000000007
#define eps    1e-9
///===============================///

int n,ar[MX+2],dp[MX+2],Fst[MX+2],Lst[MX+2];
int Mp[MX+2];
int Pre[MX+2][MX+2];

int go(int p) {
    if(p>=n+1) return 0;
    int &ret=dp[ p ];
    if(ret!=-1) return ret;
    ret=go(p+1);
    int mn=Fst[ ar[p] ];
    int mx=Lst[ ar[p] ];
    for(int i=p; i<=n; i++) {
        mn=min( mn, Fst[ ar[i] ] );
        mx=max( mx, Lst[ ar[i] ] );
        if( mn>=p && mx<=i ) {
            ret=max(ret, Pre[ p ][ i ]+go( i+1 ));
        }
    }
    return ret;
}

int main() {
    S(n);
    int ans=0,mx=0;
    for(int i=1; i<=n; i++) {
        S(ar[i]);
        if( !Mp[ ar[i] ] ){
             Mp[ ar[i] ]=1;
             ans^=ar[i];
        }
        mx=max(mx,ar[i]);
    }
    for(int i=1; i<=n; i++) {
        Lst[ ar[i] ]=i;
    }
    for(int i=n; i>=1; i--) {
        Fst[ ar[i] ]=i;
    }
    //cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        int xr=0;
        for(int j=0;j<=mx;j++)Mp[ j ]=0;
        for(int j=i;j<=n;j++){
            if( !Mp[ ar[j] ] ){
                xr^=ar[ j ];
                Mp[ ar[j] ]=1;
            }
            Pre[i][j]=xr;
        }
    }
    SET(dp);
    ans=max(ans,go(1));
    printf("%d\n",ans);

    return 0;
}

