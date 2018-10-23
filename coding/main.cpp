#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll n,m,q,x1,y11,x2,y2,ar[1000][1000],cnt[1000][1000],baba[1000][1000][2],inp[10000][4],reg=0,regbig=1000001,givex,givey;
bool vis[1000][1000];
ll dx[4]={0,0,1,-1};
ll dy[4]={1,-1,0,0};
vector<ll> ans;
inline bool valid(ll X,ll Y)
{
    if(X>=0 && X<n && Y>=0 && Y<m)
        return true;
    return false;
}
inline void dfs(ll X,ll Y)
{
    ll nx,ny;
    vis[X][Y]=true;
    baba[X][Y][0]=givex;
    baba[X][Y][1]=givey;
    for(ll i=0;i<4;i++)
    {
        nx=X+dx[i];
        ny=Y+dy[i];
        if(!valid(nx,ny))
            continue;
        if(vis[nx][ny])
            continue;
        if(ar[nx][ny]==1)
            continue;
        dfs(nx,ny);
    }
}
inline pair<ll,ll> root(ll x,ll y)
{
    while(baba[x][y][0]!=x || baba[x][y][1]!=y)
    {
        if(baba[x][y][0]==x && baba[x][y][1]==y)
            break;
        ll alpha=baba[x][y][0],beta=baba[x][y][1];
        baba[x][y][0]=baba[alpha][beta][0];
        baba[x][y][1]=baba[alpha][beta][1];
        alpha=x,beta=y;
        x=baba[alpha][beta][0];
        y=baba[alpha][beta][1];
    }
    return {x,y};
}
inline void erase()
{
    if(x1==x2)
    {
        for(ll j=y11;j<=y2;j++)
        {
            if(cnt[x1][j]>1)
                cnt[x1][j]--;
            else
            {
                cnt[x1][j]=0;
                bool ha=true;
                for(ll k=0;k<4;k++)
                {
                    ll nx=x1+dx[k],ny=j+dy[k];
                    if(!valid(nx,ny))
                        continue;
                    if(cnt[nx][ny]==0)
                        ha=false;
                }
                if(ha)
                {
                    baba[x1][j][0]=x1;
                    baba[x1][j][1]=j;
                    reg++;
                    continue;
                }
                set<pair<ll,ll> > st;
                pair<ll,ll> up;
                for(ll k=0;k<4;k++)
                {
                    ll nx=x1+dx[k],ny=j+dy[k];
                    if(!valid(nx,ny))
                        continue;
                    if(cnt[nx][ny]>=1)
                        continue;
                    up=root(nx,ny);
                    st.insert(up);
                }
                baba[x1][j][0]=up.first;
                baba[x1][j][1]=up.second;
                reg-=(st.size()-1);
                for(ll k=0;k<4;k++)
                {
                    ll nx=x1+dx[k],ny=j+dy[k];
                    if(!valid(nx,ny))
                        continue;
                    if(cnt[nx][ny]==1)
                        continue;
                    pair<ll,ll> upp=root(nx,ny);
                    baba[upp.first][upp.second][0]=up.first;
                    baba[upp.first][upp.second][1]=up.second;
                }
            }
        }
    }
    else
    {
        for(ll j=x1;j<=x2;j++)
        {
            if(cnt[j][y11]>1)
                cnt[j][y11]--;
            else
            {
                cnt[j][y11]=0;
                bool ha=true;
                for(ll k=0;k<4;k++)
                {
                    ll nx=j+dx[k],ny=y11+dy[k];
                    if(!valid(nx,ny))
                        continue;
                    if(cnt[nx][ny]==0)
                        ha=false;
                }
                if(ha)
                {
                    baba[j][y11][0]=j;
                    baba[j][y11][1]=y11;
                    reg++;
                    continue;
                }
                set<pair<ll,ll> > st;
                pair<ll,ll> up;
                for(ll k=0;k<4;k++)
                {
                    ll nx=j+dx[k],ny=y11+dy[k];
                    if(!valid(nx,ny))
                        continue;
                    if(cnt[nx][ny]>=1)
                        continue;
                    up=root(nx,ny);
                    st.insert(up);
                    // if(j==0 && y11==2)
                    //     cout<<j<<" "<<y11<<" "<<up.first<<" "<<up.second<<" "<<nx<<" "<<ny<<endl;
                }
                baba[j][y11][0]=up.first;
                baba[j][y11][1]=up.second;
                reg-=(st.size()-1);
                for(ll k=0;k<4;k++)
                {
                    ll nx=j+dx[k],ny=y11+dy[k];
                    if(!valid(nx,ny))
                        continue;
                    if(cnt[nx][ny]==1)
                        continue;
                    pair<ll,ll> upp=root(nx,ny);
                    baba[upp.first][upp.second][0]=up.first;
                    baba[upp.first][upp.second][1]=up.second;
                }
            }
        }
    }
    ans.push_back(reg);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>q;
    memset(ar,0,sizeof(ar));
    memset(cnt,0,sizeof(cnt));
    memset(baba,-1,sizeof(baba));
    for(ll i=0;i<q;i++)
    {
        cin>>x1>>y11>>x2>>y2;
        x1--;y11--;x2--,y2--;
        inp[i][0]=x1;
        inp[i][1]=y11;
        inp[i][2]=x2;
        inp[i][3]=y2;
        if(x1==x2)
            for(ll j=y11;j<=y2;j++)
                ar[x1][j]=1,cnt[x1][j]++,baba[x1][j][0]=x1,baba[x1][j][1]=j;
        else
            for(ll j=x1;j<=x2;j++)
                ar[j][y11]=1,cnt[j][y11]++,baba[j][y11][0]=j,baba[j][y11][1]=y11;
    }
    memset(vis,false,sizeof(vis));
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(ar[i][j]==1 || vis[i][j])
                continue;
            givex=i;givey=j;
            dfs(i,j);
            reg++;
        }
    }
    ans.push_back(reg);
    for(ll i=q-1;i>0;i--)
    {
        x1=inp[i][0];
        y11=inp[i][1];
        x2=inp[i][2];
        y2=inp[i][3];
        erase();
    }
    reverse(ans.begin(),ans.end());
    for(auto &it:ans)
        cout<<it<<"\n";
    return 0;
}
