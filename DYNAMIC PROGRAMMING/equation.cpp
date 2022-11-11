/**#include <bits/stdc++.h>
using namespace std;

bool isOperator(char op)
{
    return (op == '+' || op == '-' || op == '*');
}

int possibleResultUtil(string input )
{
    vector<int> res;
    for (int i = 0; i < input.size(); i++)
    {
        if (isOperator(input[i]))
        {

            int  resPre =
                possibleResultUtil(input.substr(0, i));
            int  resSuf =
                possibleResultUtil(input.substr(i + 1));

            if (input[i] == '+')
                res.push_back(resPre + resSuf);
            else if (input[i] == '-')
                res.push_back(resPre - resSuf);
            else if (input[i] == '*')
                res.push_back(resPre * resSuf);
        }
    }

    int x=-10000;
    if (res.size() == 0)
        res.push_back(atoi(input.c_str()));
    for(int i=0; i<res.size(); i++)
    {
        if(x<res[i])
        {
            x=res[i];
        }
    }
    return x;
}

int main()
{
    string input ;
    cin>>input;
    cout<< possibleResultUtil(input);


    return 0;
}
**/
// C++ program to output all possible values of
// an expression by parenthesizing it.
#include <bits/stdc++.h>
using namespace std;

// method checks, character is operator or not
bool isOperator(char op)
{
	return (op == '+' || op == '-' || op == '*');
}

// Utility recursive method to get all possible
// result of input string
vector<int> possibleResultUtil(string input,
			map< string, vector<int> > memo)
{
	// If already calculated, then return from memo
	if (memo.find(input) != memo.end())
		return memo[input];

	vector<int> res;
	for (int i = 0; i < input.size(); i++)
	{
		if (isOperator(input[i]))
		{
			// If character is operator then split and
			// calculate recursively
			vector<int> resPre =
			possibleResultUtil(input.substr(0, i), memo);
			vector<int> resSuf =
			possibleResultUtil(input.substr(i + 1), memo);
			for(i=0;i<resPre.size();i++)
           cout<<"#"<<resPre[i]<<" ";
           cout<<"*****";
           for(int i=0;i<resSuf.size();i++)
            cout<<"$"<<resSuf[i]<<" ";//input.substr(i + 1)
            cout<<endl;
			// Combine all possible combination
			for (int j = 0; j < resPre.size(); j++)
			{   //cout<<1;
				for (int k = 0; k < resSuf.size(); k++)
				{  //cout<<2;
					if (input[i] == '+')
						res.push_back(resPre[j] + resSuf[k]);
					else if (input[i] == '-')
						res.push_back(resPre[j] - resSuf[k]);
					else if (input[i] == '*')
						res.push_back(resPre[j] * resSuf[k]);
				}
			}
		}
	}
  //cout<<endl;
	// if input contains only number then save that
	// into res vector
	if (res.size() == 0)
		res.push_back(atoi(input.c_str()));

	// Store in memo so that input string is not
	// processed repeatedly
	memo[input] = res;

	return res;
}

// method to return all possible output
// from input expression
vector<int> possibleResult(string input)
{
	map< string, vector<int> > memo;
	return possibleResultUtil(input, memo);
}

// Driver code to test above methods
int main()
{
	string input;
	cin>>input;
	vector<int> res = possibleResult(input);

	for (int i = 0; i < res.size(); i++)
		//cout << res[i] << " ";
	return 0;
}
//**/



