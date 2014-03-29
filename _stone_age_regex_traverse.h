//
//  traverse.h
//  CC
//
//  Created by Tian Jin on 14-3-25.
//  Copyright (c) 2014年 Tian Jin. All rights reserved.
//

#ifndef __CC__traverse__
#define __CC__traverse__

#include <iostream>
#include "_stone_age_regex_edge.h"
#include "_stone_age_regex_nfa_node.h"

int traverse_nfa(edge<nfa_node>* start, string to_parse, int index);

void traverse_debug(edge<nfa_node>* start, int max = 1000, int current = 0);

#endif /* defined(__CC__traverse__) */
