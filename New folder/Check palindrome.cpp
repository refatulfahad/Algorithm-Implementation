#include<bits/stdc++.h>
using namespace std;
string s;
bool palindrome(int i,int j)
{
    if(i>=j)
        return true;
    if(s[i]!=s[j])
        return false;
    return palindrome(i+1,j-1);
}
int main()
{

    cin>>s;
    cout<<palindrome(0,s.length()-1);
    return 0;
}
