#include<bits/stdc++.h>
using namespace std;
vector<int>sqrd[325];
int ar[100005],block_size;
int main() {
    int n,q,ans,bk_id,left_id,right_id,cont=0,l,r,val,index,cont1=0;
    char ch;
    scanf("%d %d",&n,&q);
    block_size=sqrt(n);
    for(int i=0; i<n; i++) {
        scanf("%d",&ar[i]);
        cont++;
        bk_id=i/block_size;
        sqrd[bk_id].push_back(ar[i]);
        if(cont==block_size) {
            sort(sqrd[bk_id].begin(),sqrd[bk_id].end());
                 cont=0;
        }
    }
    while(q--) {
        scanf(" %c",&ch);
        if(ch=='C') {
                ans=0;
            scanf("%d %d %d",&l,&r,&val);
            l--,r--;
            left_id=l/block_size;
            right_id=r/block_size;
            if(left_id==right_id) {
                for(int i=l; i<=r; i++) {
                    if(ar[i]<=val) {
                        ans++;
                    }
                }
            } else {
                for(int i=l; i<(left_id+1)*block_size; i++) {
                    if(ar[i]<=val) {
                        ans++;
                    }
                }
                for(int i=left_id+1; i<right_id; i++) {
                    int id=upper_bound(sqrd[i].begin(),sqrd[i].end(),val)-sqrd[i].begin();
                    ans+=id;
                }
                for(int i=(right_id)*block_size; i<=r; i++) {
                    if(ar[i]<=val) {
                        ans++;
                    }
                }
            }
            printf("%d\n",ans);
        }
        else{
            scanf("%d %d",&index,&val);
            index--;cont1++;

            bk_id=index/block_size;
            /*if(cont1==2){
                    cout<<"***";
                 for(int i=0;i<sqrd[bk_id].size();i++){
                    cout<<sqrd[bk_id][i]<<" ";
                 }cout<<endl;
            }*/
            for(int i=0;i<sqrd[bk_id].size();i++){
                if(sqrd[bk_id][i]==ar[index]){
                    sqrd[bk_id][i]=val;
                    ar[index]=val;
                    break;
                }
            }
            sort(sqrd[bk_id].begin(),sqrd[bk_id].end());
            //cout<<q<<"*";

        }
    }
    return 0;
}
/***
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int>sqrd[555];
int ar[3*100005],block_size;
int main() {
    int n,ans,bk_id,left_id,right_id,cont=0,m;
    ll v,l,r,p,cal,u;
    char ch;
    scanf("%d %d %lld",&n,&m,&u);
    block_size=sqrt(n);
    for(int i=0; i<n; i++) {
        scanf("%d",&ar[i]);
        cont++;
        bk_id=i/block_size;
        sqrd[bk_id].push_back(ar[i]);
        if(cont==block_size) {
            sort(sqrd[bk_id].begin(),sqrd[bk_id].end());
            cont=0;
        }
    }
    while(m--) {
        scanf("%lld %lld %lld %lld",&l,&r,&v,&p);
        ans=0;
        l--,r--,p--;
        left_id=l/block_size;
        right_id=r/block_size;
        if(left_id==right_id) {
            for(int i=l; i<=r; i++) {
                if(ar[i]<v) {
                    ans++;
                }
            }
        } else {
            for(int i=l; i<(left_id+1)*block_size; i++) {
                if(ar[i]<v) {
                    ans++;
                }
            }
            for(int i=left_id+1; i<right_id; i++) {
                int id1=upper_bound(sqrd[i].begin(),sqrd[i].end(),v)-sqrd[i].begin();
                int id2=lower_bound(sqrd[i].begin(),sqrd[i].end(),v)-sqrd[i].begin();
                if(id2<id1)
                    ans+=id2;
                else
                    ans+=id1;
            }
            for(int i=(right_id)*block_size; i<=r; i++) {
                if(ar[i]<v) {
                    ans++;
                }
            }
        }
        cal=(u*ans)/(r-l+1);
        bk_id=p/block_size;
        //printf("%d\n",ans);
        for(int i=0; i<sqrd[bk_id].size(); i++) {
            if(sqrd[bk_id][i]==ar[p]) {
                sqrd[bk_id][i]=cal;
                ar[p]=cal;
                break;
            }
        }
        sort(sqrd[bk_id].begin(),sqrd[bk_id].end());
        //cout<<q<<"*";

    }
    for(int i=0; i<n; i++) {
        printf("%d\n",ar[i]);
    }
    return 0;
}


***/
