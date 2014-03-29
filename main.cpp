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

int traverse_nfa(edge<nfa_node>* start, string input, int index);
void traverse_debug(edge<nfa_node>* start, int max = 1000, int current = 0);
t_nfa* analyze_grammar(lex_stack input);

int main(int argc, const char * argv[])
{
    string input = "b*a-";
    string to_test = "bba";
    t_nfa* nfa = analyze_grammar(analyze(input));
    traverse_debug(nfa->_start);
    int match_id = traverse_nfa(nfa->_start,to_test, 0);
    cout << "largest match ends at index: " << match_id;
    return 0;
}

