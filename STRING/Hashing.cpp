
#include<bits/stdc++.h>
using namespace std;

///Author:Refat(BSMRSTU)///

#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define pil pair<int,ll>
const int N = 1e5 + 5;
const ll M = 1e9 + 7;
string s,s1,s2;
ll hash_value(ll len,ll base,ll ck) {
    ll res=0,power=1;
    if(ck==0)s=s1;
    else s=s2;
    //cout<<s<<" ";
    for(int i=len-1; i>=0; i--) {
        res+=(s[i]*power)%M;
        res%=M;
        power=(power*base)%M;
    }
    return res;
}
int main() {

    ll base=347,power=1,ck=0;///131,137,503,509
    cin>>s1>>s2;
    ll len1=s1.length();
    ll len2=s2.length();
    for(int i=1; i<len2; i++) {
        power=(power*base)%M;
    }
    ll main_string=hash_value(len2,base,0);
    ll match_string=hash_value(len2,base,1);
    //cout<<main_string<<" "<<match_string<<endl;
    if(main_string==match_string) {
        printf("index:0 yes");
        ck=1;
    } else
        for(int i=1; i<=len1-len2+1; i++) {
            main_string=(main_string-(s1[i-1]*power)%M)%M;
            main_string=(main_string+M)%M;
            main_string=(main_string*base)%M;
            main_string=(main_string+s1[i+len2-1])%M;
            // cout<<main_string<<" "<<match_string;
            if(main_string==match_string) {
                printf("index:%d yes",i);
                ck=1;
                break;
            }
        }
    if(ck==0)cout<<"no";
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;

///Author:Refat(BSMRSTU)///

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define pil pair<int,ll>
const int N = 1e5 + 5;
const int M = 1e9 + 7;
ull po1[1000005],h1[3*100005],h2[3*100005],po2[1000005];
string s1[3*100005],s2[3*100005];
set<ull>st,st1;
void mHash1(string s,int in) {
    ull has=0;
    for(int i=0; i<s.length(); i++) {
        has=(has+((s[i]-'a'+1)*po1[i])%M)%M;
    }
    st.insert(has);
}
void tHash1(string s,int in) {
    ull has=0;
    for(int i=0; i<s.length(); i++) {
        has=(has+((s[i]-'a'+1)*po1[i])%M)%M;
    }
    h1[in]=has;
}
pow1() {
    po1[0]=1;
    for(int i=1; i<=1000000; i++) {
        po1[i]=(po1[i-1]*11ull)%M;
    }

}
void mHash2(string s,int in) {
    ull has=0;
    for(int i=0; i<s.length(); i++) {
        has=(has+((s[i]-'a'+1)*po2[i])%M)%M;
    }
    st1.insert(has);
}
void tHash2(string s,int in) {
    ull has=0;
    for(int i=0; i<s.length(); i++) {
        has=(has+((s[i]-'a'+1)*po2[i])%M)%M;
    }
    h2[in]=has;
}
pow2() {
    po2[0]=1;
    for(int i=1; i<=1000000; i++) {
        po2[i]=(po2[i-1]*37ull)%M;
    }

}
int main() {
    int n,k;
    pow1();
    pow2();
    scanf("%d %d",&n,&k);
    for(int i=1; i<=n; i++) {
        cin>>s1[i];
        mHash1(s1[i],i);
        mHash2(s1[i],i);
    }
    for(int i=1; i<=k; i++) {
        cin>>s2[i];
        tHash1(s2[i],i);
        tHash2(s2[i],i);
    }

    for(int i=1; i<=k; i++) {
        int ck=0;
        for(int j=0; j<s2[i].length(); j++) {
            ull has1,has2;
            for(int ch=1; ch<=3; ch++) {
                if(s2[i][j]-'a'+1==ch)continue;
                has1=(h1[i]-((s2[i][j]-'a'+1)*po1[j])%M+M)%M;
                //has1=(has1+M)%M;
                has1=(has1+(ch*po1[j])%M)%M;
                has2=(h2[i]-((s2[i][j]-'a'+1)*po2[j])%M+M)%M;
                //has2=(has2+M)%M;
                has2=(has2+(ch*po2[j])%M)%M;
                //cout<<has1<<" "<<has2;
                if(st.find(has1)!=st.end()&&st1.find(has2)!=st1.end()) {
                    ck=1;
                    break;
                }
            }
            if(ck==1) {
                printf("YES\n");
                break;
            }
        }
        if(ck==0)printf("NO\n");

    }
    return 0;
}

*/
/*
hash
#include <bits/stdc++.h>

using namespace std;

struct HashString {
    vector<int> P = {131, 151};
    vector<vector<long long>> Hash, Pow;
    vector<long long> Mod = {1000000007LL, 1000000009LL};

    HashString(string s) {
        Pow.clear();
        Hash.clear();
        Pow.resize(2, vector<long long> ((int) s.size()));
        Hash.resize(2, vector<long long> ((int) s.size()));

        buildHash(s);
    }

    void generatePower(int n) {
        Pow[0][0] = Pow[1][0] = 1;
        for (int i = 1; i < n; ++i) {
            Pow[0][i] = (Pow[0][i - 1] * P[0]) % Mod[0];
            Pow[1][i] = (Pow[1][i - 1] * P[1]) % Mod[1];
        }
    }

    void buildHash(string s) {
        generatePower((int) s.size());
        Hash[0][0] = Hash[1][0] = s[0];
        for (int i = 1; i < (int) s.size(); ++i) {
            Hash[0][i] = (Hash[0][i - 1] + Pow[0][i] * s[i]) % Mod[0];
            Hash[1][i] = (Hash[1][i - 1] + Pow[1][i] * s[i]) % Mod[1];
        }
    }

    long long getHash(int l, int r, int f) {
        long long h = l > 0 ? Hash[f][r] - Hash[f][l - 1] : Hash[f][r];
        return (h + Mod[f]) % Mod[f];
    }

    bool isMatch(int l1, int r1, int l2, int r2) {
        bool foo = (getHash(l1, r1, 0) * Pow[0][l2 - l1]) % Mod[0] == getHash(l2, r2, 0);
        bool boo = (getHash(l1, r1, 1) * Pow[1][l2 - l1]) % Mod[1] == getHash(l2, r2, 1);
        return foo & boo;
    }
};

int main() {
    string s; cin >> s;
    HashString helper = HashString(s);
}
*/

