#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>

using namespace std;

struct attPair
{
    string first;
    string second;
};

int main() {
    
    int n = 0 , q = 0;
    
    cin >> n >> q;
    
    cin.clear();
    cin.ignore();
    
    int count = 0;
    vector<string> endVector;
    vector<string> startVector;
    
    std::multimap<string,string> mmap;
     
    attPair attribute;
    
    for (int i = 0; i < n; i++)
    {   
        string str;
        getline(cin,str);
        
        std::stringstream ss (str);
        string tmp;     
        
        attribute.first = " ";
        attribute.second = " ";
        
        string tag = "";
        string endTag = "";
        
        while (getline (ss,tmp,' '))
        {
            if (tmp[0] == '<' && tmp[1] != '/')
            {
                tag = tmp.substr(1);
                
                if (tag[tag.size()-1] == '>')
                {
                    tag = tmp.substr(1,tmp.size()-2);
                }
                
                startVector.push_back(tag);
            }
            else if (tmp[0] == '<' && tmp[1] == '/')
            {
                endTag = tmp.substr(2,tmp.size()-3);
                endVector.push_back(endTag);
                
                for (int sv = 0 ; sv < startVector.size(); sv++)
                {
                    if (endTag == startVector[sv])
                    {
                        startVector.erase (startVector.begin()+sv);
                        break;
                    }
                }
            }
            else if (tmp[0] != '"' && tmp[tmp.size()-1] != '"' && tmp != "=")
            {
                string access = "";
                for (int j = 0; j < startVector.size(); j++)
                {
                    access += startVector[j];
                    
                    if (j < startVector.size() - 1)
                    {
                        access += ".";
                    }
                }
                
                access += "~";
                access += tmp;
                                                    
                attribute.first = access;
                attribute.second = " ";
            }
            else if (tmp[0]=='"' && tmp[tmp.size()-1]=='"')
            {
                attribute.second = tmp.substr(1,tmp.size()-2);

            }
            else if ( tmp[0]=='"' && tmp[tmp.size()-2]=='"')
            {
                attribute.second = tmp.substr(1,tmp.size()-3);
            }
            
            if (attribute.second != " ")
            {
                mmap.insert (std::pair <string,string>(attribute.first,attribute.second));
                attribute.first = " ";
                attribute.second = " ";
            }
        }      
    }

    for (int i = 0 ; i < q; i++)
    {
        string str;
        getline (cin,str);
        std::multimap<string,string>::iterator it = mmap.find(str);
        
        if(it!=mmap.end())
        {
            std::cout << (*it).second << std::endl;
        }
        else
        {
            std::cout << "Not Found!"<<std::endl;
        }
    }

    return 0;
}

