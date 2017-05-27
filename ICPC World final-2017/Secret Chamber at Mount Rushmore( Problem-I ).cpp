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
#define MX     500005
#define inf    1000000010
#define MD     1000000007
#define eps    1e-9
///===============================///

int dp[30][30];
char c[55],d[55];
int main() {
    int tc,cs=1,i,j,k,x,m,n;
    S2(m,n);
    char a,b;
    fr(i,0,26){
        fr(j,0,26){
            dp[ i ][ j ]=inf;
        }
        dp[ i ][ i ]=0;
    }
    for(i=0;i<m;i++){
        scanf(" %c %c",&a,&b);
        dp[ a-'a'+1 ][ b-'a'+1 ]=1;
    }
    fr(k,1,26)fr(i,1,26)fr(j,1,26)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);

    while(n--){

        scanf("%s%s",c,d);
        int lc=strlen(c);
        int ld=strlen(d);
        if( lc!=ld ){
            printf("no\n");
            continue;
        }
        bool f=1;
        fr(i,0,lc-1){
            int aa=c[ i ]-'a'+1;
            int bb=d[ i ]-'a'+1;
            if( dp[aa][bb]>=inf ){
                f=0;
            }
        }
        if( f )printf("yes\n");
        else printf("no\n");
    }

    return 0;
}
