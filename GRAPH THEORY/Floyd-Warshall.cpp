#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll ar[1000][1000],par[1000][1000];
void fun(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            par[i][j]=j;
            if(i==j)
                continue;
            ar[i][j]=INT_MAX;

        }
    }
}
void path(int u,int v) {
    printf("%d",u);
    if(u!=v) {
        printf(" ");
        u=par[u][v];
        path(u,v);
    }
}

void negativecycle(int n) {
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(ar[i][j]>(ar[i][k]+ar[k][j])) {
                    ar[i][j]=INT_MIN;
                    par[i][j]=-1;
                }
            }
        }
    }
}
int main() {
    int n,edge,x,y,z,u,v;

    scanf("%d",&n);
    fun(n);
    scanf("%d",&edge);
    for(int i=1; i<=edge; i++) {
        scanf("%d %d %d",&x,&y,&z);
        ar[x][y]=z;
    }
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(ar[i][j]>(ar[i][k]+ar[k][j])) {
                    ar[i][j]=ar[i][k]+ar[k][j];
                    par[i][j]=par[i][k];
                }
            }
        }
    }
    negativecycle(n);
    /**for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            printf("%d ",ar[i][j]);
        }
        printf("\n");
    }**/
    scanf("%d %d",&u,&v);
    if(ar[u][v]==INT_MAX) {
        printf("infinite");
    } else {
        printf("%d\n",ar[u][v]);
        path(u,v);
    }
    return 0;
}
