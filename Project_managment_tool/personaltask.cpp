
#include "personaltask.h"

PersonalTask::PersonalTask(std::string name, std::chrono::year_month_day date_start,
                           std::chrono::year_month_day date_finish, int employee_id)
    :Task(name, date_start, date_finish)
{
    this->employee_id = employee_id;
}

void PersonalTask::set_description(std::string description) {
    this->description = description;
}

std::string PersonalTask::get_description() {
    return this->description;
}


