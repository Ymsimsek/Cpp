/*-> In C++, attributes are used to attach additional information to entities such as variables, functions, or classes. 
Attributes provide a way to give the compiler or other tools specific instructions or metadata about how to handle the 
annotated entities. Attributes were introduced in C++11 and have been expanded in subsequent C++ standards.

Syntax: 
[[ Attribute_name ]]
*/

//Examples: 

//-> [[nodiscard]] : Advises the compiler to issue a warning if the return value of a function marked with this attribute is ignored.

[[nodiscard]] int getValue() {
    return 42;
}

// Generates a warning if the return value is ignored
int main() {
    getValue();
}


//-> [[maybe_unused]] : Suppresses compiler warnings about unused variables or entities.

void myFunction([[maybe_unused]] int unusedParameter) {
    //... some code
}


//-> [[deprecated]] : Marks a function, variable, or type as deprecated, suggesting that it should be avoided in favor of alternative constructs.

void myFunction([[maybe_unused]] int unusedParameter) {
    // function implementation
}


//-> [[fallthrough]] : Used to indicate intentional fallthrough in a switch statement. It informs the compiler that the fallthrough is intentional and not a mistake.

switch (value) {
    case 1:
        // ... some code
        [[fallthrough]];
    case 2:
        // code for case 1 and case 2
        break;
    case 3:
        // code for case 3
        break;
}


// -> [[likely]] and [[unlikely]] : Used to provide branch prediction hints to the compiler, indicating the likely or unlikely paths in conditional statements. 
These hints can help the compiler generate more efficient code by optimizing for the predicted branch.

  if ([[likely]](condition)) {
    // code for the likely branch
} else {
    // code for the unlikely branch
}

