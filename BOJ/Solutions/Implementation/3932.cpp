#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

string j(string s){
   string temp = "";
   for (int i = 1; i < s.length(); i++)
   {
      temp+=s[i];
   }
   temp+=s[0];
   return temp;
}
string c(string s){
   string temp = "";
   temp+=s[s.length()-1];
   for (int i = 0; i < s.length()-1; i++)
   {
      temp+=s[i];
   }
   return temp;
}

string e(string s){
   string temp="";
   for (int i = (s.length()+1)/2; i < s.length(); i++)
   {
      temp+=s[i];   
   }
   for (int i = s.length()/2; i < (s.length()+1)/2; i++)
   {
      temp+=s[i];
   }
   
   for (int i = 0; i < s.length()/2; i++)
   {
      temp+=s[i];   
   }
   return temp;
}

string a(string s){
   reverse(s.begin(), s.end());
   return s;
}

string p(string s){
   string temp = "";
   for (int i = 0; i < s.length(); i++)
   {
      if(s[i]>='0'&&s[i]<='9'){
         if(s[i]=='9')temp+='0';
         else temp+=(char)s[i]+1;
      }
      else{
         temp+=s[i];
      }
   }
   return temp;
   
}

string m(string s){
   string temp = "";
   for (int i = 0; i < s.length(); i++)
   {
      if(s[i]>='0'&&s[i]<='9'){
         if(s[i]=='0')temp+='9';
         else temp+=(char)s[i]-1;
      }
      else{
         temp+=s[i];
      }
   }
   return temp;
   
}
int main() {    
   FAST
   /*cout<<j("abcd")<<endl;
   cout<<c("abcd")<<endl;
   cout<<e("abcd")<<endl;
   cout<<e("abcde")<<endl;
   cout<<a("abcde")<<endl;
   cout<<p("1234567890abc")<<endl;
   cout<<m("1234567890abc")<<endl;
   */
   int T;
   cin >> T;
   while(T--){
      string s;
      cin >> s;
      string s2;
      cin >> s2;
      for (int i = s.length()-1; i >=0; i--)
      {
         if(s[i]=='J'){
            s2 = c(s2);
         }
         else if(s[i]=='C')s2 = j(s2);
         else if(s[i]=='E')s2 = e(s2);
         else if(s[i]=='A')s2 = a(s2);
         else if(s[i]=='P')s2 = m(s2);
         else s2 = p(s2);
      }
      cout<<s2<<endl;
      
   }
}