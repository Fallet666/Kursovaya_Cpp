#include "cl_base.h"

#include <stack>
using namespace std;
cl_base::cl_base(cl_base* head, string name){
	this->s_name = name;
	this->p_head_object = head;
	if(head != nullptr){
		head->p_sub_objects.push_back(this);
	}
}
cl_base::~cl_base(){
	for(auto &i: p_sub_objects)
		delete i;
}
bool cl_base::set_name(string new_name){
	if (get_head() != nullptr){
		for(auto &i: get_head()->p_sub_objects){
			if(i->get_name() == s_name)
				return false;
		}
	}
	s_name = new_name;
	return true;
}
void cl_base::print_tree(){
	string delay = "";
	cl_base* buf = this;
	while(buf->p_head_object != nullptr){
		delay+="    ";
		buf = buf->p_head_object;
	}
	cout<<endl<<delay<<get_name();
	for (auto p_sub: p_sub_objects)
		p_sub->print_tree();
}
string cl_base::get_name(){
	return s_name;
}
cl_base* cl_base::get_head(){
	return p_head_object;
}
cl_base* cl_base::get_sub_obj(string name){
	for(auto &i: p_sub_objects){
		if(i->s_name == name)
			return i;
	}
	return nullptr;
}
void cl_base::print_ready(){
	string delay = "";
	cl_base* buf = this;
	while(buf->p_head_object != nullptr){
		delay+="    ";
		buf = buf->p_head_object;
	}
	cout<<endl<<delay;
	if(p_ready!=0){
			cout<<get_name()<<" is ready";}
		else{
			cout<<get_name()<<" is not ready";}
	for(auto p_sub: p_sub_objects)
		p_sub->print_ready();
}

cl_base* cl_base::search_by_name(string name){
	if(name == s_name)
		return this;
	cl_base* p_result = nullptr;
	cl_base* result = nullptr;
	bool found = false;
	for(auto & p_sub_object: p_sub_objects){
		p_result  = p_sub_object->search_by_name(name);
		if(p_result == (cl_base*) -1) return (cl_base*) -1;
		if(p_result != nullptr){
			if(found){return (cl_base*) -1;}
			found = true;
			result = p_result;
		}
	}
	return result;
}

void cl_base::set_ready(int s_new_ready){
	if(s_new_ready!=0){
		if(p_head_object == nullptr || p_head_object->p_ready != 0)
			p_ready = s_new_ready;
	} else {
		p_ready = s_new_ready;
		for(auto & p_sub_object: p_sub_objects)
			p_sub_object->set_ready(s_new_ready);
	}
}

cl_base* cl_base::search_from_root(string name){
	if(p_head_object!=nullptr){
		return p_head_object->search_from_root(name);
	}
	cl_base* answ = search_by_name(name);
	if(answ==(cl_base*) -1)
		return nullptr;
	return search_by_name(name);
}

bool cl_base::head_change(cl_base *new_head){
	if(new_head != nullptr){
		cl_base* tmp = new_head;
		while(tmp != nullptr){
			tmp = tmp->p_head_object;
			if(tmp == this)
				return false;
		}
		if(new_head->get_sub_obj(s_name) == nullptr && p_head_object != nullptr){
			p_head_object->p_sub_objects.erase(find(p_head_object->p_sub_objects.begin(),p_head_object->p_sub_objects.end(), this));
			new_head->p_sub_objects.emplace_back(this);
			p_head_object = new_head;
			return true;
		}
	}
	return false;
}

void cl_base::remove_sub(string name)
{
	cl_base* subordinate_obj = get_sub_obj(name);
	if (subordinate_obj != nullptr)
	{
		p_sub_objects.erase(find(p_sub_objects.begin(), p_sub_objects.end(), subordinate_obj));
		delete subordinate_obj;
	}
}


cl_base* cl_base::cladmen(string coordinaty){
	//посмеялся и хватит, пусть будет нормальное название
	string s = coordinaty;
	cl_base* answ = nullptr;
	if(s=="/"){
		if(p_head_object==nullptr)
			return this;
		return p_head_object->cladmen(s);
	}
	if(s.substr(0,2)=="//"){
		answ = search_from_root(s.substr(2));
		if(answ == (cl_base*) -1)
			return nullptr;
		return answ;
	}

	if(s == ".")
		return this;
	if(s.substr(0,1)=="."){
		answ = search_by_name(s.substr(1));
		if(answ == (cl_base*) -1)
			return nullptr;
		return answ;
	}
	if(s[0]=='/'){
		if(p_head_object==nullptr)
			return cladmen(s.substr(1));
		return p_head_object->cladmen(s);
	}
	if(s.find('/') == s.npos){
		if(this==(cl_base*) -1)
			return nullptr;
		return get_sub_obj(s);
	}
	return get_sub_obj(s.substr(0,s.find('/')))->cladmen(s.substr(s.find('/')+1));
}

void cl_base::set_connect(TYPE_SIGNAL signal_ptr, cl_base* target_ptr, TYPE_HANDLER handler_ptr) {
	for (auto & connect : connects) {
		if (connect->signal_ptr == signal_ptr && connect->target_ptr
		== target_ptr && connect->handler_ptr == handler_ptr) {
			return;
		}
	}
	connect *new_connect = new connect();
	new_connect->signal_ptr = signal_ptr;
	new_connect->target_ptr = target_ptr;
	new_connect->handler_ptr = handler_ptr;
	connects.push_back(new_connect);
}
void cl_base::remove_connect(TYPE_SIGNAL signal_ptr, cl_base* target_ptr, TYPE_HANDLER handler_ptr) {
	for (int i = 0; i < connects.size(); ++i) {
		if (connects[i]->signal_ptr == signal_ptr && connects[i]->target_ptr == target_ptr && connects[i]->handler_ptr == handler_ptr) {
			delete connects[i];
			connects.erase(connects.begin() + i);
			return; }
	}
}
void cl_base::emit_signal(TYPE_SIGNAL signal_ptr, string command) {
	if (this->p_ready == 0) {
		return; }
	(this->*signal_ptr)(command);
	for (auto & connect : connects) {
		if (connect->signal_ptr == signal_ptr) {
			TYPE_HANDLER handler_ptr = connect->handler_ptr;
			cl_base* target_ptr = connect->target_ptr;
			if (target_ptr->p_ready != 0) {
				(target_ptr->*handler_ptr)(command);
			}
		}
	}
}
string cl_base::get_absolute_path() {
	string result;
	stack<string> st;
	cl_base* root_ptr = this;
	while (root_ptr->get_head() != nullptr) {
		st.push(root_ptr->get_name());
		root_ptr = root_ptr->get_head();
	}
	while (!st.empty()) {
		result += '/' + st.top();
		st.pop();
	}
	if (result.empty()) {
		return "/"; }
	return result;
}
int cl_base::get_class_number() {
	return 0;
}
void cl_base::set_state_branch(int new_state) {
	if (get_head() != nullptr && get_head()->p_ready == 0) {
		return;
	}
	set_ready(new_state);
	for (auto sub: p_sub_objects) {
		sub->set_state_branch(new_state);
	}
}

void cl_base::turn_on_subtree()
{
	p_ready = 1;
	for (auto p_sub_obj : p_sub_objects)
	{
		p_sub_obj->turn_on_subtree();
	}
}
