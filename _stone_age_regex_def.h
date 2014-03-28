//
//  def.h
//  CC
//
//  Created by Tian Jin on 14-3-25.
//  Copyright (c) 2014年 Tian Jin. All rights reserved.
//

#ifndef CC_def_h
#define CC_def_h

#define CC_EPSILON ""

#include <string>
#include <sstream>

using namespace std;

template<class node, class edge>
class nfa {
public:
    nfa(edge* start, node* end):_end(end), _start(start)
    {
    }
    node* _end;
    edge* _start;
};

enum LEX_TOKEN {
    TOKEN_NOT_FOUND,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_ASTERISK,
    TOKEN_QUESTION_MARK,
    TOKEN_PIPE,
    TOKEN_LSQUARE,
    TOKEN_RSQUARE,
    TOKEN_CONNECT,
    TOKEN_LITERAL
};

class lex_parcel {
public:
    lex_parcel(LEX_TOKEN type, char val): _type(type), _val(val)
    {
    
    }
    LEX_TOKEN _type;
    char _val;
};

static string char_to_string(char c)
{
    stringstream ss;
    string s;
    ss << c;
    ss >> s;
    return s;
}

#endif
