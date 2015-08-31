#include <string>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <cctype>
#include "alexical_an.hpp"

int AlexicalAnalizer::searchName(std::string name) {
  int i = 0;
  // search in vector token_sec
  for (auto know_id: const_table) {
    if (know_id.type == ID && strcmp(know_id.id_name, name.c_str()) == 0) return i;
    i++;
  }

  // Add id to table
  ConstValue buff;
  buff.type = ID;
  strcpy(buff.id_name, name.c_str());
  const_table.push_back(buff);

  return i;
}
  
int AlexicalAnalizer::getLastToken2(void) { return last_token2; }

AlexicalAnalizer::AlexicalAnalizer(std::string source_code_name) {
  // open file
  source_code.open(source_code_name.c_str());
  // read first char of file
  next_char = readChar();
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
  while (next_char == ' ' || next_char == '\n') {
    next_char = readChar();
  }
}

char AlexicalAnalizer::readChar(void) {
  char buff = '@';
  if (!source_code.eof()) {
    buff = source_code.get();
    if (source_code.good()) {
      return buff;
    }
  }
  return buff;
}

t_token AlexicalAnalizer::searchKeyWord(std::string name) {
  // regular key words
  if(name == "array") return ARRAY;
  if(name == "boolean") return BOOLEAN;
  if(name == "break") return BREAK;
  if(name == "char") return CHAR;
  if(name == "continue") return CONTINUE;
  if(name == "do") return DO;
  if(name == "else") return ELSE;
  if(name == "false") return FALSE;
  if(name == "function") return FUNCTION;
  if(name == "if") return IF;
  if(name == "integer") return INTEGER;
  if(name == "of") return OF;
  if(name == "string") return STRING;
  if(name == "struct") return STRUCT;
  if(name == "true") return TRUE;
  if(name == "type") return TYPE;
  if(name == "var") return VAR;
  if(name == "while") return WHILE;
  if(name == "and") return AND;
  if(name == "or") return OR;
  if(name == "not") return NOT;
  
  return ID;
}

int AlexicalAnalizer::addCharConst(char value) {
  // setup values
  ConstValue buff;
  buff.type = CHARACTER; 
  buff.char_const = value;
  // add to table
  const_table.push_back(buff);
  return const_table.size() - 1;
}

int AlexicalAnalizer::addIntConst(int value) {
  // setup values
  ConstValue buff;
  buff.type = INTEGER; 
  buff.int_const = value;
  // add to table
  const_table.push_back(buff);
  return const_table.size() - 1;
}

int AlexicalAnalizer::addStringConst(std::string value) {
  // setup values
  ConstValue buff;
  buff.type = STRINGVAL; 
  strcpy(buff.string_const, value.c_str());
  // add to table
  const_table.push_back(buff);
  return const_table.size() - 1;
} 

t_token AlexicalAnalizer::nextToken(void) {
  t_token token;
  int token2 = -1;

  // Trata comentários
  skipSeparators();
  // Alfa numerico
  if (isalpha(next_char)) {
    // Palavras Reservadas
    char text[MAX_STRING_SIZE];
    // init text
    for (int i=0; i<MAX_STRING_SIZE ;i++) { text[i] = '\0'; }
    int i = 0;
    do {
      text[i++] = next_char;
      next_char = readChar();
    } while (isalnum(next_char) || next_char == '_');
    // discover alpha type
    token = searchKeyWord(text);
    // if is a id, add to table
    if (token == ID) { token2 = searchName(text); }
  }
  // Numeral
  else if (isdigit(next_char)) {
    int n = 0;
    do {
      n = n * 10 + (next_char - '0');
      next_char = readChar();
    } while (isdigit(next_char));

    // update token variables
    token = NUMERAL;
    token2 = addIntConst(n);
  }
  // Stringval
  else if (next_char == '"') {
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
    /************
     * SIMBOLOS *
     ************/
    case '.':
      next_char = readChar();
      token = DOT;
      break;
    // COLON
    case ':':
      next_char = readChar();
      token = COLON;
      break;
    // SEMI_COLON
    case ';':
      next_char = readChar();
      token = SEMI_COLON;
      break;
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
    case '!':
      next_char = readChar();
      if (next_char == '=') {
        token = NOT_EQUAL;
        next_char = readChar();
      } else {
        token = NOT;
      }
      break;
    // Equals and equal_equal
    case '=':
      next_char = readChar();
      if (next_char == '=') {
        token = EQUAL_EQUAL;
        next_char = readChar();
      } else {
        token = EQUALS;
      }
      break;
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
  // setup last token variables
  last_token = token;
  last_token2 = token2;

  return token;
}
