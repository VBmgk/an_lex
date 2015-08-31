#include <cstdlib>
#include <cstdio>
#include <fstream>

#include "alexical_an.hpp"

int main(void) {
  printf("\nCompilador\n");
  AlexicalAnalizer lexical_an("../src/test_code.lang");

  /*  t_token token;

    token = FUNCTION; printf("\n token num: %d \n", token);
    token = CHARACTER; printf("\n token num: %d \n", token);
    token = ID; printf("\n token num: %d \n", token);
  */
  return 0;
}
