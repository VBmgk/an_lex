#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "alexical_an.hpp"

/*int nextToken(int &i, int &token2) {
  switch (i++) {
  case 1:
    return FUNCTION;
  case 2:
    token2 = 1;
    return ID;
  case 3:
    return LEFT_PARENTHESIS;
  case 4:
    token2 = 2;
    return ID;
  case 5:
    return RIGHT_PARENTHESIS;
  case 6:
    return LEFT_BRACES;
  case 7:
    token2 = 2;
    return ID;
  case 8:
    return PLUS_PLUS;
  case 9:
    return SEMI_COLON;
  case 10:
    token2 = 3;
    return ID;
  case 11:
    return EQUALS;
  case 12:
    return NUMERAL;
  case 13:
    return SEMI_COLON;
  case 14:
    return PLUS;
  case 15:
    return VAR;
  case 16:
    token2 = 1;
    return NUMERAL;
  case 17:
    token2 = 2;
    return NUMERAL;
  case 18:
    token2 = 3;
    return CHARACTER;
  case 19:
    token2 = 4;
    return STRINGVAL;
  case 20:
    return RIGHT_BRACES;
  }

  return 0;
}
*/

TEST_CASE("Teste do Analizador Alexico ¬¬", "[nextToken]") {
  // Load test_code.lang
  AlexicalAnalizer test_code("src/test_code.lang");
  //--------------------
  // function f (a) {
  //  a++;
  //  b=1;
  //  +
  //  var
  //  10
  //  20
  //  'c'
  //  "ALO"
  //}
  //--------------------
  REQUIRE(test_code.nextToken() == FUNCTION);
  REQUIRE(test_code.nextToken() == ID);
  REQUIRE(test_code.getLastToken2() == 1);
  REQUIRE(test_code.nextToken() == LEFT_PARENTHESIS);
  REQUIRE(test_code.nextToken() == ID);
  REQUIRE(test_code.getLastToken2() == 2);
  REQUIRE(test_code.nextToken() == RIGHT_PARENTHESIS);
  REQUIRE(test_code.nextToken() == LEFT_BRACES);
  REQUIRE(test_code.nextToken() == ID);
  REQUIRE(test_code.getLastToken2() == 2);
  REQUIRE(test_code.nextToken() == PLUS_PLUS);
  REQUIRE(test_code.nextToken() == SEMI_COLON);
  REQUIRE(test_code.nextToken() == ID);
  REQUIRE(test_code.getLastToken2() == 3);
  REQUIRE(test_code.nextToken() == EQUALS);
  REQUIRE(test_code.nextToken() == NUMERAL);
  REQUIRE(test_code.nextToken() == SEMI_COLON);
  REQUIRE(test_code.nextToken() == PLUS);
  REQUIRE(test_code.nextToken() == VAR);
  REQUIRE(test_code.nextToken() == NUMERAL);
  REQUIRE(test_code.getLastToken2() == 1);
  REQUIRE(test_code.nextToken() == NUMERAL);
  REQUIRE(test_code.getLastToken2() == 2);
  REQUIRE(test_code.nextToken() == CHARACTER);
  REQUIRE(test_code.getLastToken2() == 3);
  REQUIRE(test_code.nextToken() == STRINGVAL);
  REQUIRE(test_code.getLastToken2() == 4);
  REQUIRE(test_code.nextToken() == RIGHT_BRACES);
}
