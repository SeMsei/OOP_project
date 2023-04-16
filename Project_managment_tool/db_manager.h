
#ifndef DB_MANAGER_H
#define DB_MANAGER_H

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


std::map<std::string, Role> role_map {  {"Boss", Role::Boss},
    {"project_manager", Role::project_manager}, {"developer", Role::developer},
    {"designer", Role::designer}, {"hr_manager", Role::hr_manager}};

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
        std::vector<Employee> ret_vec;
        std::string line;
        std::ifstream in(connection_str + "\\employees.txt");
        while (std::getline(in, line)) {
            //id; first_name; middle_name; surname; date_birth; KPI; role; salary; date_start; is_cur_working, project_id;
            //work_task_vec;
            //personal_task_vec;
            //
            //Employee tmp();
            int id, tmp_id, project_id;
            std::string first_name, middle_name, surname, date_b_str, date_s_str, role;
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

            ret_vec.push_back(Employee(tmp));
        }

        return ret_vec;
    }

    static std::vector<WorkTask> get_worktasks(std::string connection_str) {
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

            ret_vec.push_back(WorkTask(tmp));

        }

        return ret_vec;
    }

    static std::vector<PersonalTask> get_personaltasks(std::string connection_str) {
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

            ret_vec.push_back(PersonalTask(tmp));

        }

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



            ret_vec.push_back(Project(tmp));

        }

        return ret_vec;
    }
};

#endif // DB_MANAGER_H
