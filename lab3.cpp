#include<bits/stdc++.h>
using namespace std;

int ismatching(string a)
{
  stack<char> s;
  char t;
  int count=0;

  for(int i=0;i<a.length();i++)
  {
      if(a[i] == '(' || a[i] == '[' || a[i] == '{' || a[i] == '<')
      {
        s.push(a[i]);
        continue;
      }else if(a[i] == '|' && count==0)
      {
        s.push(a[i]);
        count++;
        continue;
      }
      if(s.empty())
      return 0;

      switch(a[i])
      {
        case ')': t=s.top();
                  if(t == '[' || t == '{' || t == '<' || t == '|')
                  {
                    return 0;
                  }else if(t == '('){ s.pop();}
                  break;
        case ']': t=s.top();
                  if(t == '(' || t == '{' || t == '<' || t == '|')
                  {
                    return 0;
                  }else if(t == '['){ s.pop();}
                  break;
        case '}': t=s.top();
                  if(t == '(' || t == '[' || t == '<' || t == '|')
                  {
                    return 0;
                  }else if(t == '{'){ s.pop();}
                  break;
        case '>': t=s.top();
                  if(t == '(' || t == '[' || t == '{' || t == '|')
                  {
                    return 0;
                  }else if(t == '<'){ s.pop();}
                   break;
        case '|': t=s.top();
                  if(t == '(' || t == '[' || t == '{' || t == '<')
                  {
                    return 0;
                  }else if(t == '|'){ s.pop();count--;}
                   break;

      }
  }
    return s.empty();
}




int main(void)
{
  string in;
  int test;
  cin >> test;
  while(test--)
  {
  cin >> in ;
  if(ismatching(in))
  {
   cout <<"YES"<<endl;
  }else cout <<"NO"<<endl;
  }
  return 0;
}
