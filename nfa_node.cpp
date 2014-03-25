//
//  nfa_node.cpp
//  CC
//
//  Created by Tian Jin on 14-3-25.
//  Copyright (c) 2014年 Tian Jin. All rights reserved.
//

#include "nfa_node.h"

nfa_node::nfa_node(bool accept, string symbol, list<edge<nfa_node>*> terminated, list<edge<nfa_node>*> started): _accept(accept), _symbol(symbol), _terminated(terminated), _started(started)
{
    
}

nfa_node::nfa_node(bool accept, string symbol): _accept(accept), _symbol(symbol)
{
    _terminated = list<edge<nfa_node>*>();
    _started = list<edge<nfa_node>*>();
}

void nfa_node::push_terminated(edge<nfa_node>* edge) {
    _terminated.push_back(edge);
    edge->set_to(this);
}

void nfa_node::push_started(edge<nfa_node>* edge) {
    _started.push_back(edge);
    edge->set_from(this);
}

list<edge<nfa_node>*> nfa_node::get_terminated()
{
    return _terminated;
}

list<edge<nfa_node>*> nfa_node::get_started()
{
    return _started;
}