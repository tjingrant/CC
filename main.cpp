//
//  main.cpp
//  CC
//
//  Created by Tian Jin on 14-3-24.
//  Copyright (c) 2014年 Tian Jin. All rights reserved.
//

#include <iostream>
#include <list>
#include "_stone_age_regex_edge.h"
#include "_stone_age_regex_nfa_node.h"
#include "_stone_age_regex_def.h"
#include "_stone_age_thompsons_construction.h"
#include "_stone_age_lex.h"
#include "_stone_age_grammar.h"

using namespace std;

bool traverse_nfa(edge<nfa_node>* start, string input, int index);
void traverse_debug(edge<nfa_node>* start);
t_nfa* analyze_grammar(lex_stack input);

int main(int argc, const char * argv[])
{
    string input = "ab-a-b-c-d-f-e-";
    string to_test = "ababcdf";
    t_nfa* nfa = analyze_grammar(analyze(input));
    traverse_debug(nfa->_start);
    for (int i = 0; i<1; i++)
        cout << traverse_nfa(nfa->_start,to_test, 0);
    
    return 0;
}

