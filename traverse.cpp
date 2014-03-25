//
//  traverse.cpp
//  CC
//
//  Created by Tian Jin on 14-3-25.
//  Copyright (c) 2014年 Tian Jin. All rights reserved.
//

#include "traverse.h"

void traverse_nfa(edge<nfa_node>* start)
{
    cout << "executed\n";
    nfa_node* node = start->get_to();
    for (auto edge : node->get_started())
    {
        traverse_nfa(edge);
    }
}