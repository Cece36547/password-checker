#ifndef ANALYZER_H
#define ANALYZER_H

#include "password.h"
class Analyzer{
  private:
  unsigned int strength_score;
  unsigned int spec_char_count;
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
      bool hasSpecialChar(const Password& pw);
    
     /**
     * @brief This method checks if the given password contains white space.
     */
      bool hasWhitespace(const Password& pw) const;

    /**
    * @brief Getter for Special Character Count
    */
      int get_spec_char_count() const;

    /**
     * @brief Setter for Special Character Count
     */
      void set_spec_char_count(const Password& pw) const;
    /**
     * @brief Checking file + comparing users password 
     * to see if password contains common password
     * @param Constant Reference to Password Object
     */
      bool isCommonPassword(const Password &pw, const std::string& comparable) const;
    /**
      * @brief Method checking the overall validity of the Password
      * @param A constant reference to a Password Object
      */
      bool isPasswordValid(const Password &p) const;

    /**
     * @brief Strength Score Calculator
     * @param Constant Reference to Password Object
     */
    int calc_strength_score(const Password& p) const;
};

#endif // ANALYZER_H