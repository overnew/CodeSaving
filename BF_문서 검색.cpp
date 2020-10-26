//https://www.acmicpc.net/problem/1543
#include <iostream>
#include<string>
using namespace std;

int main() {
  string document;
  string word;
  int count=0;

  getline(cin,document);
  getline(cin,word);

  if(document.length() <word.length())
    cout<<0<<'\n';
  else{
    for(int i=0; i<=document.length()-word.length() ; ++i)
      if(document.substr(i,word.length()) == word ){
        ++count;
        i+= (word.length()-1);
      }
  
  cout<<count<<'\n';
  }

  return 0;
}
