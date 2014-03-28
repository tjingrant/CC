//
//  _stone_age_thompsons_construction.h
//  CC
//
//  Created by Tian Jin on 14-3-27.
//  Copyright (c) 2014年 Tian Jin. All rights reserved.
//

#ifndef __CC___stone_age_thompsons_construction__
#define __CC___stone_age_thompsons_construction__

#include <iostream>
#include "_stone_age_regex_def.h"
#include "_stone_age_regex_edge.h"
#include "_stone_age_regex_nfa_node.h"

typedef nfa<nfa_node, edge<nfa_node>> t_nfa;

class thompsons_construction
{
public:
    static void connect_nfa(t_nfa* previous, t_nfa* next);
    
    
    //todo: the accept states needed to be indicated somewhere if not here
    static t_nfa* get_a(string input, bool accept = false);
    
    static t_nfa* get_Epsilon();
    
    static t_nfa* get_M_or_N(t_nfa* N, t_nfa* M);
    
    static t_nfa* get_M_and_N(t_nfa* N, t_nfa* M);
    
    static t_nfa* get_M_star(t_nfa* M);
    
    static t_nfa* get_M_plus(t_nfa* M);
    
    static t_nfa* get_M_question(t_nfa* M);
};


#endif /* defined(__CC___stone_age_thompsons_construction__) */
