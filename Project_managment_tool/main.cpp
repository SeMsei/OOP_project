
#include <iostream>
#include "lib_include/jsonserializer.hpp"
#include <fstream>
#include "lib_include/db_manager.h"
#include "lib_include/role_class.h"

std::vector<PersonalTask> tuple_to_personal_task(std::vector<std::tuple<int, std::string, bool,
                                                                        std::chrono::year_month_day, std::chrono::year_month_day,
                                                                        bool, std::string, int>> vec_in) {
    std::vector<PersonalTask> out_vec;

    for (auto x:vec_in) {
        PersonalTask tmp(std::get<0>(x), std::get<1>(x), std::get<3>(x), std::get<4>(x), std::get<7>(x));
        tmp.change_overdue_status(std::get<5>(x));
        tmp.set_description(std::get<6>(x));
        if (std::get<2>(x)) {
            tmp.complete();
        }

        out_vec.push_back(tmp);
    }

    return out_vec;
}

std::vector<std::tuple<int, std::string, bool,
                       std::chrono::year_month_day, std::chrono::year_month_day,
                       bool, std::string, int>> personal_task_to_tuple(std::vector<PersonalTask> in_vec) {
    std::vector<std::tuple<int, std::string, bool,
                           std::chrono::year_month_day, std::chrono::year_month_day,
                           bool, std::string, int>> out_vec;

    for (auto x:in_vec) {
        auto tmp = std::make_tuple(x.get_id(), x.get_name(), x.is_task_done(), x.get_date_start(),
                                   x.get_date_finish(), x.is_task_overdue(), x.get_description(),
                                   x.get_employee_id());

        out_vec.push_back(tmp);
    }

    return out_vec;
}

std::vector<WorkTask> tuple_to_work_task(std::vector<std::tuple<int, std::string, bool, std::chrono::year_month_day,
                                                                std::chrono::year_month_day, bool, std::vector<int>, int>> in_vec) {
    std::vector<WorkTask> out_vec;

    for (auto x:in_vec) {
        WorkTask tmp(std::get<0>(x), std::get<1>(x), std::get<3>(x), std::get<4>(x), std::get<7>(x));
        tmp.change_overdue_status(std::get<5>(x));
        if (std::get<2>(x)) {
            tmp.complete();
        }

        for (auto x:std::get<6>(x)) {
            tmp.add_employee(x);
        }

        out_vec.push_back(tmp);
    }

    return out_vec;
}

std::vector<std::tuple<int, std::string, bool, std::chrono::year_month_day,
                       std::chrono::year_month_day, bool, std::vector<int>, int>> work_task_to_tuple(std::vector<WorkTask> in_vec) {

    std::vector<std::tuple<int, std::string, bool, std::chrono::year_month_day,
                           std::chrono::year_month_day, bool, std::vector<int>, int>> out_vec;

    for (auto x:in_vec) {
        auto tmp = std::make_tuple(x.get_id(), x.get_name(), x.is_task_overdue(), x.get_date_start(),
                                   x.get_date_finish(), x.is_task_done(), x.get_employees_id(), x.get_project());

        out_vec.push_back(tmp);
    }

    return out_vec;
}

std::vector<Project> tuple_to_project(std::vector<std::tuple<int, std::string, std::vector<int>,
                                                             std::chrono::year_month_day, std::chrono::year_month_day,
                                                             int, int, bool, std::vector<int>>> in_vec) {
    std::vector<Project> out_vec;

    for (auto x:in_vec) {
        Project tmp(std::get<0>(x), std::get<1>(x), std::get<3>(x), std::get<4>(x));

        for (auto x:std::get<2>(x)) {
            tmp.add_employee(x);
        }

        for (auto x:std::get<8>(x)) {
            tmp.add_task(x);
        }

        for (int i = 0; i < std::get<6>(x); i++)
            tmp.complete_task();

        if (std::get<7>(x)) {
            tmp.complete();
        }

        out_vec.push_back(tmp);
    }

    return out_vec;
}

std::vector<std::tuple<int, std::string, std::vector<int>,
                       std::chrono::year_month_day, std::chrono::year_month_day,
                       int, int, bool, std::vector<int>>> project_to_tuple(std::vector<Project> in_vec) {
    std::vector<std::tuple<int, std::string, std::vector<int>,
                           std::chrono::year_month_day, std::chrono::year_month_day,
                           int, int, bool, std::vector<int>>> out_vec;

    for (auto x:in_vec) {
        auto tmp = std::make_tuple(x.get_id(), x.get_name(), x.get_employees_id(),
                                   x.get_date_start(), x.get_date_finish(), x.get_task_count(),
                                   x.get_done_task_count(), x.is_completed(), x.get_tasks());

        out_vec.push_back(tmp);
    }

    return out_vec;
}

std::vector<Employee> tuple_to_employee(std::vector<std::tuple<int, int, std::string, std::string,
                                                               std::string, std::chrono::year_month_day, double,
                                                               int, double, std::chrono::year_month_day,
                                                               bool, std::vector<int>, std::vector<int>,
                                                               std::string, std::string>> in_vec) {
    std::vector<Employee> out_vec;

    for (auto x:in_vec) {
        Employee tmp(std::get<0>(x), std::get<2>(x), std::get<3>(x), std::get<4>(x), std::get<5>(x),
                     std::get<9>(x), std::get<13>(x), std::get<14>(x));

        tmp.set_project_id(std::get<1>(x));
        tmp.set_kpi(std::get<6>(x));
        tmp.set_role(Role(std::get<7>(x)));
        tmp.set_salary(std::get<8>(x));
        tmp.set_working_status(std::get<10>(x));

        for (auto x:std::get<11>(x)) {
            tmp.add_work_task(x);
        }

        for (auto x:std::get<12>(x)) {
            std::cout << x << "|";
        }

        for (auto x:std::get<12>(x)) {
            tmp.add_personal_task(x);
        }

        out_vec.push_back(tmp);
    }

    return out_vec;
}

std::vector<std::tuple<int, int, std::string, std::string,
                       std::string, std::chrono::year_month_day, double,
                       int, double, std::chrono::year_month_day,
                       bool, std::vector<int>, std::vector<int>,
                       std::string, std::string>> employee_to_tuple(std::vector<Employee> in_vec) {
    std::vector<std::tuple<int, int, std::string, std::string,
                           std::string, std::chrono::year_month_day, double,
                           int, double, std::chrono::year_month_day,
                           bool, std::vector<int>, std::vector<int>,
                           std::string, std::string>> out_vec;

    for (auto x:in_vec) {
        auto tmp = std::make_tuple(x.get_id(), x.get_project_id(), x.get_first_name(),
                                   x.get_middle_name(), x.get_surname(), x.get_start_date(),
                                   x.get_kpi(), (int)x.get_role(), x.get_salary(), x.get_date_birth(),
                                   x.get_working_status(), x.get_work_tasks(), x.get_personal_tasks(),
                                   x.get_login(), x.get_password());

        out_vec.push_back(tmp);
    }

    return out_vec;
}

int main()
{
    std::string login, password;

    std::vector<PersonalTask> vec2 = tuple_to_personal_task(deserealize_personal_task("E:\\personal_task.json"));
    std::vector<Employee> vec = tuple_to_employee(deseralize_employee("E:\\employee.json"));//*/db_manager::get_employees("E:\\");
    std::vector<WorkTask> vec1 = tuple_to_work_task(deserealize_work_task("E:\\work_task.json")); //*/db_manager::get_work_tasks("E:\\");
    std::vector<Project> vec3 = tuple_to_project(deserealize_project("E:\\project.json")); //*/db_manager::get_projects("E:\\");

    while (1) {
        std::cout << "Enter login: ";
        std::cin >> login;
        std::cout << "Enter password: ";
        std::cin >> password;

        if (login == "exit")
            break;

        auto cur_user = std::find_if(vec.begin(), vec.end(),
                                     [login, password](Employee tmp){return tmp.get_login() == login && tmp.get_password() == password;});

        if (cur_user == vec.end()) {
            std::cout << "Incorrect password";
        } else if (cur_user->get_role() == Role::Boss) {
            std::cout << "Hi, " << cur_user->get_first_name() << ' ' <<
                cur_user->get_middle_name() << ' ' << cur_user->get_surname() << "!\n";
            std::cout << "You are a boss\n";
            role_class::boss(*cur_user, vec, vec1, vec2, vec3);
        } else if (cur_user->get_role() == Role::hr_manager) {
            std::cout << "Hi, " << cur_user->get_first_name() << ' ' <<
                cur_user->get_middle_name() << ' ' << cur_user->get_surname() << "!\n";
            std::cout << "You are a manager\n";
            role_class::hr_mngr(*cur_user, vec, vec1, vec2, vec3);
        } else if (cur_user->get_role() == Role::project_manager) {
            std::cout << "Hi, " << cur_user->get_first_name() << ' ' <<
                cur_user->get_middle_name() << ' ' << cur_user->get_surname() << "!\n";
            std::cout << "You are a pm\n";
            role_class::manager(*cur_user, vec, vec1, vec2, vec3);
        } else {
            std::cout << "Hi, " << cur_user->get_first_name() << ' ' <<
                cur_user->get_middle_name() << ' ' << cur_user->get_surname() << "!\n";
            std::cout << "You are a slave\n";
            role_class::slave(*cur_user, vec, vec1, vec2, vec3);
        }

        serialize_personal_task(personal_task_to_tuple(vec2), "E:\\personal_task.json");
        serialize_work_task(work_task_to_tuple(vec1), "E:\\work_task.json");
        serialize_project(project_to_tuple(vec3), "E:\\project.json");
        serializer_employee(employee_to_tuple(vec), "E:\\employee.json");

    }

    return 0;
}
