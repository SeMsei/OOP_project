
#include "../include/personaltask.h"

PersonalTask::PersonalTask(int id, std::string name, std::chrono::year_month_day date_start,
                           std::chrono::year_month_day date_finish, int employee_id)
    :Task(id, name, date_start, date_finish)
{
    this->employee_id = employee_id;
}

void PersonalTask::set_description(std::string description) {
    this->description = description;
}

std::string PersonalTask::get_description() {
    return this->description;
}

int PersonalTask::get_employee_id() {
    return this->employee_id;
}


