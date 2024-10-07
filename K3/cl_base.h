#ifndef __CL_BASE__H
#define __CL_BASE__H
#define SIGNAL_D(signal_f)(TYPE_SIGNAL)(&signal_f)
#define HANDLER_D(handler_f)(TYPE_HANDLER)(&handler_f)
#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "string"
#include <iomanip>
#include <sstream>
using namespace std;
class cl_base;
typedef void(cl_base::*TYPE_SIGNAL)(string &);
typedef void(cl_base::*TYPE_HANDLER)(string);

class cl_base{
    struct connect {
        TYPE_SIGNAL signal_ptr;
        cl_base* target_ptr;
        TYPE_HANDLER handler_ptr;
    };
    string s_name;
    cl_base* p_head_object;
    vector<cl_base*> p_sub_objects;
    int p_ready = 0;
    vector<connect*> connects;
public:
    cl_base(cl_base* head, string name = "Base Object");
    bool set_name(string new_name);
    string get_name();
    cl_base* get_head();
    void print_tree();
    cl_base* get_sub_obj(string name);
    ~cl_base();
    cl_base* search_by_name(string name);
    cl_base* search_from_root(string name);
    void set_ready(int s_new_ready);
    void print_ready();
    bool head_change(cl_base* new_head);
    void remove_sub(string sub_name);
    cl_base* cladmen(string coordinaty);
    void set_connect(TYPE_SIGNAL signal_ptr, cl_base* target_ptr, TYPE_HANDLER handler_ptr);
    void remove_connect(TYPE_SIGNAL signal_ptr, cl_base* target_ptr, TYPE_HANDLER handler_ptr);
    void emit_signal(TYPE_SIGNAL signal_ptr, string command);
    string get_absolute_path();
    virtual int get_class_number();
    void set_state_branch(int new_state);

    void turn_on_subtree();
    string s_cmd, s_expression, s_operation, s_operand_2;
    int i_result = 0, f = 0;
};

#endif
