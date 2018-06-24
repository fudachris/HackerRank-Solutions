#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct charFreq
{
    char c;
    int f;
};

vector<char> str2vector (string str)
{
    vector <char> tmp;
    
    for (int i = 0 ; i < str.length (); i++)
    {
        tmp.push_back(str[i]);
    }
    
    return tmp;
}

int getFreq (vector<char> v, char ch)
{
    int count = 0;
    for (auto i = v.rbegin(); i != v.rend(); i++)
    {
        if (ch == *i)
        {
            count += 1;
        }
    }
    
    return count;
}

vector <charFreq> getFreqVector (vector<char> v)
{
    vector <charFreq> tmp;
    
    vector <char> used;
    
    for (int i = v.size() - 1  ; i >= 0; i--)
    {
        bool push = true;
        
        if (used.size () == 0)
        {
            char ch = v[i];
            int freq = getFreq (v,ch);
        
            charFreq tr;
            tr.c = ch;
            tr.f = freq;
        
            tmp.push_back (tr);
            
            used.push_back(ch);
        }
        else if (!used.empty())
        {
            for (int j = 0 ; j < used.size(); j++)
            {
                if (v[i] == used[j])
                {
                    push = false;
                    break;
                }
            }
            
            if (push)
            {
                char ch = v[i];
                int freq = getFreq (v,ch);
        
                charFreq tr;
                tr.c = ch;
                tr.f = freq;
        
                tmp.push_back (tr);
            
                used.push_back(ch);
            }
        }
    }
    
    return tmp;
}

void Print (vector<charFreq> v)
{
    for (int i = 0 ; i < v.size(); i++)
    {
        std::cout << " c=" << v[i].c << " f=" << v[i].f << std::endl;
    }
}

int getDiff (vector<charFreq> a, vector<charFreq> b)
{
    int count = 0;
    for (int i = 0 ; i < a.size(); i++)
    {
        for (int j = 0 ; j < b.size(); j++)
        {
            if (a[i].c == b[j].c)
            {
                int max = (a[i].f >= b[j].f) ? a[i].f : b[j].f;
                int min = (a[i].f <= b[j].f) ? a[i].f : b[j].f;
                count = count + max - min;
            }
        }
    }
    
    return count;
}



int main()
{
    string a;
    getline(cin, a);

    string b;
    getline(cin, b);
    
    vector<char> av = str2vector (a);    
    vector<char> bv = str2vector (b);    
    
    vector<charFreq> acf = getFreqVector(av);
    vector<charFreq> bcf = getFreqVector(bv);
    
    int count = getDiff (acf,bcf);
    
    vector<charFreq> zcf;
    
    for ( int i = 0 ; i < acf.size(); i++)
    {
        bool push = true;

        for (int j = 0 ; j < bcf.size(); j++)
        {
            if ( acf[i].c == bcf[j].c)
            {
                push = false;
                break;
            }
        }
        
        if (push)
        {
            zcf.push_back(acf[i]);
        }
    }
    
    for ( int i = 0 ; i < bcf.size(); i++)
    {
        bool push = true;

        for (int j = 0 ; j < acf.size(); j++)
        {
            if ( bcf[i].c == acf[j].c)
            {
                push = false;
                break;
            }
        }
        
        if (push)
        {
            zcf.push_back(bcf[i]);
        }
    }
    
    for (int i = 0 ; i < zcf.size(); i++)
    {
        count += zcf[i].f;   
    }

    std::cout <<  count;


    return 0;
}

