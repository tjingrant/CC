//
//  main.cpp
//  CC
//
//  Created by Tian Jin on 14-3-24.
//  Copyright (c) 2014年 Tian Jin. All rights reserved.
//

#include <iostream>
#include <list>

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
private:
    T* _from;
    T* _to;
    string _input;
};

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

void traverse_nfa(edge<nfa_node>* start)
{
    cout << "executed\n";
    nfa_node* node = start->get_to();
    for (auto edge : node->get_started())
    {
        traverse_nfa(edge);
    }
}

int main(int argc, const char * argv[])
{
//    //for type a
    nfa_node* a_node = new nfa_node(false, "");
    edge<nfa_node>* a_edge = new edge<nfa_node>(0, a_node, "a");
    a_node->push_terminated(a_edge);
    nfa_node* e_node = new nfa_node(false, "");
    edge<nfa_node>* e_edge = new edge<nfa_node>(0, e_node, "e");
    a_node->push_started(e_edge);
    e_node->push_terminated(e_edge);
    traverse_nfa(a_edge);
    
    std::cout << "Hello, World!\n";
    return 0;
}

