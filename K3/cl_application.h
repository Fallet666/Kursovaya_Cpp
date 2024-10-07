#ifndef __CL_APPLICATION_H__
#define __CL_APPLICATION_H__
#include "cl_base.h"
#include "cl_1.h"
#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
#include "cl_5.h"
class cl_application : public cl_base
{
    public:
    cl_application(cl_base* p_head_object);
    void build_tree_objects();
    int exec_app();
    int get_class_number();
    void signal(string & message);
    void handler(const string& message);

};
#endif