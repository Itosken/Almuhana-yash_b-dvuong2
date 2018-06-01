CPSC 311 Documenting Code 
Summer 2018

Dustin Vuong dvuong2@csu.fullerton.edu
Yash Bhambhani yash_b@csu.fullerton.edu
Abdulmalek Almuhana Almuhana@csu.fullerton.edu

Infix to Postfix/Postfix Evaluation/Postfix to Prefix
Description

First Function: string infixToPostfix(string exp)
This will take an infix expression as an argument, and return the corresponding postfix expression.
Second Function:double evaluatePostfix(string exp)
This will take a postfix expression of the form generated in part 1, and evaluate it as a double value.
Third Function: string postfixtoPrefix(string exp)
Creates stacks S, of strings and scans the postfix expression from left to right(skips over whitespace). If the character is an operand, it pushes the char on top of the stack. If it's an operator, it pops the top of the stack twice into two separate characters (x and y). After popping twice, the stack is pushed with the concatenation of the operatore and the two separate characters. 


