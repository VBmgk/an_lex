#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "alexical_an.hpp"

TEST_CASE("Teste do Analizador Alexico ¬¬", "[nextToken]") {
  // Load test_code.lang
  AlexicalAnalizer test_code("src/test_code.lang");

  // -------------------
  // searchKeyWord tests
  // -------------------
  CHECK(test_code.searchKeyWord("array") == ARRAY);
  CHECK(test_code.searchKeyWord("boolean") == BOOLEAN);
  CHECK(test_code.searchKeyWord("break") == BREAK);
  CHECK(test_code.searchKeyWord("char") == CHAR);
  CHECK(test_code.searchKeyWord("continue") == CONTINUE);
  CHECK(test_code.searchKeyWord("do") == DO);
  CHECK(test_code.searchKeyWord("else") == ELSE);
  CHECK(test_code.searchKeyWord("false") == FALSE);
  CHECK(test_code.searchKeyWord("function") == FUNCTION);
  CHECK(test_code.searchKeyWord("if") == IF);
  CHECK(test_code.searchKeyWord("integer") == INTEGER);
  CHECK(test_code.searchKeyWord("of") == OF);
  CHECK(test_code.searchKeyWord("string") == STRING);
  CHECK(test_code.searchKeyWord("struct") == STRUCT);
  CHECK(test_code.searchKeyWord("true") == TRUE);
  CHECK(test_code.searchKeyWord("type") == TYPE);
  CHECK(test_code.searchKeyWord("var") == VAR);
  CHECK(test_code.searchKeyWord("while") == WHILE);
  CHECK(test_code.searchKeyWord("and") == AND);
  CHECK(test_code.searchKeyWord("or") == OR);
  CHECK(test_code.searchKeyWord("not") == NOT);

  // -------------------
  // test token generation
  // -------------------
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
  CHECK(test_code.nextToken() == FUNCTION);
  CHECK(test_code.nextToken() == ID);
  //CHECK(test_code.getLastToken2() == 0);
  CHECK(test_code.searchName("f") == 0);
  CHECK(test_code.nextToken() == LEFT_PARENTHESIS);
  CHECK(test_code.nextToken() == ID);
  CHECK(test_code.searchName("a") == 1);
  //CHECK(test_code.getLastToken2() == 1);
  CHECK(test_code.nextToken() == RIGHT_PARENTHESIS);
  CHECK(test_code.nextToken() == LEFT_BRACES);
  CHECK(test_code.nextToken() == ID);
  CHECK(test_code.searchName("a") == 1);
  //CHECK(test_code.getLastToken2() == 1);
  CHECK(test_code.nextToken() == PLUS_PLUS);
  CHECK(test_code.nextToken() == SEMI_COLON);
  CHECK(test_code.nextToken() == ID);
  CHECK(test_code.searchName("b") == 2);
  //CHECK(test_code.getLastToken2() == 2);
  CHECK(test_code.nextToken() == EQUALS);
  CHECK(test_code.nextToken() == NUMERAL);
  CHECK(test_code.nextToken() == SEMI_COLON);
  CHECK(test_code.nextToken() == PLUS);
  CHECK(test_code.nextToken() == VAR);
  CHECK(test_code.nextToken() == NUMERAL);
  CHECK(test_code.getLastToken2() == 0);
  CHECK(test_code.nextToken() == NUMERAL);
  CHECK(test_code.getLastToken2() == 1);
  CHECK(test_code.nextToken() == CHARACTER);
  CHECK(test_code.getLastToken2() == 2);
  CHECK(test_code.nextToken() == STRINGVAL);
  CHECK(test_code.getLastToken2() == 3);
  CHECK(test_code.nextToken() == RIGHT_BRACES);
}
