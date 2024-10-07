//
// Created by user on 11.05.2024.
//

#include "cl_3.h"
cl_3::cl_3(cl_base* p_head_object, string s_name) :cl_base(p_head_object, s_name) {}
int cl_3::get_class_number() {
    return 4; }
void cl_3::signal(string & message) {
    cout << endl << "Signal from " << get_absolute_path();
    message += " (class: " + to_string(get_class_number()) + ")";
}
void cl_3::handler(string message) {
    cout << endl << "Signal to " << get_absolute_path() << " Text: " << message;
}
void cl_3::handler_reader_from_app(string msg)
{
    string s_cmd;
    cin >> s_cmd;
    if (s_cmd == "C" || s_cmd == "Off")
    {
        emit_signal(SIGNAL_D(cl_3::signal_reader_to_all), s_cmd);
    }
    else if (s_cmd == "+" || s_cmd == "-" || s_cmd == "*" || s_cmd == "/" || s_cmd == "%" || s_cmd == "<<" || s_cmd == ">>")
    {
        get_head()->s_operation = s_cmd;
        get_head()->s_expression += (" " + s_cmd);

        cin >> get_head()->s_operand_2;
        get_head()->s_expression += (" " + get_head()->s_operand_2);
        emit_signal(SIGNAL_D(cl_3::signal_reader_to_all), s_cmd);

    }
    else
    {
        get_head()->s_expression = s_cmd;
        get_head()->i_result = atoi((get_head()->s_expression).c_str());
    }
}

void cl_3::signal_reader_to_all(string& msg)
{

}