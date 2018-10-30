#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll n,fx,fy,f_x,f_y,x,y;
string s;
inline bool go(ll L,ll R,ll D,ll U,ll x_req,ll y_req)
{
    if(x_req>=0 && y_req>=0)
    {
        //dont touch R,U
        if(x_req>=2*L)
        {
            x_req-=2*L;
            L=0;
        }
        else
        {
            if(x_req%2==0)
            {
                L-=x_req/2;
                x_req=0;
            }
            else
            {
                L-=x_req/2;
                x_req=1;
            }
        }
        if(x_req>D)
            return false;
        D-=x_req;
        y_req-=x_req;
        x_req=0;
        if(y_req<0)
            return go(L,R,D,U,x_req,y_req);
        if(y_req&1)
            return false;
        if(y_req/2>D)
            return false;
        return true;
    }

    if(x_req<0 && y_req>=0)
    {
        x_req*=-1;
        //dont touch L,U
        if(x_req>=2*R)
        {
            x_req-=2*R;
            R=0;
        }
        else
        {
            if(x_req%2==0)
            {
                R-=x_req/2;
                x_req=0;
            }
            else
            {
                R-=x_req/2;
                x_req=1;
            }
        }
        if(x_req>D)
            return false;
        D-=x_req;
        y_req-=x_req;
        x_req=0;
        if(y_req<0)
            return go(L,R,D,U,x_req,y_req);
        if(y_req&1)
            return false;
        if(y_req/2>D)
            return false;
        return true;
    }

    if(x_req<0 && y_req<0)
    {
        x_req*=-1;
        y_req*=-1;
        //dont touch L,D
        if(x_req>=2*R)
        {
            x_req-=2*R;
            R=0;
        }
        else
        {
            if(x_req%2==0)
            {
                R-=x_req/2;
                x_req=0;
            }
            else
            {
                R-=x_req/2;
                x_req=1;
            }
        }
        if(x_req>U)
            return false;
        U-=x_req;
        y_req-=x_req;
        x_req=0;
        if(y_req<0)
            return go(L,R,D,U,x_req,y_req);
        if(y_req&1)
            return false;
        if(y_req/2>U)
            return false;
        return true;
    }

    if(x_req>=0 && y_req<0)
    {
        y_req*=-1;
        //dont touch R,D
        if(x_req>=2*L)
        {
            x_req-=2*L;
            L=0;
        }
        else
        {
            if(x_req%2==0)
            {
                L-=x_req/2;
                x_req=0;
            }
            else
            {
                L-=x_req/2;
                x_req=1;
            }
        }
        if(x_req>U)
            return false;
        U-=x_req;
        y_req-=x_req;
        x_req=0;
        if(y_req<0)
            return go(L,R,D,U,x_req,y_req);
        if(y_req&1)
            return false;
        if(y_req/2>U)
            return false;
        return true;
    }
    return false;
}
inline bool check(ll rng,ll x_req,ll y_req)
{
    ll L=0,R=0,U=0,D=0;
    for(ll i=0;i<rng;i++)
    {
        if(s[i]=='U')   U++;
        if(s[i]=='D')   D++;
        if(s[i]=='L')   L++;
        if(s[i]=='R')   R++;
    }
    if(go(L,R,D,U,x_req,y_req))
        return true;
    for(ll i=rng;i<n;i++)
    {
        if(s[i]=='U')   U++;
        if(s[i]=='D')   D++;
        if(s[i]=='L')   L++;
        if(s[i]=='R')   R++;
        if(s[i-rng]=='U')   U--;
        if(s[i-rng]=='D')   D--;
        if(s[i-rng]=='L')   L--;
        if(s[i-rng]=='R')   R--;
        if(go(L,R,D,U,x_req,y_req))
            return true;
    }
    return false;
}
int main()
{
    cin>>n>>s>>fx>>fy;
    x=0;
    y=0;
    if((abs(x-fx)+abs(y-fy))>n)
    {
        cout<<-1;
        return 0;
    }
    for(char &it:s)
    {
        if(it=='U') y=y+1;
        if(it=='D') y=y-1;
        if(it=='L') x=x-1;
        if(it=='R') x=x+1;
    }
    f_x=x;
    f_y=y;
    if(f_x==fx && f_y==fy)
    {
        cout<<0;
        return 0;
    }
    ll x_req=fx-f_x;
    ll y_req=fy-f_y;
    ll low=1,high=n,mid,ans=1e10;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(check(mid,x_req,y_req))
        {
            ans=min(ans,mid);
            high=mid-1;
        }
        else
            low=mid+1;
    }
    cout<<ans;
}