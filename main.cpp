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

using namespace std;

bool traverse_nfa(edge<nfa_node>* start, string input, int index);
void traverse_debug(edge<nfa_node>* start);

typedef nfa<nfa_node, edge<nfa_node>> t_nfa;

typedef void (*handlr)(int);

void connect_nfa(t_nfa* previous, t_nfa* next)
{
    previous->_end->push_started(next->_start);
}

t_nfa* get_a(string input, bool accept = false, handlr accept_handlr = nullptr)
{
    nfa_node* a_node = new nfa_node(false, "");
    edge<nfa_node>* a_edge = new edge<nfa_node>(0, a_node, input);
    a_node->push_terminated(a_edge);
    
    t_nfa* a = new t_nfa(a_edge, a_node);
    return a;
}

t_nfa* get_Epsilon()
{
    nfa_node* e_node = new nfa_node(false, "");
    edge<nfa_node>* e_edge = new edge<nfa_node>(0, e_node, CC_EPSILON);
    e_node->push_terminated(e_edge);
    
    t_nfa* e = new t_nfa(e_edge, e_node);
    return e;
}

t_nfa* get_M_or_N(t_nfa* N, t_nfa* M)
{
    t_nfa* start_nfa = get_Epsilon();
    connect_nfa(start_nfa, N);
    connect_nfa(start_nfa, M);
    
    nfa_node* e_node = new nfa_node(false, "");
    edge<nfa_node>* e_edge_N = new edge<nfa_node>(0, e_node, CC_EPSILON);
    edge<nfa_node>* e_edge_M = new edge<nfa_node>(0, e_node, CC_EPSILON);
    
    e_node->push_terminated(e_edge_N);
    e_node->push_terminated(e_edge_M);
    
    N->_end->push_started(e_edge_N);
    M->_end->push_started(e_edge_M);
    
    t_nfa* mn = new t_nfa(start_nfa->_start, e_node);
    return mn;
}

t_nfa* get_M_and_N(t_nfa* N, t_nfa* M)
{
    connect_nfa(N, M);
    
    t_nfa* mn = new t_nfa(N->_start, M->_end);
    return mn;
}

t_nfa* get_M_star(t_nfa* M)
{
    t_nfa* start_nfa = get_Epsilon();
    connect_nfa(start_nfa, M);
    
    edge<nfa_node>* e_edge = new edge<nfa_node>(M->_end, start_nfa->_end, CC_EPSILON);
    M->_end->push_started(e_edge);
    start_nfa->_end->push_terminated(e_edge);
    
    t_nfa* ms = new t_nfa(start_nfa->_start, start_nfa->_end);
    return ms;
}

t_nfa* get_M_plus(t_nfa* M)
{
    t_nfa* M_star = get_M_star(M);
    connect_nfa(M, M_star);
    
    t_nfa* mp = new t_nfa(M->_start, M_star->_end);
    return mp;
}

t_nfa* get_M_question(t_nfa* M)
{
    t_nfa* e = get_Epsilon();
    t_nfa* mq = get_M_or_N(M, e);
    
    return mq;
}

int main(int argc, const char * argv[])
{
    string input = "aaa";
    t_nfa* nfa_a = get_a("a");
    t_nfa* nfa_e = get_a("e");
    t_nfa* nfa_f = get_a("f");
    
    t_nfa* nfa_a_star = get_M_star(nfa_a);
    nfa_a_star->_end->set_accept();
//    t_nfa* mn = get_M_or_N(nfa_a, nfa_e);
//    t_nfa* mn2 = get_M_and_N(mn, nfa_f);
    
    cout << "==debug session start==" << endl;
    //traverse_debug(mn2->_start);
    cout << "==debug session end==" << endl;
    
    bool match = traverse_nfa(nfa_a_star->_start, input, 0);
    
    if (match)
        cout << "Match";
    else
        cout << "Doesn't Match";
    
    return 0;
}

