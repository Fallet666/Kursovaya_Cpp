#ifndef __CL_8_H__
#define __CL_8_H__
#include "cl_base.h"

//calc

class cl_1 : public cl_base
{
public:
    cl_1(cl_base* p_head_object, string s_name);
    int get_class_number();
    void signal(string & message);
    void handler(string message);

    void signal_calc_to_screen(string& msg);
    void handler_calc_from_reader(string msg);
};

#endif