
#include "project.h"


Project::Project(int id, std::string project_name, std::chrono::year_month_day date_start,
                 std::chrono::year_month_day date_finish) :
    id(id), project_name(project_name), date_start(date_start), date_finish(date_finish)
{}

int Project::get_id() {
    return this->id;
}

void Project::set_name(std::string new_name) {
    project_name = new_name;
}
std::string Project::get_name() {
    return project_name;
}
std::vector<int> Project::get_tasks() {
    return tasks_vec;
}

std::chrono::year_month_day Project::get_date_start() {
    return date_start;
}

std::chrono::year_month_day Project::get_date_finish() {
    return date_finish;
}

void Project::set_date_finish(std::chrono::year_month_day new_date_finish) {
    date_finish = new_date_finish;
}

void Project::add_task(int task) {
    tasks_vec.push_back(task);
    task_count++;
}

void Project::remove_task(int num) {
    //auto tmp = std::move(tasks_vec[num]);
    tasks_vec.erase(tasks_vec.begin() + num);
    task_count--;
}

void Project::complete_task() {
    done_task_count++;
    //tasks_vec[num].complete();
}

int Project::get_task_count() {
    return task_count;
}

int Project::get_done_task_count() {
    return done_task_count;
}

bool Project::is_completed() {
    return is_done;
}

void Project::complete() {
    is_done = 1;
}

void Project::add_employee(int empl) {
    employee_vec.push_back(empl);
}

std::vector<int> Project::get_employees_id() {
    return this->employee_vec;
}

