
#include "../include/task.h"

std::string Task::get_name() {
    return this->name;
}

void Task::set_name(std::string name) {
    this->name = name;
}

bool Task::is_task_done() {
    return this->is_done;
}

void Task::complete() {
    this->is_done = 1;
}

bool Task::is_task_overdue() {
    return this->is_overdue;
}

void Task::change_overdue_status(bool new_status) {
    this->is_overdue = new_status;
}

std::chrono::year_month_day Task::get_date_start() {
    return this->date_start;
}
void Task::set_date_start(std::chrono::year_month_day date_start) {
    this->date_start = date_start;
}
std::chrono::year_month_day Task::get_date_finish() {
    return this->date_finish;
}
void Task::set_date_finish(std::chrono::year_month_day date_finish) {
    this->date_finish = date_finish;
}

int Task::get_id() {
    return this->id;
}

