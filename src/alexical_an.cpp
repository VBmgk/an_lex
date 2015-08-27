#include <string>
#include <cstdio>
#include <fstream>
#include "alexical_an.hpp"

int AlexicalAnalizer::getLastToken2(void) { return last_token2; }

AlexicalAnalizer::AlexicalAnalizer(std::string source_code_name) {
  // open file
  source_code.open(source_code_name.c_str());
}

AlexicalAnalizer::~AlexicalAnalizer() {
  // close file
  source_code.close();
  source_code.clear();
}

void AlexicalAnalizer::skipSeparators(void) {
  // seems like I don't need this function
  // as the ifstream do this for me...
  // maybe for comments...
}

char AlexicalAnalizer::readChar(void) {
  char buff = ' ';
  if (!source_code.eof()) {
    source_code >> buff;
    if (source_code.good())
      return buff;
  }
}

t_token searchKeyWord(char *name) {
    // regular key words
    if(strcmp(name,"array")) return ARRAY;
    if(strcmp(name, "boolean")) return BOOLEAN;
    if(strcmp(name, "break")) return BREAK;
    if(strcmp(name, "char")) return CHAR;
    if(strcmp(name, "continue")) return CONTINUE;
    if(strcmp(name, "do")) return DO;
    if(strcmp(name, "else")) return ELSE;
    if(strcmp(name, "false")) return FALSE;
    if(strcmp(name, "function")) return FUNCTION;
    if(strcmp(name, "if")) return IF;
    if(strcmp(name, "integer")) return INTEGER;
    if(strcmp(name, "of")) return OF;
    if(strcmp(name, "string")) return STRING;
    if(strcmp(name, "struct")) return STRUCT;
    if(strcmp(name, "true")) return TRUE;
    if(strcmp(name, "type")) return TYPE;
    if(strcmp(name, "var")) return VAR;
    if(strcmp(name, "while")) return WHILE;
    // -> And
    // -> Dot
    // -> Or
    // -> Not
}

bool AlexicalAnalizer::isDigit(char ch) {
  return (ch < '0' || ch > '9') ? false : true;
}

t_token AlexicalAnalizer::addCharConst(char ch) {
  // TODO
  t_token token;
  return token;
}

t_token AlexicalAnalizer::addIntConst(char ch) {
  // TODO
  t_token token;
  return token;
}

t_token AlexicalAnalizer::nextToken(void) {
  // TODO: Make struct for token2
  t_token token, token2;

  char next_char;

  // Trata comentários
  skipSeparators();
  // Numeral
  if (isDigit(next_char)) {
    int n = 0;
    do {
      n = n * 10 + (next_char - '0');
      next_char = readChar();
    } while (isDigit(next_char));

    // update token variables
    token = NUMERAL;
    token2 = addIntConst(n);
  }
  // Stringval
  if (next_char == '"') {
    char string[MAX_STRING_SIZE + 1];
    int i = 0;
    // to remove '"' from string
    next_char = readChar();
    // store value of string on variable
    do {
      string[i++] = next_char;
      next_char = readChar();
    } while (next_char != '"');

    // update token variables
    token = STRINGVAL;
    token2 = addStringConst(string);
  } else {
    switch (next_char) {
    /***********************
     * Palavras Reservadas *
     ***********************/
    case 'a-z' 'A-Z'
    /************
     * SIMBOLOS *
     ************/
    // COLON
    case ':':
      next_char = readChar();
      token = COLON;
    // SEMI_COLON
    case ';':
      next_char = readChar();
      token = SEMI_COLON;
    // COMMA
    case ',':
      next_char = readChar();
      token = COMMA;
      break;
    // 'Squares'
    case '[':
      next_char = readChar();
      token = LEFT_SQUARE;
      break;
    case ']':
      next_char = readChar();
      token = RIGHT_SQUARE;
      break;
    // Braces
    case '{':
      next_char = readChar();
      token = LEFT_BRACES;
      break;
    case '}':
      next_char = readChar();
      token = RIGHT_BRACES;
      break;
    // Parenthesis
    case '(':
      next_char = readChar();
      token = LEFT_PARENTHESIS;
      break;
    case ')':
      next_char = readChar();
      token = RIGHT_PARENTHESIS;
      break;
    // Less_than and Less_or_equal
    case '<':
      next_char = readChar();
      token = LESS_THAN;
      if (next_char == '=') {
        token = LESS_OR_EQUAL;
        next_char = readChar();
      }
      break;
    // Greater_than and Greater_or_equal
    case '>':
      next_char = readChar();
      token = GREATER_THAN;
      if (next_char == '=') {
        token = GREATER_OR_EQUAL;
        next_char = readChar();
      }
      break;
    // Not_equal
    case '!': // TODO
      break;
    // Equals and equal_equal
    case '=':
      next_char = readChar();
      if (nex_char == '=') {
        token = EQUAL_EQUAL;
        next_char = readChar();
      } else {
        token = EQUALS;
      }
    // Plus and plus_plus
    case '+':
      next_char = readChar();
      if (next_char == '+') {
        token = PLUS_PLUS;
        next_char = readChar();
      } else {
        token = PLUS;
      }
      break;
    // Minus and minus_minus
    case '-':
      next_char = readChar();
      if (next_char == '-') {
        token = MINUS_MINUS;
        next_char = readChar();
      } else {
        token = MINUS;
      }
      break;
    // Times
    case '*':
      next_char = readChar();
      token = TIMES;
      break;
    // Divide
    case '/':
      next_char = readChar();
      token = DIVIDE;
      break;
    /********************
     * Tokens Regulares *
     ********************/
    // Character
    case '\'':
      next_char = readChar();
      // update token variable
      token = CHARACTER;
      token2 = addCharConst(next_char);
      next_char = readChar();
      if ('\'' != next_char)
        token = UNKNOWN;
      next_char = readChar();
      break;
    }
  }

  return token;
}
