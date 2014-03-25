//
//  def.h
//  CC
//
//  Created by Tian Jin on 14-3-25.
//  Copyright (c) 2014年 Tian Jin. All rights reserved.
//

#ifndef CC_def_h
#define CC_def_h

#define CC_EPSILON ""

template<class node, class edge>
class nfa {
public:
    nfa(edge* start,node* end):_end(end), _start(start)
    {
    }
    node* _end;
    edge* _start;
};

#endif
