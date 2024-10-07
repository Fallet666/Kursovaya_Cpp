//
// Created by user on 11.05.2024.
//

#include "cl_5.h"

cl_5::cl_5(cl_base* p_head_object, string s_name) :cl_base(p_head_object, s_name) {}
int cl_5::get_class_number() {
    return 6; }
void cl_5::signal(string & message) {
    cout << endl << "Signal from " << get_absolute_path();
    message += " (class: " + to_string(get_class_number()) + ")";
}
void cl_5::handler(string message) {
    cout << endl << "Signal to " << get_absolute_path() << " Text: " << message;
}

void cl_5::handler_shift_from_reader(string msg)
{
    if (msg == "<<")
    {
        get_head()->i_result = get_head()->i_result << atoi((get_head()->s_operand_2).c_str());
    }
    else if (msg == ">>")
    {
        get_head()->i_result = get_head()->i_result >> atoi((get_head()->s_operand_2).c_str());
    }

    emit_signal(SIGNAL_D(cl_5::signal_shift_to_screen),
        to_string(get_head()->i_result));
}

void cl_5::signal_shift_to_screen(string& msg)
{

}