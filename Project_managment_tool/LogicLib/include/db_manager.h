
#ifndef DB_MANAGER_H
#define DB_MANAGER_H

#pragma once

#include <string>
#include <sys/stat.h>
#include <fstream>
#include <sstream>
#include <map>
#include "employee.h"
#include "personaltask.h"
#include "role.h"
#include <iostream>
#include "worktask.h"
#include "personaltask.h"
#include "project.h"

class Employee;
class WorkTask;
class PersonalTask;
class Project;






class db_manager
{
private:
    //static std::string connection_str;


public:
    static bool connect(std::string cnct_str) {
        struct stat sb;

        if (!stat(cnct_str.c_str(), &sb))
            //connection_str = cnct_str;
        {}
        else
            return false;

        return true;
    }

    static std::vector<Employee> get_employees(std::string connection_str) {
        std::map<std::string, Role> role_map {  {"Boss", Role::Boss},
                                             {"project_manager", Role::project_manager}, {"developer", Role::developer},
                                             {"designer", Role::designer}, {"hr_manager", Role::hr_manager}};

        std::vector<Employee> ret_vec;
        std::string line;
        std::ifstream in(connection_str + "\\employees.txt");
        while (std::getline(in, line)) {
            //id; first_name; middle_name; surname; date_birth; KPI; role; salary; date_start; is_cur_working, project_id;
            //login password
            //work_task_vec;
            //personal_task_vec;
            //
            //Employee tmp();
            int id, tmp_id, project_id;
            std::string first_name, middle_name, surname, date_b_str, date_s_str, role, login, password;
            double KPI, salary;
            bool is_cur_working;
            std::vector<int> work_task_vec;
            std::vector<int> personal_task_vec;
            std::stringstream cont;
            std::chrono::sys_days date_b, date_s;
            std::chrono::year_month_day date_birth, date_start;

            cont << line;
            cont >> id >> first_name >> middle_name >> surname >> date_b_str >> KPI >> role >>
                salary >> date_s_str >> is_cur_working >> project_id;

            std::istringstream iss_b{date_b_str}, iss_s{date_s_str};

            std::chrono::from_stream(iss_b, "%F", date_b);
            std::chrono::from_stream(iss_s, "%F", date_s);
            date_birth = date_b;
            date_start = date_s;


            Employee tmp(id, first_name, middle_name, surname, date_birth, date_start);
            tmp.set_kpi(KPI);
            tmp.set_role(role_map[role]);
            tmp.set_salary(salary);
            tmp.set_working_status(is_cur_working);

            cont.clear();
            std::getline(in, line);
            cont << line;

            cont >> login >> password;

            cont.clear();
            std::getline(in, line);
            cont << line;

            while (cont >> tmp_id) {
                work_task_vec.push_back(tmp_id);
                tmp.add_work_task(tmp_id);
            }

            cont.clear();
            std::getline(in, line);
            cont << line;

            while (cont >> tmp_id) {
                personal_task_vec.push_back(tmp_id);
                tmp.add_personal_task(tmp_id);
            }

            tmp.set_project_id(project_id);

            tmp.set_login(login);
            tmp.set_password(password);

            ret_vec.push_back(tmp);
        }

        in.close();

        return ret_vec;
    }

    static std::vector<WorkTask> get_work_tasks(std::string connection_str) {
        std::vector<WorkTask> ret_vec;
        std::ifstream in(connection_str + "worktasks.txt");
        std::string line;

        while (std::getline(in, line)) {
            //id, name, is_done, date_start, date_finish, is_overdue, project_id
            //employees_id

            int id, tmp_id, project_id;
            bool is_done, is_overdue;
            std::string name, date_s_str, date_f_str;
            std::stringstream cont;
            std::chrono::year_month_day date_start, date_finish;

            cont << line;
            cont >> id >> name >> is_done >> date_s_str >> date_f_str >> is_overdue >> project_id;

            std::istringstream iss_s{date_s_str}, iss_f{date_f_str};
            std::chrono::from_stream(iss_s, "%F", date_start);
            std::chrono::from_stream(iss_f, "%F", date_finish);

            WorkTask tmp(id, name, date_start, date_finish, project_id);

            if (is_done) {
                tmp.complete();
            }

            tmp.change_overdue_status(is_overdue);

            std::getline(in, line);
            cont.clear();
            cont << line;

            while (cont >> tmp_id) {
                tmp.add_employee(tmp_id);
            }

            ret_vec.push_back(tmp);

        }

        in.close();

        return ret_vec;
    }

    static std::vector<PersonalTask> get_personal_tasks(std::string connection_str) {
        std::vector<PersonalTask> ret_vec;
        std::ifstream in(connection_str + "personaltasks.txt");
        std::string line;

        while (std::getline(in, line)) {
            //id, name, is_done, date_start, date_finish, is_overdue, employee_id
            //description

            int id, employee_id;
            bool is_done, is_overdue;
            std::string name, date_s_str, date_f_str;
            std::stringstream cont;
            std::chrono::year_month_day date_start, date_finish;

            cont << line;
            cont >> id >> name >> is_done >> date_s_str >> date_f_str >> is_overdue >> employee_id;

            std::istringstream iss_s{date_s_str}, iss_f{date_f_str};
            std::chrono::from_stream(iss_s, "%F", date_start);
            std::chrono::from_stream(iss_f, "%F", date_finish);

            PersonalTask tmp(id, name, date_start, date_finish, employee_id);

            if (is_done) {
                tmp.complete();
            }

            tmp.change_overdue_status(is_overdue);

            std::getline(in, line);

            tmp.set_description(line);

            ret_vec.push_back(tmp);

        }

        in.close();

        return ret_vec;
    }

    static std::vector<Project> get_projects(std::string connection_str) {
        std::vector<Project> ret_vec;
        std::ifstream in(connection_str + "projects.txt");
        std::string line;

        while (std::getline(in, line)) {
            //id, name, date_start, date_finish, task_count, dont_task_count, is_done,
            //employee_vec
            //task_vec
            int id, tmp_id, task_count, done_task_count;
            std::string name;
            bool is_done;
            std::chrono::year_month_day date_start, date_finish;
            std::string date_start_str, date_finish_str;
            std::stringstream cont;

            cont << line;
            cont >> id >> name >> date_start_str >> date_finish_str >> task_count >> done_task_count >> is_done;

            std::istringstream iss_s{date_start_str}, iss_f{date_finish_str};
            std::chrono::from_stream(iss_s, "%F", date_start);
            std::chrono::from_stream(iss_f, "%F", date_finish);

            Project tmp(id, name, date_start, date_finish);

            for (int i = 0; i < done_task_count; i++)
                tmp.complete_task();

            if (is_done)
                tmp.complete();

            cont.clear();
            std::getline(in, line);
            cont << line;

            while (cont >> tmp_id)
                tmp.add_employee(tmp_id);

            cont.clear();
            std::getline(in, line);
            cont << line;

            while (cont >> tmp_id)
                tmp.add_task(tmp_id);



            ret_vec.push_back(tmp);

        }

        in.close();

        return ret_vec;
    }

    static void update_employees(std::vector<Employee> &vec, std::string cnct_str) {
        //id; first_name; middle_name; surname; date_birth; KPI; role; salary; date_start; is_cur_working, project_id;
        //login password
        //work_task_vec;
        //personal_task_vec;

        std::map<Role,std::string> reverse_role_map {  {Role::Boss, "Boss"},
                                                     {Role::project_manager, "project_manager"}, {Role::developer, "developer"},
                                                     {Role::designer, "designer"}, {Role::hr_manager, "hr_manager"}};

        //
        std::ofstream out(cnct_str + "employees.txt", std::ofstream::out | std::ofstream::trunc);

        for (auto empl:vec) {
            std::ostringstream oss_b, oss_s;

            oss_b << empl.get_date_birth();
            oss_s << empl.get_start_date();

            std::string work_tasks_line;
            std::string personal_tasks_line;
            std::string log_pass_line = empl.get_login() + ' ' + empl.get_password();
            std::string info_line = std::to_string(empl.get_id()) + ' ' + empl.get_first_name() + ' ' +
                    empl.get_middle_name() + ' ' + empl.get_surname() + ' ' + oss_b.str() + ' ' +
                    std::to_string(empl.get_kpi()) + ' ' + reverse_role_map[empl.get_role()] + ' ' +
                    std::to_string(empl.get_salary()) + ' ' + oss_s.str() + ' ' +
                    std::to_string(empl.get_working_status()) + ' ' + std::to_string(empl.get_project_id());

            for (auto x:empl.get_work_tasks())
                work_tasks_line += std::to_string(x) + ' ';

            if (work_tasks_line.size() > 0)
                work_tasks_line.erase(work_tasks_line.end() - 1);

            for (auto x:empl.get_personal_tasks())
                personal_tasks_line += std::to_string(x) + ' ';

            if (personal_tasks_line.size() > 0)
                personal_tasks_line.erase(personal_tasks_line.end() - 1);

            out << info_line + '\n';
            out << log_pass_line + '\n';
            out << work_tasks_line + '\n';
            out << personal_tasks_line;

            if (empl.get_id() != vec[vec.size() - 1].get_id())
                out << '\n';

        }

        out.close();
    }

    static void update_work_tasks(std::vector<WorkTask> &vec, std::string cnct_str) {
        //id, name, is_done, date_start, date_finish, is_overdue, project_id
        //employees_id

        std::ofstream out(cnct_str + "worktasks.txt", std::ofstream::out | std::ofstream::trunc);

        for (auto task:vec) {
            std::ostringstream oss_s, oss_f;
            std::string employees_line;

            oss_s << task.get_date_start();
            oss_f << task.get_date_finish();

            std::string info_line = std::to_string(task.get_id()) + ' ' + task.get_name() + ' ' +
                                    std::to_string(task.is_task_done()) + ' ' + oss_s.str() + ' ' + oss_f.str() + ' ' +
                                    std::to_string(task.is_task_overdue()) + ' ' + std::to_string(task.get_project());

            for (auto x:task.get_employees_id())
                employees_line += std::to_string(x) + ' ';

            if (employees_line.size() > 0)
                employees_line.erase(employees_line.end() - 1);

            out << info_line << '\n' << employees_line;

            if (task.get_id() != vec.back().get_id())
                out << '\n';
        }

        out.close();
    }

    static void update_personal_tasks(std::vector<PersonalTask> &vec, std::string cnct_str) {
        //id, name, is_done, date_start, date_finish, is_overdue, employee_id
        //description

        std::ofstream out(cnct_str + "personaltasks.txt", std::ofstream::out | std::ofstream::trunc);

        for (auto task:vec) {
            std::ostringstream oss_s, oss_f;
            oss_s << task.get_date_start();
            oss_f << task.get_date_finish();

            std::string info_line = std::to_string(task.get_id()) + ' ' + task.get_name() + ' ' +
                                    std::to_string(task.is_task_done()) + ' ' + oss_s.str() + ' ' + oss_f.str() + ' ' +
                                    std::to_string(task.is_task_overdue()) + ' ' + std::to_string(task.get_employee_id());

            out << info_line << '\n' << task.get_description();

            if (task.get_id() != vec.back().get_id())
                out << '\n';
        }
    }

    static void update_projects(std::vector<Project> &vec, std::string cnct_str) {
        //id, name, date_start, date_finish, task_count, dont_task_count, is_done,
        //employee_vec
        //task_vec

        std::ofstream out(cnct_str + "projects.txt", std::ofstream::out | std::ofstream::trunc);

        for (auto project:vec) {
            std::ostringstream oss_s, oss_f;
            oss_s << project.get_date_start();
            oss_f << project.get_date_finish();

            std::string employee_line, task_line;
            std::string info_line = std::to_string(project.get_id()) + ' ' + project.get_name() + ' ' +
                                    oss_s.str() + ' ' + oss_f.str() + ' ' + std::to_string(project.get_task_count()) + ' ' +
                                    std::to_string(project.get_done_task_count()) + ' ' + std::to_string(project.is_completed());

            for (auto x:project.get_employees_id())
                employee_line += std::to_string(x) + ' ';

            if (employee_line.size() > 0)
                employee_line.erase(employee_line.end() - 1);

            for (auto x:project.get_tasks())
                task_line += std::to_string(x) + ' ';

            if (task_line.size() > 0)
                task_line.erase(task_line.end() - 1);

            out << info_line << '\n';
            out << employee_line << '\n';
            out << task_line;

            if (project.get_id() != vec.back().get_id())
                out << '\n';
        }

        out.close();
    }
};

#endif // DB_MANAGER_H
