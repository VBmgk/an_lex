#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "alexical_an.hpp"

int nextToken(int &i, int &token2) {
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

TEST_CASE("Teste do Analizador Alexico ¬¬", "[nextToken]") {
  // Load test_code.lang
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
  int i = 1, token2 = 0;
  REQUIRE(nextToken(i, token2) == FUNCTION);
  REQUIRE(nextToken(i, token2) == ID);
  REQUIRE(token2 == 1);
  REQUIRE(nextToken(i, token2) == LEFT_PARENTHESIS);
  REQUIRE(nextToken(i, token2) == ID);
  REQUIRE(token2 == 2);
  REQUIRE(nextToken(i, token2) == RIGHT_PARENTHESIS);
  REQUIRE(nextToken(i, token2) == LEFT_BRACES);
  REQUIRE(nextToken(i, token2) == ID);
  REQUIRE(token2 == 2);
  REQUIRE(nextToken(i, token2) == PLUS_PLUS);
  REQUIRE(nextToken(i, token2) == SEMI_COLON);
  REQUIRE(nextToken(i, token2) == ID);
  REQUIRE(token2 == 3);
  REQUIRE(nextToken(i, token2) == EQUALS);
  REQUIRE(nextToken(i, token2) == NUMERAL);
  REQUIRE(nextToken(i, token2) == SEMI_COLON);
  REQUIRE(nextToken(i, token2) == PLUS);
  REQUIRE(nextToken(i, token2) == VAR);
  REQUIRE(nextToken(i, token2) == NUMERAL);
  REQUIRE(token2 == 1);
  REQUIRE(nextToken(i, token2) == NUMERAL);
  REQUIRE(token2 == 2);
  REQUIRE(nextToken(i, token2) == CHARACTER);
  REQUIRE(token2 == 3);
  REQUIRE(nextToken(i, token2) == STRINGVAL);
  REQUIRE(token2 == 4);
  REQUIRE(nextToken(i, token2) == RIGHT_BRACES);
}
