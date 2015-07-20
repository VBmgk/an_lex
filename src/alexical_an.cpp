#include "alexical_an.hpp"

void skipSeparators  (void) {} 
char readChar        (void) { char ch; return ch; }
bool isDigit         (char ch) { return true; }
t_token addCharConst (char ch) { t_token token; return token; }
t_token addIntConst  (char ch) { t_token token; return token; }

/*t_token nextToken (void) {
  // TODO: Make struct for token2
  t_token token, token2;

  char next_char;

  // tratar comentários
  skipSeparators(); 
  // token regular numeral
  if (isDigit(next_char)) {
    int n = 0;
    do {
      n = n * 10 + (next_char - '0');
      next_char = readChar();
    } while (isDigit(next_char));

    token = NUMERAL;
    token2 = addIntConst(n);
  }
  // token regular string
  if (next_char == '"') {
    char string[MAX_STRING_SIZE + 1];
    int i = 0;

    next_char = readChar();// to remove

    do {
      string[i++] = next_char;
      next_char = readChar();
    } while (next_char != '"');
  } else {
    switch(next_char) {
      // simbolos
      case '(':
        token = LEFT_PARENTHESIS;

        next_char = readChar();
        break;

      case '+':
        next_char = readChar();
        if (next_char == '+') { token = PLUS_PLUS; next_char = readChar(); }
        else { token = PLUS; } 
        break;

      // token regular char
      case '\'':
        next_char = readChar();
        token = CHARACTER;
        token2 = addCharConst (next_char);
        next_char = readChar();
        if ('\'' != next_char) token = UNKNOWN;

        next_char = readChar();
        break;
    }
  }

  return token;
}
*/
