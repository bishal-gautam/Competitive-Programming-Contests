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
#define MD     1000000007
#define eps    1e-9
///===============================///

int n,lg,tmm,St[MX],Ed[MX],L[MX],T[MX],P[20][MX];
vector<int>G[MX+2];

void Dfs(int u,int p,int l) {
    L[u]=l;
    T[u]=p;
    St[u]=++tmm;
    for(int i=0;i<SZ( G[u ]);i++){
        int v=G[u][i];
        if(v==p)continue;
        Dfs(v,u,l+1);
    }
    Ed[u]=++tmm;
}

void PrePar( ) {
    for(int i=1; i<=n; i++)P[0][i]=T[i];
    for(int i=1; 1<<i<=n ; i++) {
        for(int j=1; j<=n; j++) {
            if( P[i-1][j]==-1 )continue;
            P[i][j]= P[i-1][ P[i-1][j] ];
        }
    }
}

int dis;
int Kth(int x,int k) {
    for(int i=18; i>=0; i--) {
        if( (1<<i) <=k ) {
            x=P[i][x];
            k-=(1<<i);
        }
    }
    return x;
}

int LCA(int x,int y) {
    if( L[x]<L[y] ) swap(x,y);
    int k=(L[x]-L[y]);
    x=Kth(x,k);
    if(x==y) return x;
    for(int i=18; i>=0; i--) {
        if( P[i][x]!=P[i][y] ) {
            x=P[i][x];
            y=P[i][y];
        }
    }
    return T[x];
}

int Ind[MX+2];
int main(){
    int x,a,b;
    SET(P);
    SET(T);
    S2(n,x);
    fr(i,1,n-1){
        S2(a,b);
        G[a].pb( b );
        G[b].pb( a );
        Ind[ a ]++;
        Ind[ b ]++;
    }

    Dfs(1,-1,1);
    PrePar( );
    int ans=0;
    for(int i=2;i<=n;i++){
        if( Ind[i]==1 ){ ///LeafNode
            // cout<<i<< " => ";
            int lc=LCA(x,i);
            //cout<<lc<<endl;
            int mydis=L[ x ]-L[ lc ];
            int hisdis=L[ lc ]-1;
           // cout<<mydis<< " && "<<hisdis<<endl;
            if( mydis<hisdis ){
                ans=max( ans, L[ i ]+L[ i ]-2);
            }
            //cout<<ans<<endl;
        }
    }

    printf("%d\n",ans);

    return 0;
}
