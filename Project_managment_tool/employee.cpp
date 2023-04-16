
#include "employee.h"
#include <iostream>

Employee::Employee(int id, std::string first_name, std::string middle_name, std::string surname,
         std::chrono::year_month_day date_birth) :
    id(id), first_name(first_name), middle_name(middle_name), surname(surname),
    date_birth(date_birth)
{
    date_start = std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now());
}

Employee::Employee(int id, std::string first_name, std::string middle_name, std::string surname,
                   std::chrono::year_month_day date_birth, std::chrono::year_month_day date_start) :
    id(id), first_name(first_name), middle_name(middle_name), surname(surname),
    date_birth(date_birth), date_start(date_start)
{
}

void Employee::set_salary(double new_salary) {
    this->salary = new_salary;
}
double Employee::get_salary() {
    return this->salary;
}
void Employee::set_role(Role new_role) {
    this->role = new_role;
}
Role Employee::get_role() {
    return this->role;
}
void Employee::set_kpi(double new_kpi) {
    this->KPI = new_kpi;
}
double Employee::get_kpi() {
    return this->KPI;
}
void Employee::set_working_status(bool new_status) {
    this->is_cur_working = new_status;
}
bool Employee::get_working_status() {
    return this->is_cur_working;
}
std::chrono::year_month_day Employee::get_start_date() {
    return this->date_start;
}
std::chrono::year_month_day Employee::get_date_birth() {
    return this->date_birth;
}
std::string Employee::get_middle_name() {
    return this->middle_name;
}
std::string Employee::get_first_name() {
    return this->first_name;
}
std::string Employee::get_surname() {
    return this->surname;
}
std::vector<int> Employee::get_work_tasks() {
    return this->work_task_vec;
}
std::vector<int> Employee::get_personal_tasks() {
    return personal_task_vec;
}
void Employee::add_work_task(int new_task) {
    this->work_task_vec.push_back(new_task);

}
void Employee::add_personal_task(int new_task) {
    this->personal_task_vec.push_back(new_task);
}

int Employee::get_id() {
    return this->id;
}

