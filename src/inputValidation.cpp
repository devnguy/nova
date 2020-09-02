/*******************************************************************************
** Description:  Contains input validation functions that return the user's
**               input after validation. These functions can be called with no 
**               arguments if no range is specified, and can be overloaded if 
**               the input needs to be within a specific range.
*******************************************************************************/ 

#include <iostream>
#include <string>
#include "inputValidation.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;


/**
 * Continues to prompt the user for input until they enter a string that 
 * can be properly converted to an int. Returns that string as an int.
 * This function can be overloaded with one or two parameters to specify 
 * a required range for the input.
 */
int getInt() {
  string input;
  bool isInvalid = false;
  do {
    if (isInvalid) {
      cout << "Invalid input" << endl;
      isInvalid = false;
    }
    cout << "Enter an integer: ";

    getline(cin, input);

    if (!checkDigits(input)) {
      isInvalid = true;
    }
  } while (isInvalid);
  cout << endl;
  return stoi(input);
}

/**
 * Overloaded getInt to specify a min (EXCLUSIVE)
 */
int getInt(int min) {
  string input;
  bool isInvalid = false;
  do {
    if (isInvalid) {
      cout << "Invalid input" << endl;
      isInvalid = false;
    }
    cout << "Enter an integer greater than " << min << ": ";
    getline(cin, input);

    if (!checkDigits(input)) {
      isInvalid = true;
    }
  } while (isInvalid || stoi(input) <= min);
  cout << endl;
  return stoi(input);
}


/**
 * Overloaded getInt to specify a min and max (INCLUSIVE)
 */
int getInt(int min, int max) {
  string input;
  bool isInvalid = false;
  do {
    if (isInvalid) {
      cout << "Invalid input" << endl;
      isInvalid = false;
    }
    cout << "Enter an integer between " << min << " and " << max << ": ";
    getline(cin, input);

    if (!checkDigits(input)) {
      isInvalid = true;
    }
  } while (isInvalid || (stoi(input) < min || stoi(input) > max));
  cout << endl;
  return stoi(input);
}


/**
 * Continues to prompt the user for input until they enter an integer that 
 * is one of two paramters passed in. If there are more than two options, 
 * use getInt(min, max)
 */
int validateChoice(int option1, int option2) {
  string input;
  bool isInvalid = false;
  do {
    if (isInvalid) {
      cout << "Invalid input. Please enter " << option1 << " or " << option2 << endl;
      isInvalid = false;
    }
    cout << "Enter your choice: ";
    getline(cin, input);

    if (!checkDigits(input)) {
      isInvalid = true;
    }
  } while (isInvalid || (stoi(input) != option1 && stoi(input) != option2));
  cout << endl;
  return stoi(input);
}


/**
 * Continues to prompt the user for input until they enter a string that 
 * can be properly converted to a double that is within range of the min
 * and max parameters passed in. Returns that string as a double.
 */
double getDouble(int min, int max) {
  string input;
  bool isInvalid = false;
  do {
    if (isInvalid) {
      cout << "Invalid input" << endl;
      isInvalid = false;
    }
    cout << "Enter a float between " << min << " and " << max << ": ";
    getline(cin, input);

    if (!checkFloat(input)) {
      isInvalid = true;
    }
  } while (isInvalid || (stod(input) < min || stod(input) > max));
  cout << endl;
  return stod(input);
}


/**
 * Continues to prompt the user for input until they enter a string that 
 * loosely resembles a name. Returns the string if it does not violate 
 * any restrictions enoforced by the checkName helper function
 */
string getName() {
  string input;
  bool isInvalid = false;
  do {
    if (isInvalid) {
      cout << "Invalid input." << endl;
      isInvalid = false;
    }
    cout << "Enter a name: ";
    getline(cin, input);

    if (!checkName(input)) {
      isInvalid = true;
    }
  } while (isInvalid);
  cout << endl;
  return input;
}


/**
 * Checks if the parameter passed in as a string contains only numbers.
 *    Ignores preceding '-' if present to allow negative numbers.
 *    Returns true if each char is a digit.
 */
bool checkDigits(string number) {
  if (number.empty() || number == "-") {
    return false;
  }
  for (int i = 0; i < number.size(); ++i) {
    if ((i != 0 || number[i] != '-') && !isdigit(number[i])) {
      return false;
    }
  }
  return true;
}


/**
 * Checks if the parameter passed in as a string is a valid float.
 *    Ignores preceding '-' if present to allow negative numbers.
 *    Returns true if:
 *      -Each char is a digit
 *      -There is <= 1 radix
 */
bool checkFloat(string number) {
  int radixCount = 0;
  for (int i = 0; i < number.size(); ++i) {
    if (number[i] == '.') {
      ++radixCount;
    } else if ((i != 0 || number[i] != '-') && !isdigit(number[i])) {
      return false;
    }
  }
  if (radixCount > 1) {
    return false;
  } else {
    return true;
  }
}

/**
 * Takes a name as a string to check as a parameter.
 *    Returns true if the name contains:
 *      -Only letters
 *      -At most 2 spaces (nonconsecutive)
 *      -At most 2 hyphens
 *      -At most 1 period
 *      -These special chars are not leading/trailing
 *      -FIXME: "Dr. Weeniehut" not allowed due to consecutive char restriction
 */
bool checkName(string name) {
  int spaceCount = 0;
  int hyphenCount = 0;
  int periodCount = 0;
  int consecutiveSpecialCharCount = 0;

  if (name.empty()) {
    return false;
  }
  for (int i = 0; i < name.size(); ++i) {
    if (name[i] == ' ' || name[i] == '-' || name[i] == '.') {
      ++consecutiveSpecialCharCount;

      // Check if special char is first, last, or consecutive
      if ((i == 0 || i == name.size() - 1)
        || consecutiveSpecialCharCount > 1) {
        return false;
      }
      if (name[i] == ' ') {
        ++spaceCount;
      } else if (name[i] == '-') {
        ++hyphenCount;
      } else if (name[i] == '.') {
        ++periodCount;
      }
    } else if (!isalpha(name[i])) {
      return false;
    } else {
      consecutiveSpecialCharCount = 0;
    }
  }

  if (spaceCount > 2 || hyphenCount > 1 || periodCount > 1) {
    return false;
  } else {
    return true;
  }
  
}