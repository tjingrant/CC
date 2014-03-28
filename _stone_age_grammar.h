//
//  grammar.h
//  CC
//
//  Created by Tian Jin on 14-3-26.
//  Copyright (c) 2014年 Tian Jin. All rights reserved.
//

#ifndef __CC__grammar__
#define __CC__grammar__

#include <iostream>
#include "_stone_age_regex_def.h"
#include "_stone_age_thompsons_construction.h"
#include <list>

using namespace std;

typedef list<lex_parcel> lex_stack;

t_nfa* analyze_grammar(lex_stack* input);

#endif /* defined(__CC__grammar__) */
