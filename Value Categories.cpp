/*Primary Value Categories:
-> L Value
-> PR Value
-> X Value

Combined/Unified Value Categories:
-> PR Value or X Value : R Value
-> L Value or X Value : GL Value 

-> L value expressions can not be initialized with R value expressions. 

-> If an expresiion is pure identifier, if it is a name of a variable we can almost every time say that it is an L value expression. 

L Value Examples:
1) x 
2) --x
3) ++x
4) *ptr
5) ptr[35]
6) x,y
7) a?b:c // (Turner Operator: Only if two operands are L Valued the expression becomes L Valued )

PR Value Examples: 
1) Arithmetic Operators except preincrement and predecrement operators: +x, -c, x++, x+z, etc...
2) Logic Operators: !a, a<b, etc...
3) Relational Operators: a==b, etc...
4) Constant Values: 10, 1, etc...


-> Paranthesis does not change the value category of the expression. 
*/
