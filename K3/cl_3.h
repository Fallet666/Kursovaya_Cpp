//
// Created by user on 11.05.2024.
//

#ifndef CL_READER_H
#define CL_READER_H

#include "cl_base.h"

class cl_3 : public cl_base{
public:
    cl_3(cl_base* p_head_object, string s_name);
    int get_class_number();
    void signal(string & message);
    void handler(string message);

    void handler_reader_from_app(string msg);
    void signal_reader_to_all(string& msg);
};



#endif //CL_READER_H
