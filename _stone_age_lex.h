//
//  lex.h
//  CC
//
//  Created by Tian Jin on 14-3-25.
//  Copyright (c) 2014年 Tian Jin. All rights reserved.
//

#ifndef __CC__lex__
#define __CC__lex__

#include <iostream>
#include <map>
#include <string>
#include <list>
#include "_stone_age_regex_def.h"

#define CHECK_AND_RETURN(TO_CHECK,TO_RETURN)      \
do {\
if (c==TO_CHECK) { \
    stack->push_back(lex_parcel(LEX_TOKEN::TO_RETURN, c));\
    return LEX_TOKEN::TO_RETURN;\
}\
else {\
    return LEX_TOKEN::TOKEN_NOT_FOUND;\
}\
} while(0)\

using namespace std;

typedef list<lex_parcel> lex_stack;
typedef LEX_TOKEN (*lex_handlr)(char, lex_stack*, int);

lex_stack* analyze(string s);


#endif /* defined(__CC__lex__) */
