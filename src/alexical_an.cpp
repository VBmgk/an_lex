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
  // as the ifstream do this for me
}

char AlexicalAnalizer::readChar(void) {
  char buff = ' ';
  if (!source_code.eof()) {
    source_code >> buff;
    if (source_code.good())
      return buff;
  }
}

bool AlexicalAnalizer::isDigit(char ch) {
  return (ch < '0' || ch > '9') ? false : true;
}
t_token AlexicalAnalizer::addCharConst(char ch) {
  t_token token;
  return token;
}

t_token AlexicalAnalizer::addIntConst(char ch) {
  t_token token;
  return token;
}

t_token AlexicalAnalizer::nextToken(void) {
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

    next_char = readChar(); // to remove

    do {
      string[i++] = next_char;
      next_char = readChar();
    } while (next_char != '"');
  } else {
    switch (next_char) {
    // simbolos
    case '(':
      token = LEFT_PARENTHESIS;

      next_char = readChar();
      break;

    case '+':
      next_char = readChar();
      if (next_char == '+') {
        token = PLUS_PLUS;
        next_char = readChar();
      } else {
        token = PLUS;
      }
      break;

    // token regular char
    case '\'':
      next_char = readChar();
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
