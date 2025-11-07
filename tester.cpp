#include "password.h"
#include "analyzer.h"
#include <iostream>
#include <string>

int main(){
    Analyzer myanalyzer;
    std::string entered_pw;
    
    std::cout << "Password Requirements:\n";
    std::cout << "1. Length of 10 or greater\n";
    std::cout << "2. At least one uppercase letter\n";
    std::cout << "3. At least one lowercase letter\n";
    std::cout << "4. At least one digit\n";
    std::cout << "5. At least one special character\n";
    std::cout << "6. No spaces\n\n";
    
    while(true) {
        std::cout << "Enter a password (or 'quit' to exit): ";
        std::getline(std::cin, entered_pw);
        
        if(entered_pw == "quit") {
            break;
        }
        
        // Create a new Password object with the entered password
        Password mypassword(entered_pw);
        
        // Test individual checks
        std::cout << "\n--- Analysis ---\n";
        std::cout << "Length valid (>10): " << (myanalyzer.isLengthValid(mypassword) ? "YES" : "NO") << "\n";
        std::cout << "Has uppercase: " << (myanalyzer.hasUppercase(mypassword) ? "YES" : "NO") << "\n";
        std::cout << "Has lowercase: " << (myanalyzer.hasLowercase(mypassword) ? "YES" : "NO") << "\n";
        std::cout << "Has digit: " << (myanalyzer.hasDigit(mypassword) ? "YES" : "NO") << "\n";
        std::cout << "Has special char: " << (myanalyzer.hasSpecialChar(mypassword) ? "YES" : "NO") << "\n";
        std::cout << "Has whitespace: " << (myanalyzer.hasWhitespace(mypassword) ? "YES" : "NO") << "\n";
        
        // Overall validity check
        std::cout << "\n--- Result ---\n";
        if(myanalyzer.isPasswordValid(mypassword)) {
            std::cout << "✓ Password is VALID!\n\n";
        } else {
            std::cout << "✗ Password is INVALID!\n\n";
        }
    }
    
    std::cout << "Goodbye!\n";
    return 0;
}