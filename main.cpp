//
//  main.cpp
//  CC
//
//  Created by Tian Jin on 14-3-24.
//  Copyright (c) 2014年 Tian Jin. All rights reserved.
//

#include <iostream>
#include <list>
#include "edge.h"
#include "nfa_node.h"

#define EPSILON ""

using namespace std;



void traverse_nfa(edge<nfa_node>* start);

int main(int argc, const char * argv[])
{
    nfa_node* a_node = new nfa_node(false, "");
    edge<nfa_node>* a_edge = new edge<nfa_node>(0, a_node, "a");
    a_node->push_terminated(a_edge);
    nfa_node* e_node = new nfa_node(false, "");
    edge<nfa_node>* e_edge = new edge<nfa_node>(0, e_node, EPSILON);
    a_node->push_started(e_edge);
    e_node->push_terminated(e_edge);
    
    traverse_nfa(a_edge);
    
    return 0;
}

