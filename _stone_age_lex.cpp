//
//  lex.cpp
//  CC
//
//  Created by Tian Jin on 14-3-25.
//  Copyright (c) 2014年 Tian Jin. All rights reserved.
//

#include "_stone_age_lex.h"

lex_stack* analyze(string s)
{
    lex_stack* stack = new lex_stack();
    
    list<lex_handlr> handlr_list = {
        [] (char c, lex_stack* stack, int pos) -> LEX_TOKEN {
            CHECK_AND_RETURN('(', TOKEN_LPAREN);
        },
        [] (char c, lex_stack* stack, int pos) -> LEX_TOKEN {
            CHECK_AND_RETURN(')', TOKEN_RPAREN);
        },
        [] (char c, lex_stack* stack, int pos) -> LEX_TOKEN {
            CHECK_AND_RETURN('?', TOKEN_QUESTION_MARK);
        },
        [] (char c, lex_stack* stack, int pos) -> LEX_TOKEN {
            CHECK_AND_RETURN('*', TOKEN_ASTERISK);
        },
        [] (char c, lex_stack* stack, int pos) -> LEX_TOKEN {
            CHECK_AND_RETURN('|', TOKEN_PIPE);
        },
        [] (char c, lex_stack* stack, int pos) -> LEX_TOKEN {
            CHECK_AND_RETURN('[', TOKEN_LSQUARE);
        },
        [] (char c, lex_stack* stack, int pos) -> LEX_TOKEN {
            CHECK_AND_RETURN(']', TOKEN_RSQUARE);
        },
        [] (char c, lex_stack* stack, int pos) -> LEX_TOKEN {
            CHECK_AND_RETURN('-', TOKEN_CONNECT);
        },
        [] (char c, lex_stack* stack, int pos) -> LEX_TOKEN {
            CHECK_AND_RETURN('+', TOKEN_PLUS);
        },
        [] (char c, lex_stack* stack, int pos) -> LEX_TOKEN {
            stack->push_back(lex_parcel(LEX_TOKEN::TOKEN_LITERAL, c));
            return LEX_TOKEN::TOKEN_LITERAL;
        }
    };
    
    int pos = 0;
    std::list<lex_handlr>::const_iterator iterator;
    for(char& c : s) {
        for (iterator = handlr_list.begin(); iterator != handlr_list.end(); ++iterator) {
            LEX_TOKEN token = (*iterator)(c, stack, pos);
            if (token != LEX_TOKEN::TOKEN_NOT_FOUND) break;
        }
        pos++;
    }
    return stack;
}
