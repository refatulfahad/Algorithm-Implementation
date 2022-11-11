#include<bits/stdc++.h>
using namespace std;
char s[10000],t[10000];
map<string,int>m;

int main()
{
    int len[100][100],len1,len2,res=0,ans=0;
    scanf("%s %s",s+1,t+1);
    len1=strlen(s+1);
    len2=strlen(t+1);
    for(int i=1; i<=len1; i++)
    {
        for(int j=1; j<=len2; j++)
        {
            if(s[i]==t[j])
            {
                len[i][j]=len[i-1][j-1]+1;
                res=len[i][j];
            }
            else
            {
                len[i][j]=max(len[i][j-1],len[i-1][j]);
                res=len[i][j];
            }
        }
    }
    ans=res;
    char st[res];
    st[res]='\0';
    int i=len1,j=len2;
    while(i>0&&j>0)///path print
    {
        if(s[i]==t[j])
        {
            st[res-1]=s[i];
            i--,j--;
            res--;
        }
        else if(len[i][j]==len[i][j-1])
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    cout<<"length"<<"= "<<ans<<endl<<"subsequence"<<"= "<<st;
    return 0;
}
/**********************recursion*****************************
#include<bits/stdc++.h>
using namespace std;
int visit[1000][1000],l[1000][1000];
char s1[1000],s2[1000];
int lcs(int n,int m)
{   int ans=0;
    if(visit[n][m]==1)
    {
        //cout<<1;
        return l[n][m];
    }
    else if(s1[n]=='\0'||s2[m]=='\0')
    {
        return 0;
    }
    else if(s1[n]==s2[m])
    {

        //cout<<n<<m<<endl;
       ans=1+lcs(n+1,m+1);
    }
    else
    {
        ans= max(lcs(n,m+1),lcs(n+1,m));
    }
     visit[n][m]=1;
     l[n][m]=ans;
      return l[n][m];
}
int main()
{

    scanf("%s %s",s1+1,s2+1);
    int len1,len2;
    len1=strlen(s1+1);
    len2=strlen(s2+1);
    cout<<lcs(1,1);
    return 0;
}*/
