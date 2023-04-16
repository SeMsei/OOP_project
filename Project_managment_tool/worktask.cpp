
#include "worktask.h"
#include <iostream>

WorkTask::WorkTask(int id, std::string name, std::chrono::year_month_day date_start,
                   std::chrono::year_month_day date_finish, int new_project_id):Task(id, name, date_start, date_finish),
    project_id(new_project_id)
{
}

void WorkTask::add_employee(int new_employee_id) {
    this->employees_id.push_back(new_employee_id);
}
std::vector<int> WorkTask::get_employees_id() {
    return employees_id;
}

void WorkTask::change_project(int new_project_id) {
    project_id = new_project_id;
}

int WorkTask::get_project() {
    return project_id;
}
