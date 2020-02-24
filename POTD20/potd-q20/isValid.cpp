#include <string>
#include <stack>

using namespace std;

bool isValid(string input) {
    stack<char> st;
    if (input.length() == 0) {
      return true;
    }

    for (unsigned long i = 0; i < input.length(); i++) {
      if (input.at(i) == '[' || input.at(i) == '(' || input.at(i) == '{') {
        st.push(input.at(i));
      } else if (input.at(i) == ']'){
        if (!st.empty() && st.top() == '[') {
          st.pop();
        } else {
          return false;
        }
      } else if (input.at(i) == ')'){
        if (!st.empty() && st.top() == '(') {
          st.pop();
        } else {
          return false;
        }
      } else if (input.at(i) == '}'){
        if (!st.empty() && st.top() == '{') {
          st.pop();
        } else {
          return false;
        }
      } 
    }

    return st.empty();    // modify this!
}
