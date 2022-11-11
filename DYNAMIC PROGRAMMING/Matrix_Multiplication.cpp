#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int visit[10000][10000],dp[1000][1000];
int n,row[10009],col[100009];
int fun(int l,int r) {
    int left_right,res;
    if(l>=r) {
        return 0;
    }
    if(visit[l][r]==1) {
        return dp[l][r];
    }
    int ans=INT_MAX;
    for(int mid=l; mid<r; mid++) {
        int left=fun(l,mid);
        int right=fun(mid+1,r);
        left_right=row[l]*col[mid]*col[r];
        res=left+right+left_right;
        //cout<<res<<" ";
        ans=min(ans,res);
        //cout<<ans<<" ";
    }
    visit[l][r]=1;
    dp[l][r]=ans;
    return dp[l][r];
}
int main() {

    scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        scanf("%d %d",&row[i],&col[i]);
    }
    cout<<fun(1,n);

}
/**int row[MAX], col[MAX];
int dp[MAX][MAX];
bool visited[MAX][MAX];
int f(int beg,int end)
{
	if(beg>=end)return 0;
	if(visited[beg][end])return dp[beg][end];
	int ans=1<<30; //
	for(int mid=beg; mid<end;mid++) //
	{
		int opr_left = f(beg, mid); //opr = multiplication operation
		int opr_right = f(mid+1, end);
		int opr_to_multiply_left_and_right = row[beg]*col[mid]*col[end];
		int total = opr_left + opr_right + opr_to_multiply_left_and_right;
		ans = min(ans, total);
	}
	visited[beg][end] = 1;
	dp[beg][end] = ans;
	return dp[beg][end];
}

int main()
{
	int n;
	 scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d %d",&row[i],&col[i]);
    }
	cout<<f(0,n-1)<<endl;
}**/
