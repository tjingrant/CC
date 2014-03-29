//
//  traverse.cpp
//  CC
//
//  Created by Tian Jin on 14-3-25.
//  Copyright (c) 2014年 Tian Jin. All rights reserved.
//

#include "_stone_age_regex_traverse.h"
#include "_stone_age_regex_def.h"
#include <list>
#include <string>
#include <map>
#include <sstream>

using namespace std;

string print_symbol(string sym)
{
    map<string, string> replace_list = {{"", "{EPSILON}"}};
    if ((replace_list.count(sym) != 0))
    {
        sym = replace_list[sym];
    }
    return sym;
}

int traverse_nfa(edge<nfa_node>* start, string to_parse, int index)
{
    CC_DEBUG_OUT("The nfa just went by: " + start->get_input());
    CC_DEBUG_OUT("CURRENT INDEX:" << index);
    //next node to examine
    nfa_node* node = start->get_to();
    
    //running to the end of the nfa
    if (node == 0)
        return index;
    
    //reaching the end of to_parse while not the end of the nfa
    if (index >= to_parse.length() && (start->get_input() != CC_EPSILON)) {
        
        //making sure it has a source because the source will be tested for accpet states
        if (start->get_from() == nullptr)
            return -1;
        return start->get_from()->get_accpet() ? index : -1;
        
    }
    
    
    if (start->get_input() == CC_EPSILON)
    {
        int result = -1;
        
        for (auto edge : node->get_started())
        {
            result = std::max(result, traverse_nfa(edge, to_parse, index));
        }

        if (node->get_started().size() == 0)
            return index - 1; //To Check
        
        return result; //To Check
    }
    
    //todo: why this doesn't work????
    string symbol, to_match;
    symbol = start->get_input();
    to_match = char_to_string(to_parse.at(index));
    int cmp = symbol.compare(to_match);
    if (symbol == to_match)
    {
        int result = -1;
        
        for (auto edge : node->get_started())
        {
            result = std::max(result, traverse_nfa(edge, to_parse, index + 1));
        }
        
        if (node->get_started().size() == 0)
            return index;
        
        return result;
    }
    
    return -1;
}

void traverse_debug(edge<nfa_node>* start, int max, int current)
{
    if (current >= max) return;
    CC_DEBUG_OUT(start->get_input());
    nfa_node* node = start->get_to();
    for (auto edge : node->get_started())
    {
        traverse_debug(edge, max, current + 1);
    }

}