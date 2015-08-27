#include <cstdlib>
#include <cstdio>
#include <fstream>

#include "alexical_an.hpp"

int main(void) {
  printf("\nCompilador\n");
  AlexicalAnalizer lexical_an("../src/test_code.lang");
  if (lexical_an.isDigit('0'))
    printf("\nit is!!\n");
  if (lexical_an.isDigit('5'))
    printf("\nit is!!\n");
  if (lexical_an.isDigit('9'))
    printf("\nit is!!\n");
  if (lexical_an.isDigit('c'))
    printf("\nit is!!\n");
  else
    printf("\nit's not...\n");

  /*  t_token token;

    token = FUNCTION; printf("\n token num: %d \n", token);
    token = CHARACTER; printf("\n token num: %d \n", token);
    token = ID; printf("\n token num: %d \n", token);
  */
  return 0;
}
