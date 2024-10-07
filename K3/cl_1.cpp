#include "cl_1.h"



cl_1::cl_1(cl_base* p_head_object, string s_name) :cl_base(p_head_object, s_name) {}

int cl_1::get_class_number() {
    return 2; }
void cl_1::signal(string & message) {
    cout << endl << "Signal from " << get_absolute_path();
    message += " (class: " + to_string(get_class_number()) + ")";
}
void cl_1::handler(string message) {
    cout << endl << "Signal to " << get_absolute_path() << " Text: " << message;
}
void cl_1::signal_calc_to_screen(string& msg)
{

}

void cl_1::handler_calc_from_reader(string msg)
{
    if (msg == "+")
    {
        get_head()->i_result = get_head()->i_result + atoi((get_head()->s_operand_2).c_str());
    }
    else if (msg == "-")
    {
        get_head()->i_result = get_head()->i_result - atoi((get_head()->s_operand_2).c_str());
    }
    else if (msg == "*")
    {
        get_head()->i_result = get_head()->i_result * atoi((get_head()->s_operand_2).c_str());
    }
    else if (msg == "/")
    {
        if (atoi((get_head()->s_operand_2).c_str()) != 0)
        {
            get_head()->i_result = get_head()->i_result / atoi((get_head()->s_operand_2).c_str());
        }
        else
        {
            get_head()->s_operand_2 = "     Division by zero";
            get_head()->i_result = 0;
        }
    }
    else if (msg == "%")
    {
        get_head()->i_result = get_head()->i_result % atoi((get_head()->s_operand_2).c_str());
    }

    emit_signal(SIGNAL_D(cl_1::signal_calc_to_screen),std::to_string(get_head()->i_result) );
}