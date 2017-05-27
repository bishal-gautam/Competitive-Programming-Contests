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
#define MX     2000005
#define inf    1000000010
#define MD     1000000007LL
#define eps    1e-9
///===============================///

//int sq;
//struct data {
//    int l,r,d,id;
//    data() {};
//    inline data(int a, int b, int c) {
//        id = c;
//        l = a, r = b, d = l / sq;
//    }
//    inline bool operator < (const data& other) const {
//        if(d != other.d) return (d > other.d);
//        return ((d & 1) ? (r < other.r) : (r > other.r));
//    }
//};
//data v[MX+2];

ull bp[MX+5],b=7ULL;
void PrePow( ) {
    bp[0]=1ULL;
    for(ull i=1; i<=MX-2; i++)bp[i]=(bp[i-1]*b);
}

int Mp[MX+2];
int tot,n,m,q,l,r,uu[MX],vv[MX],ans[MX+2];

//
//void add(int p) {
//    Mp[ uu[p] ]^=1;
//    Mp[ vv[p] ]^=1;
//    if( Mp[ uu[p] ] ==1 )tot++;
//    else tot--;
//    if( Mp[ vv[p] ] ==1 )tot++;
//    else tot--;
//}
//
//void rmv(int p) {
//    Mp[ uu[p] ]^=1;
//    Mp[ vv[p] ]^=1;
//    if( Mp[ uu[p] ] ==1 )tot++;
//    else tot--;
//    if( Mp[ vv[p] ] ==1 )tot++;
//    else tot--;
//}

ull dp[MX+2];
int main() {
    PrePow();
    S2(n,m);
    ull phs=0ULL;
    dp[ 0 ]=phs;
    fr(i,1,m) {
        S2(uu[i],vv[i]);
        phs^=bp[ uu[i] ];
        phs^=bp[ vv[i] ];
        dp[ i ]=phs;
    }
    S(q);
//    sq=200;
    fr(i,0,q-1) {
        S2(l,r);
        ll xr=( dp[r]^dp[l-1] );
        ans[i]=(xr);
       // v[i]=data(l,r,i);
    }
//    sort(v,v+q);
//    int cl=v[0].l,cr=cl-1;
//    tot=0;
//    for(int i=0; i<q; i++) {
//        l=v[i].l;
//        r=v[i].r;
//        ///frm left to l;
//        while(cl<l) {
//            rmv(cl++);
//        }
//        /// add frm rgt to l
//        while(cl>l) {
//            add(--cl);
//        }
//        /// add frm lft to r
//        while(cr<r) {
//            add(++cr);
//        }
//        /// rmv frm rgt to r
//        while(cr>r) {
//            rmv(cr--);
//        }
//        ans[ v[i].id ]=tot;
//    }
    fr(i,0,q-1) {
        if(ans[i]) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
