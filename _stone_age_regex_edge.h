//
//  edge.h
//  CC
//
//  Created by Tian Jin on 14-3-25.
//  Copyright (c) 2014年 Tian Jin. All rights reserved.
//

#ifndef __CC__edge__
#define __CC__edge__

#include <iostream>
#include <string>

using namespace std;

template <class T>
class edge
{
public:
    edge(T* from, T* to, string input): _from(from), _to(to), _input(input)
    {
        
    }
    
    void set_to(T* to)
    {
        _to = to;
    }
    
    void set_from(T* from)
    {
        _from = from;
    }
    
    T* get_to()
    {
        return _to;
    }
    
    T* get_from()
    {
        return _from;
    }
    
    string get_input()
    {
        return _input;
    }
private:
    T* _from;
    T* _to;
    string _input;
};

#endif /* defined(__CC__edge__) */
