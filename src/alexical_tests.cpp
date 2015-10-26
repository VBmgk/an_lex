#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "alexical_an.hpp"

TEST_CASE("Teste do Analizador Alexico ¬¬", "[nextToken]") {
  // Load test_code.lang
  AlexicalAnalizer test_code("test_code.lang");
  // -------------------
  // searchKeyWord tests
  // -------------------
  SECTION("Teste das Keywords", "") {
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
  }

  SECTION("Teste da geração dos tokens","") {
    // -------------------
    // test token generation (vide source code test_code.lang)
    // -------------------
    CHECK(test_code.nextToken() == FUNCTION);
    CHECK(test_code.nextToken() == ID);
    CHECK(test_code.nextToken() == LEFT_PARENTHESIS);
    CHECK(test_code.nextToken() == ID);
    CHECK(test_code.nextToken() == RIGHT_PARENTHESIS);
    CHECK(test_code.nextToken() == LEFT_BRACES);
    CHECK(test_code.nextToken() == ID);
    CHECK(test_code.nextToken() == PLUS_PLUS);
    CHECK(test_code.nextToken() == SEMI_COLON);
    CHECK(test_code.nextToken() == ID);
    CHECK(test_code.nextToken() == EQUALS);
    CHECK(test_code.nextToken() == NUMERAL);
    CHECK(test_code.nextToken() == SEMI_COLON);
    CHECK(test_code.nextToken() == PLUS);
    CHECK(test_code.nextToken() == VAR);
    CHECK(test_code.nextToken() == NUMERAL);
    CHECK(test_code.nextToken() == NUMERAL);
    CHECK(test_code.nextToken() == NOT);
    CHECK(test_code.nextToken() == NOT_EQUAL);
    CHECK(test_code.nextToken() == NOT);
    CHECK(test_code.nextToken() == RIGHT_BRACES);
    CHECK(test_code.nextToken() == CHARACTER);
    CHECK(test_code.nextToken() == STRINGVAL);
    CHECK(test_code.nextToken() == STRINGVAL);
    CHECK(test_code.nextToken() == MINUS);
    CHECK(test_code.nextToken() == MINUS_MINUS);
    CHECK(test_code.nextToken() == TIMES);
    CHECK(test_code.nextToken() == DIVIDE);
    CHECK(test_code.nextToken() == TYPE);
    CHECK(test_code.nextToken() == STRUCT);
    CHECK(test_code.nextToken() == ID);
    CHECK(test_code.nextToken() == LEFT_SQUARE);
    CHECK(test_code.nextToken() == NUMERAL);
    CHECK(test_code.nextToken() == RIGHT_SQUARE);
    CHECK(test_code.nextToken() == COLON);
    CHECK(test_code.nextToken() == INTEGER);
    CHECK(test_code.nextToken() == COMMA);

    CHECK(test_code.nextToken() == WHILE);
    CHECK(test_code.nextToken() == ID);
    CHECK(test_code.nextToken() == DO);
    CHECK(test_code.nextToken() == ID);
    CHECK(test_code.nextToken() == IF);
    CHECK(test_code.nextToken() == ID);

    CHECK(test_code.nextToken() == LESS_THAN);
    CHECK(test_code.nextToken() == GREATER_THAN);
    CHECK(test_code.nextToken() == LESS_OR_EQUAL);
    CHECK(test_code.nextToken() == GREATER_OR_EQUAL);

    CHECK(test_code.nextToken() == RIGHT_BRACES);
    CHECK(test_code.nextToken() == RIGHT_BRACES);
  }
}
