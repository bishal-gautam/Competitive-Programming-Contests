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
#define MX     2005
#define inf    1000000010000
#define MD     1000000007LL
#define eps    1e-9
///===============================///

double t,d[MX],s[MX];
int n;

double F(double c) {
    double ret=0.0;
    for(int i=1; i<=n; i++) {
        ret+=( d[i]/(s[i]+c) );
    }
    return ret;
}

int main() {
    int tc,cs=1,i,j,k;
    //S(tc);
    tc=1;
    while(tc--) {
        cin>>n>>t;
        double lo=-inf;
        for(i=1; i<=n; i++) {
            cin>>d[i]>>s[i];
            lo=max(lo,0.0-s[i]);
        }
        //cout<<lo<<endl;
        double hi=0.5*inf;
        fr(i,1,1000) {
            double md=(hi+lo)*0.5;
            double tmm=F(md);
            if( tmm<=t ) {
                hi=md;
            } else lo=md;
        }
        cout<<fixed<<setprecision(12)<<hi<<endl;
    }
    return 0;
}
