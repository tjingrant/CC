//
//  grammar.cpp
//  CC
//
//  Created by Tian Jin on 14-3-26.
//  Copyright (c) 2014年 Tian Jin. All rights reserved.
//

#include "_stone_age_grammar.h"
#include "_stone_age_regex_def.h"
#include "_stone_age_regex_nfa_node.h"


t_nfa* analyze_grammar(lex_stack* input)
{
    
    std::list<t_nfa*> nfa_stack = std::list<t_nfa*>();
    
    std::list<lex_parcel>::const_iterator iterator;
    for (iterator = input->begin(); iterator != input->end(); ++iterator) {
        lex_parcel lp = *iterator;
        switch (lp._type) {
            case TOKEN_LITERAL: {
                nfa_stack.push_front(thompsons_construction::get_a(char_to_string(lp._val)));
                cout << lp._val;
                break;
            }
            case TOKEN_CONNECT: {
                cout << "-";
                t_nfa* after = nfa_stack.front();
                nfa_stack.pop_front();
                t_nfa* before = nfa_stack.front();
                nfa_stack.pop_front();
                nfa_stack.push_front(thompsons_construction::get_M_and_N(before, after));
                break;
            }
            default: {
                break;
            }
        }
    }
    
    return nfa_stack.front();
}