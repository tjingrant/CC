//
//  nfa_node.h
//  CC
//
//  Created by Tian Jin on 14-3-25.
//  Copyright (c) 2014年 Tian Jin. All rights reserved.
//

#ifndef __CC__nfa_node__
#define __CC__nfa_node__

#include <iostream>
#include "edge.h"
#include <list>

using namespace std;

class nfa_node
{
public:
    nfa_node(bool accept, string symbol, list<edge<nfa_node>*> terminated, list<edge<nfa_node>*> started): _accept(accept), _symbol(symbol), _terminated(terminated), _started(started)
    {
        
    }
    
    nfa_node(bool accept, string symbol): _accept(accept), _symbol(symbol)
    {
        _terminated = list<edge<nfa_node>*>();
        _started = list<edge<nfa_node>*>();
    }
    
    void push_terminated(edge<nfa_node>* edge) {
        _terminated.push_back(edge);
        edge->set_to(this);
    }
    
    void push_started(edge<nfa_node>* edge) {
        _started.push_back(edge);
        edge->set_from(this);
    }
    
    list<edge<nfa_node>*> get_terminated()
    {
        return _terminated;
    }
    
    list<edge<nfa_node>*> get_started()
    {
        return _started;
    }
private:
    bool _accept;
    string _symbol;
    list<edge<nfa_node>*> _terminated;
    list<edge<nfa_node>*> _started;
    
};

#endif /* defined(__CC__nfa_node__) */
