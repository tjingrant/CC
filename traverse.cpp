//
//  traverse.cpp
//  CC
//
//  Created by Tian Jin on 14-3-25.
//  Copyright (c) 2014年 Tian Jin. All rights reserved.
//

#include "traverse.h"
#include <list>
#include <string>
#include <map>

using namespace std;

void print_symbol(string sym)
{
    map<string, string> replace_list = {{"", "{EPSILON}"}};
    if ((replace_list.count(sym) != 0))
    {
        sym = replace_list[sym];
    }
    cout << sym << endl;
}

void traverse_nfa(edge<nfa_node>* start)
{
    print_symbol(start->get_input());
    nfa_node* node = start->get_to();
    for (auto edge : node->get_started())
    {
        traverse_nfa(edge);
    }
}