//
// Created by user on 11.05.2024.
//

#ifndef CL_CANCEL_H
#define CL_CANCEL_H

#include "cl_base.h"

//cancel

class cl_2 : public cl_base{
public:
    cl_2(cl_base* p_head_object, string s_name);
    int get_class_number();
    void signal(string & message);
    void handler(string message);

    void handler_cancel_from_reader(string msg);
};



#endif //CL_CANCEL_H
