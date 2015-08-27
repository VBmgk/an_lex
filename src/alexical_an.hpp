#ifndef ALEXICAL_AN
#define ALEXICAL_AN
#define MAX_STRING_SIZE 50

typedef enum {
  // palavras reservadas
  ARRAY,
  BOOLEAN,
  BREAK,
  CHAR,
  CONTINUE,
  DO,
  ELSE,
  FALSE,
  FUNCTION,
  IF,
  INTEGER,
  OF,
  STRING,
  STRUCT,
  TRUE,
  TYPE,
  VAR,
  WHILE,
  // simbolos
  COLON,
  SEMI_COLON,
  COMMA,
  EQUALS,
  LEFT_SQUARE,
  RIGHT_SQUARE,
  LEFT_BRACES,
  RIGHT_BRACES,
  LEFT_PARENTHESIS,
  RIGHT_PARENTHESIS,
  AND,
  OR,
  LESS_THAN,
  GREATER_THAN,
  LESS_OR_EQUAL,
  GREATER_OR_EQUAL,
  NOT_EQUAL,
  EQUAL_EQUAL,
  PLUS,
  PLUS_PLUS,
  MINUS,
  MINUS_MINUS,
  TIMES,
  DIVIDE,
  DOT,
  NOT,
  // tokens regulares
  CHARACTER,
  NUMERAL,
  STRINGVAL,
  ID,
  // token deconhecido
  UNKNOWN
} t_token;

class AlexicalAnalizer {
  std::ifstream source_code;
  t_token last_token, last_token2;

public:
  AlexicalAnalizer(std::string);
  ~AlexicalAnalizer(void);
  void skipSeparators(void);
  char readChar(void);
  bool isDigit(char);
  t_token addCharConst(char);
  t_token addIntConst(char);
  t_token addStringConst(std::string);
  t_token nextToken(void);
  int getLastToken2(void);
};
#endif
