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

ll x,y,xx,yy,l,r;
vector<ll>vx;
vector<ll>vy;
vector<ll>v;
int main() {
    SL2(x,y);
    SL2(l,r);

    vx.pb(1LL);
    xx=1LL;
    while( true ){
        if( xx<=( r/x ) ){
            xx=(xx*x);
            vx.pb( xx );
        }
        else break;
    }

    vy.pb(1LL);
    yy=1LL;
    while( true ){
        if( yy<=( r/y ) ){
            yy=(yy*y);
            vy.pb( yy );
        }
        else break;
    }

    int lx=SZ(vx);
    int ly=SZ(vy);

    for(int i=0;i<lx;i++){
        for(int j=0;j<ly;j++){
            ll vl=vx[ i ]+vy[ j ];
            if( vl>=l && vl<=r ){
                v.pb( vl );
            }
        }
    }

    sort( all(v) );
    int sz=SZ(v);
    ll mx=0;
    if( !sz ){
        mx=r-l+1;
    }
    else{
        ll lst=l-1;
        for(int i=0;i<sz;i++){
            mx=max( mx, v[i]-lst-1 );
            lst=v[ i ];
        }
        mx=max( mx, r-lst );
    }

    printf("%lld\n",mx);

    return 0;
}

