/*Program to convert a prefix expression to postfix expression
Prefix expression : An expression in which the operator appears before the operands. 
Postfix expression : An expression in which the operator appears after the operands. 
*/

/*
LOGIC:
To convert prefix to postfix expression we follow steps given below:
Step 1. If the symbol is an operand, push it to the stack
Step 2. If symbol is an operator then pop top two elements from stack
Step 3. Then push an expression by concatenating (+op1+op2+symbol)
Step 4. At last return the top element of stack as postfix expression
*/

//CODE:
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Function to convert prefix to postfix expression
string prefix_to_postfix(string prefix)
{
    stack<string> s;
    // length of prefix expression
    int l=prefix.length();
  
    // Iterating through the Prefix expression from right to left
    for(int i=l-1;i>=0;i--){

        // if the symbol is an operand, push it to the stack
        if(prefix[i]>='a' && prefix[i]<='z'||prefix[i]>='A' && prefix[i]<='Z')
        s.push(string(1,prefix[i]));
        // if symbol is an operator
        else
        {
            // pop two operands (op1 & op2) from stack
            string op1=s.top();
            s.pop();
            string op2=s.top();
            s.pop();

            // Creating a string by concatenating the two operands and the operator after them and pushing it back to the stack.
            string temp=(op1+op2+prefix[i]);
            s.push(temp);
        }
    }

    // returning element/string at top of stack
    return s.top();
}

// MAIN FUNCTION
int main()
{

  // taking user input
  string exp;
  cout<<"Enter expression: ";
  cin>>exp;

  // calling function
  cout<<"Prefix to Postfix expression is: "<<prefix_to_postfix(exp);
}

/*
OUTPUT:
Enter expression: *-a/bc-/akl
Prefix to Postfix expression is: abc/-ak/l-*
*/
