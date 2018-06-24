#include <bits/stdc++.h>

using namespace std;

bool findPair (string str)
{
    if (str.empty())
    {
        return true;
    }
    
    for (int i = 0; i <str.size(); i++)
    {
        if (str[i] == '{' && str[i+1] == '}')
        {
            str.erase(i,2);
            str.shrink_to_fit();
            return findPair(str);            
        }
        
        if (str[i] == '[' && str[i+1] == ']')
        {
            str.erase(i,2);
            str.shrink_to_fit();            
            return findPair(str);            
        }
        
        if (str[i] == '(' && str[i+1] == ')')
        {
            str.erase(i,2);
            str.shrink_to_fit();
            return findPair(str);            
        }
    }
    
    return false;
}



int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string expression;
        getline(cin, expression);
        
        if(findPair(expression))
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
            std::cout << "NO" << std::endl;           
        }
    }
    
    

    return 0;
}

