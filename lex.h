//
//  lex.h
//  CC
//
//  Created by Tian Jin on 14-3-25.
//  Copyright (c) 2014年 Tian Jin. All rights reserved.
//

//E -> literal
//E -> E literal
//E -> ( E )
//M -> E | E
//M -> E*
//M -> E+
//M -> E?

#ifndef __CC__lex__
#define __CC__lex__

#include <iostream>
#include <map>
#include <string>
#include <list>
#include "def.h"

using namespace std;

typedef list<lex_parcel> lex_stack;
typedef LEX_TOKEN (*lex_handlr)(char, lex_stack*, int);

static void analyze(string s)
{
    lex_stack* stack = new lex_stack();
    
    list<lex_handlr> handlr_list = {
        [] (char c, lex_stack* stack, int pos) -> LEX_TOKEN {
            return (c == '(') ? LEX_TOKEN::TOKEN_LPAREN : LEX_TOKEN::TOKEN_NOT_FOUND;
        },
        [] (char c, lex_stack* stack, int pos) -> LEX_TOKEN {
            return (c == ')') ? LEX_TOKEN::TOKEN_RPAREN : LEX_TOKEN::TOKEN_NOT_FOUND;
        },
        [] (char c, lex_stack* stack, int pos) -> LEX_TOKEN {
            cerr << "Illegal token encountered at position " << pos << endl;
            return LEX_TOKEN::TOKEN_NOT_FOUND;
        }
    };
    
    int pos = 0;
    std::list<lex_handlr>::const_iterator iterator;
    for(char& c : s) {
        for (iterator = handlr_list.begin(); iterator != handlr_list.end(); ++iterator) {
            LEX_TOKEN token = (*iterator)(c, stack, pos);
            if (token != LEX_TOKEN::TOKEN_NOT_FOUND) break;
        }
        pos++;
    }
}

#endif /* defined(__CC__lex__) */
