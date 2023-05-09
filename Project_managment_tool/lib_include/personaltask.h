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
    PersonalTask(const PersonalTask &other)
    {
        this->id = other.id;
        this->name = other.name;
        this->date_start = other.date_start;
        this->date_finish = other.date_finish;
        this->is_done = other.is_done;
        this->is_overdue = other.is_overdue;
        this->description = other.description;
        this->employee_id = other.employee_id;
    }
    PersonalTask(PersonalTask &&other) = default;
    ~PersonalTask() = default;

    void set_description(std::string description);
    std::string get_description();
    int get_employee_id();

    PersonalTask& operator=(PersonalTask &other) {
        this->id = other.id;
        this->description = other.description;
        this->employee_id = other.employee_id;
        this->date_finish = other.date_finish;
        this->date_start = other.date_start;
        this->name = other.name;
        this->is_done = other.is_done;
        this->is_overdue = other.is_overdue;

        return *this;
    }
    PersonalTask& operator=(PersonalTask &&other) = default;

};
#endif // PERSONALTASK_H
