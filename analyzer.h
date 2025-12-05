#ifndef ANALYZER_H
#define ANALYZER_H
#include "password.h"
#include <fstream>
#include <stdexcept>

class Analyzer{
  private:
  unsigned int strength_score;
  public:
   /**
     * @brief This method checks if the given password's length is valid. 
     * @return True if length >10. If else, return false.
     */
      bool isLengthValid(const Password& pw) const;

    /**
     * @brief This method checks is the given password contains at least one uppercase alphabetic character.
     */
      bool hasUppercase(const Password& pw) const;
    /**
     * @brief This method checks is the given password contains at least one uppercase alphabetic charater.
     */
      bool hasLowercase(const Password& pw) const;
    
    /**
     * @brief This method checks if the given password contains at least one digit.
     */
      bool hasDigit(const Password& pw) const;

     /**
     * @brief This method checks if the given password contains at least one special character.
     */
      bool hasSpecialChar(const Password& pw) const;
    
     /**
     * @brief This method checks if the given password contains white space.
     */
      bool hasWhitespace(const Password& pw) const;
    /**
     * @brief Checking file + comparing users password 
     * to see if password contains common password
     * @param Constant Reference to Password Object
     */
      unsigned int common_substr(const Password& pw) const;
      bool isCommon(const Password &pw) const;
    /**
      * @brief Method checking the overall validity of the Password
      * @param A constant reference to a Password Object
      */
      bool isPasswordValid(const Password &p) const;

    /**
     * @brief This method calculates the strength score of the password based on several requirments.
     * Password needs to have lowercase char, uppercase char, numbers, 
     * @param Constant Reference to Password Object
     */
    unsigned int calc_strength_score(const Password& p);
};

#endif // ANALYZER_H