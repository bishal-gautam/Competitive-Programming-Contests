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
#define MX     200005
#define inf    1000000010
#define MD     1000000007LL
#define eps    1e-9
///===============================///

template<typename T> T BigMod(T b,T p,T m) {
    T r=1;
    while(p) {
        if(p&1)r=(r*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return r;
}

bool vis[MX+2];
int pl,pr[MX+2];
map<int,int>p;

void Seive( ) {
    for(int i=2; i<=100000; i++) {
        if(!vis[i]) {
            pr[ pl++ ]=i;
            //cout<<i<<endl;
            for(int j=i+i; j<=100000; j+=i) {
                vis[ j ]=1;
            }
        }
    }
}

void FactoRize(int n) {
    int sq=sqrt( n  );
   // cout<<n<< " ?\n";
    for(int i=0; i<pl && pr[ i ]<=sq; i++) {
        if( n%pr[i]==0 ) {
            while( n%pr[i]==0 ) {
                p[ pr[i] ]++;
                n/=pr[ i ];
            }
            //cout<<pr[i]<<endl;
            // sq=sqrt(n);
        }
        if( n==1 )break;
    }
    if( n>1 ) {
       // cout<<n<<endl;
        p[ n ]++;
    }
}

int main() {
    int tc,cs=1,i,j,k,n,x;
    Seive();
    tc=1;
    while(tc--) {
        S(n);
        p.clear();
        fr(i,1,n) {
            S(x);
            FactoRize(x);
        }
        ll tot=1LL;
        bool ok=true;
        for(map<int,int>:: iterator it=p.begin(); it!=p.end(); it++) {
            ll x=(*it).X;
           // cout<<x<< " : "<<p[x]<<endl;
            ll y=p[ x ];
            if( y%n!=0 ) {
                ok=false;
                ll md=(y%(n+1));
                if( md )md=((n+1)-md);
               // cout<<x<< " => "<<md<<endl;
                tot=(tot*BigMod(x,md,MD))%MD;
            }
        }
        if(ok)printf("justdoit\n");
        else printf("%lld\n",tot);

    }
    return 0;
}
