#include<iostream>
#include<stack>

using namespace std;

string reversePrefix(string word, char ch){
     stack<char>st;
     int i = 0;

     while(i < word.length()){
        st.push(word[i]);
        if(word[i] == ch) break;
         i++;
     }
     if(i == word.length()) return  word;

     string result = "";

     while(!st.empty()){
        result += st.top();
        st.pop();
     }
     result += word.substr(i + 1);
     return result;
}

int main (){

    string word = "abcdefd";
    char ch = 'd';

     string result = reversePrefix(word, ch);
        cout << "Result: " << result <<endl;

        return 0;
     
}