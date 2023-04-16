#ifndef PERSONALTASK_H
#define PERSONALTASK_H
#pragma once

#include "task.h"

#pragma once


class PersonalTask : public Task
{
private:
    std::string description;
    int employee_id;

public:
    PersonalTask() = default;
    PersonalTask(int id, std::string name, std::chrono::year_month_day date_start,
                 std::chrono::year_month_day date_finish, int employee_id);
    PersonalTask(PersonalTask &other) = default;
    PersonalTask(PersonalTask &&other) = default;
    ~PersonalTask() = default;

    void set_description(std::string description);
    std::string get_description();
    int get_employee_id();

    PersonalTask& operator=(PersonalTask &other) = default;
    PersonalTask& operator=(PersonalTask &&other) = default;

};
#endif // PERSONALTASK_H
