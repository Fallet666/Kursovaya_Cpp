#include "cl_application.h"


cl_application::cl_application(cl_base* p_head_object) : cl_base(p_head_object) {}

void cl_application::build_tree_objects()
{
	cl_base* p_sub = nullptr;

	set_name("System");

	p_sub = new cl_3(this, "Reader");
	p_sub = new cl_1(this, "Calc");
	p_sub = new cl_5(this, "Shift");
	p_sub = new cl_2(this, "Cancel");
	p_sub = new cl_4(this, "Screen");

	this->set_connect(SIGNAL_D(cl_application::signal),
		get_sub_obj("Reader"),
		HANDLER_D(cl_3::handler_reader_from_app));

	get_sub_obj("Reader")->set_connect(SIGNAL_D(cl_3::signal_reader_to_all),
		this,
		HANDLER_D(cl_application::handler));

	get_sub_obj("Reader")->set_connect(SIGNAL_D(cl_3::signal_reader_to_all),
		get_sub_obj("Cancel"),
		HANDLER_D(cl_2::handler_cancel_from_reader));

	get_sub_obj("Reader")->set_connect(SIGNAL_D(cl_3::signal_reader_to_all),
		get_sub_obj("Shift"),
		HANDLER_D(cl_5::handler_shift_from_reader));

	get_sub_obj("Reader")->set_connect(SIGNAL_D(cl_3::signal_reader_to_all),
		get_sub_obj("Calc"),
		HANDLER_D(cl_1::handler_calc_from_reader));

	get_sub_obj("Calc")->set_connect(SIGNAL_D(cl_1::signal_calc_to_screen),
		get_sub_obj("Screen"),
		HANDLER_D(cl_4::handler_screen_from_all));

}


int cl_application::exec_app()
{
	string s_msg;
	this->set_state_branch(1);
	while (s_cmd != "Off")
	{
		emit_signal(SIGNAL_D(cl_application::signal), s_msg);
	}

	return 0;
}

int cl_application::get_class_number() {
	return 1; }
void cl_application::signal(string & message) {

}

void cl_application::handler(const string& message)
{
	if (message == "Off")
	{
		s_cmd = "Off";
		s_operand_2 = "Off";
		exit(0);
	}
}