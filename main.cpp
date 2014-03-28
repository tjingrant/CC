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
    bool match = traverse_nfa(nfa->_start,to_test, 0);
    cout << match;
//    thompsons_construction::get_a("a");
//    string input = "aaa";
//    t_nfa* nfa_a = get_a("a");
//    t_nfa* nfa_e = get_a("e");
//    t_nfa* nfa_f = get_a("f");
//    
//    t_nfa* nfa_a_star = get_M_star(nfa_a);
//    nfa_a_star->_end->set_accept();
////    t_nfa* mn = get_M_or_N(nfa_a, nfa_e);
////    t_nfa* mn2 = get_M_and_N(mn, nfa_f);
//    
//    cout << "==debug session start==" << endl;
//    //traverse_debug(mn2->_start);
//    cout << "==debug session end==" << endl;
//    
//    bool match = traverse_nfa(nfa_a_star->_start, input, 0);
//    
//    if (match)
//        cout << "Match";
//    else
//        cout << "Doesn't Match";
    
    return 0;
}

