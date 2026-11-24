#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool checkRedundant(string str){ 
    stack<char> s;

    for(char ch : str) {
        if(ch != ')') {
            s.push(ch);
        }
        else {
            bool operatorFound = false;

            while(!s.empty() and s.top() != '(') {
                char top = s.top();
                if(top == '+' or top == '-' or top == '*' or top == '/') {
                    operatorFound = true;
                }
                s.pop();
            }
            s.pop(); // pop the opening bracket
            if(!operatorFound) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    string str = "((a+b)+c) + ((d*e))";
    checkRedundant(str) ? cout<<"Contains Redundant Parenthesis" : cout<<"r";
    return 0;
}