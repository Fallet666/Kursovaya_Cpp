//
// Created by user on 11.05.2024.
//

#ifndef CL_SHIFT_H
#define CL_SHIFT_H

#include "cl_base.h"

class cl_5 : public cl_base{
public:
    cl_5(cl_base* p_head_object, string s_name);
    int get_class_number();
    void signal(string & message);
    void handler(string message);

    void handler_shift_from_reader(string msg);
    void signal_shift_to_screen(string& msg);
};



#endif //CL_SHIFT_H
