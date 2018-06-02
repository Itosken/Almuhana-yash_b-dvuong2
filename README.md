CPSC 311 Documenting Code 
Summer 2018

Dustin Vuong dvuong2@csu.fullerton.edu
Yash Bhambhani yash_b@csu.fullerton.edu
Abdulmalek Almuhana Almuhana@csu.fullerton.edu

Title: Postfix Evaluation using stacks.
Description

Main program uses a file with multiple correct infix expressions and it is passed through multiple function, which are listed below.

First Function: string postfixtoPrefix(string exp)
Creates stacks S, of strings and scans the postfix expression from left to right(skips over whitespace). If the character is an operand, it pushes the char on top of the stack. If it's an operator, it pops the top of the stack twice into two separate characters (x and y). After popping twice, the stack is pushed with the concatenation of the operatore and the two separate characters. 

Second Function: string infixToPostfix(string exp)
This will take an infix expression as an argument, and return the corresponding postfix expression.

Third Function: double evaluatePostfix(string exp)
This will take a postfix expression of the form generated from the second function, and evaluate it as a double value.
The values for each operand is asked to be hardcoded, and are listed below:
A = 2.0
B = 3.0
C = 4.0
D = 5.0
E = 6.0

All the functions listed above return what is expected of them (read function names for more clarification)


Development Tool used: Microsoft Studio Community 2017 (Version 15.3.5)
Development Environment Used: Microsoft .NET Framework (Version 4.7.02556)

