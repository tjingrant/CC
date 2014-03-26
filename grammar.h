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
#include <list>

typedef list<lex_parcel> lex_stack;

void analyze_grammar(lex_stack input);

#endif /* defined(__CC__grammar__) */
