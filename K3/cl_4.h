//
// Created by user on 11.05.2024.
//

#ifndef CL_SCREEN_H
#define CL_SCREEN_H

#include "cl_base.h"

class cl_4 : public cl_base {
public:
    cl_4(cl_base* p_head_object, string s_name);
    int get_class_number();
    void signal(string & message);
    void handler(string message);

    void handler_screen_from_all(string msg);
    void toBinary(unsigned int i);
};



#endif //CL_SCREEN_H
