//
// Created by user on 11.05.2024.
//

#include "cl_2.h"

cl_2::cl_2(cl_base* p_head_object, string s_name) :cl_base(p_head_object, s_name) {}
int cl_2::get_class_number() {
    return 3; }
void cl_2::signal(string & message) {
    cout << endl << "Signal from " << get_absolute_path();
    message += " (class: " + to_string(get_class_number()) + ")";
}
void cl_2::handler(string message) {
    cout << endl << "Signal to " << get_absolute_path() << " Text: " << message;
}
void cl_2::handler_cancel_from_reader(string msg)
{
    if (msg == "C")
    {
        get_head()->s_expression = "0";
        get_head()->s_operation = "";
        get_head()->s_operand_2 = "C";
        get_head()->i_result = 0;
    }
}