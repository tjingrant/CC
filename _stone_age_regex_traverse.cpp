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

void print_symbol(string sym)
{
    map<string, string> replace_list = {{"", "{EPSILON}"}};
    if ((replace_list.count(sym) != 0))
    {
        sym = replace_list[sym];
    }
    cout << sym << endl;
}

bool traverse_nfa(edge<nfa_node>* start, string to_parse, int index)
{
    print_symbol(start->get_input());
    nfa_node* node = start->get_to();
    
    if (node == 0)
        return true;
    
    if (index >= to_parse.length() && (start->get_input() != CC_EPSILON)) {
        if (start->get_from() == nullptr)
            return false;
        return start->get_from()->get_accpet() ? true : false;
    }
    
    
    if (start->get_input() == CC_EPSILON)
    {
        bool result = false;
        
        for (auto edge : node->get_started())
        {
            result = result || traverse_nfa(edge, to_parse, index);
        }

        if (node->get_started().size() == 0)
            return true;
        
        return result;
    }
    
    string symbol, to_match;
    symbol = start->get_input();
    to_match = char_to_string(to_parse.at(index));
    int cmp = symbol.compare(to_match);
    if (symbol == to_match)
    {
        bool result = false;
    
        for (auto edge : node->get_started())
        {
            result = result || traverse_nfa(edge, to_parse, index + 1);
        }

        if (node->get_started().size() == 0)
            return true;
        
        return result;
    }
    
    return false;
}

void traverse_debug(edge<nfa_node>* start)
{
    print_symbol(start->get_input());
    nfa_node* node = start->get_to();
    for (auto edge : node->get_started())
    {
        traverse_debug(edge);
    }

}