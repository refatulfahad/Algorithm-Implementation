#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
string text,pattern;
int failure[N];
void lps() {
    //lps=longest proper prefix which is also suffix
    failure[0]=0,failure[1]=0;
    for(int i=2; i<=(int)pattern.size(); ++i) {
        int j=failure[i-1];
        while(true) {
            if(pattern[j]==pattern[i-1]) {
                failure[i]=j+1;
                break;
            }
            if(j==0) {
                failure[i]=0;
                break;
            }
            j=failure[j];
        }
    }
}
bool kmp() {
    lps();
    int len=(int)pattern.size();
    int i=0,j=0;

    while(true) {
        if(i==(int)text.size()) {
            return false;
        }
        if(text[i]==pattern[j]) {
            ++i,++j;
            if(j==len) {
                return true;
            }
        } else {
            if(j==0) {
                ++i;
            } else {
                j=failure[j];
            }
        }
    }
    return false;
}
int main() {
    cin>>text>>pattern;
    if(kmp()) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
    return 0;
}
