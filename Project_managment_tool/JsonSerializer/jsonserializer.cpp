
#include "jsonserializer.hpp"
#include "json.hpp"
#include <iostream>
#include <fstream>


void serialize_personal_task(std::vector<std::tuple<int, std::string, bool,
                                         std::chrono::year_month_day, std::chrono::year_month_day,
                                         bool, std::string, int>> in_vec,
                             std::string file_name) {

    nlohmann::json j_tmp, j_res;
    std::vector<nlohmann::json> j_vec(in_vec.size());

    for (int i = 0; i < in_vec.size(); i++) {
        std::ostringstream date_s, date_f;

        date_s << std::get<3>(in_vec[i]);
        date_f << std::get<4>(in_vec[i]);

        j_tmp["id"] = std::get<0>(in_vec[i]);
        j_tmp["name"] = std::get<1>(in_vec[i]);
        j_tmp["is_done"] = std::get<2>(in_vec[i]);
        j_tmp["date_start"] = date_s.str();
        j_tmp["date_finish"] = date_f.str();
        j_tmp["is_overdue"] = std::get<5>(in_vec[i]);
        j_tmp["description"] = std::get<6>(in_vec[i]);
        j_tmp["employee_id"] = std::get<7>(in_vec[i]);

        date_s.clear();
        date_f.clear();

        j_vec[i] = j_tmp;
    }

    std::ofstream out(file_name);
    out << std::setw(2) << j_vec;
    out.close();
}

void serialize_work_task(std::vector<std::tuple<int, std::string, bool, std::chrono::year_month_day,
                                                std::chrono::year_month_day, bool, std::vector<int>, int>> in_vec,
                         std::string file_name) {
    nlohmann::json j_tmp, j_res;
    std::vector<nlohmann::json> j_vec(in_vec.size());

    for (int i = 0; i < in_vec.size(); i++) {
        std::ostringstream date_s, date_f;

        date_s << std::get<3>(in_vec[i]);
        date_f << std::get<4>(in_vec[i]);

        j_tmp["id"] = std::get<0>(in_vec[i]);
        j_tmp["name"] = std::get<1>(in_vec[i]);
        j_tmp["is_done"] = std::get<2>(in_vec[i]);
        j_tmp["date_start"] = date_s.str();
        j_tmp["date_finish"] = date_f.str();
        j_tmp["is_overdue"] = std::get<5>(in_vec[i]);
        j_tmp["employees_id"] = std::get<6>(in_vec[i]);
        j_tmp["project_id"] = std::get<7>(in_vec[i]);

        date_s.clear();
        date_f.clear();

        j_vec[i] = j_tmp;
    }



    std::ofstream out(file_name);
    out << std::setw(2) << j_vec;
    out.close();
}

void serialize_project(std::vector<std::tuple<int, std::string, std::vector<int>,
                                              std::chrono::year_month_day, std::chrono::year_month_day,
                                              int, int, bool, std::vector<int>>> in_vec,
                       std::string file_name) {
    nlohmann::json j_tmp;
    std::vector<nlohmann::json> j_vec(in_vec.size());

    for (int i = 0; i < in_vec.size(); i++) {
        std::stringstream date_s, date_f;

        date_s << std::get<3>(in_vec[i]);
        date_f << std::get<4>(in_vec[i]);

        j_tmp["id"] = std::get<0>(in_vec[i]);
        j_tmp["project_name"] = std::get<1>(in_vec[i]);
        j_tmp["tasks_vec"] = std::get<2>(in_vec[i]);
        j_tmp["date_start"] = date_s.str();
        j_tmp["date_finish"] = date_f.str();
        j_tmp["task_count"] = std::get<5>(in_vec[i]);
        j_tmp["done_task_count"] = std::get<6>(in_vec[i]);
        j_tmp["is_done"] = std::get<7>(in_vec[i]);
        j_tmp["employee_vec"] = std::get<8>(in_vec[i]);

        date_s.clear();
        date_f.clear();


        j_vec[i] = j_tmp;
    }

    std::ofstream out(file_name);
    out << std::setw(2) << j_vec;
    out.close();
}



void serializer_employee(std::vector<std::tuple<int, int, std::string, std::string,
                                                std::string, std::chrono::year_month_day, double,
                                                int, double, std::chrono::year_month_day,
                                                bool, std::vector<int>, std::vector<int>,
                                                std::string, std::string>> in_vec,
                         std::string file_name) {
    nlohmann::json j_tmp;
    std::vector<nlohmann::json> j_vec(in_vec.size());

    for (int i = 0; i < in_vec.size(); i++) {
        std::ostringstream date_s, date_b;

        date_b << std::get<5>(in_vec[i]);
        date_s << std::get<9>(in_vec[i]);

        j_tmp["id"] = std::get<0>(in_vec[i]);
        j_tmp["project_id"] = std::get<1>(in_vec[i]);
        j_tmp["first_name"] = std::get<2>(in_vec[i]);
        j_tmp["middle_name"] = std::get<3>(in_vec[i]);
        j_tmp["surname"] = std::get<4>(in_vec[i]);
        j_tmp["date_birth"] = date_b.str();
        j_tmp["KPI"] = std::get<6>(in_vec[i]);
        j_tmp["role"] = std::get<7>(in_vec[i]);
        j_tmp["salary"] = std::get<8>(in_vec[i]);
        j_tmp["date_start"] = date_s.str();
        j_tmp["is_cur_working"] = std::get<10>(in_vec[i]);
        j_tmp["work_task_vec"] = std::get<11>(in_vec[i]);

        std::cout << "\n---------------\n";

        for (auto x:std::get<12>(in_vec[i])) {
            std::cout << x << ' ';
        }

        std::cout << "\n---------------\n";

        j_tmp["personal_task_vec"] = std::get<12>(in_vec[i]);
        j_tmp["login"] = std::get<13>(in_vec[i]);
        j_tmp["password"] = std::get<14>(in_vec[i]);

        date_s.clear();
        date_b.clear();

        j_vec[i] = j_tmp;
    }
    std::ofstream out(file_name);
    out << std::setw(2) << j_vec;
    out.close();
}

std::vector<std::tuple<int, std::string, bool,
                       std::chrono::year_month_day, std::chrono::year_month_day,
                       bool, std::string, int>> deserealize_personal_task(std::string file_name) {
    nlohmann::json j;
    std::ifstream in(file_name);
    std::chrono::year_month_day date_start, date_finish;
    std::vector<std::tuple<int, std::string, bool,
                           std::chrono::year_month_day, std::chrono::year_month_day,
                           bool, std::string, int>> out_vec;


    in >> j;
    in.close();

    for (auto x:j) {
        std::stringstream date_s, date_f;

        int id = x["id"];
        std::string name = x["name"];
        bool is_done = x["is_done"];
        std::string date_s_str = x["date_start"];
        std::string date_f_str = x["date_finish"];
        bool is_overdue = x["is_overdue"];
        std::string description = x["description"];
        int employee_id = x["employee_id"];

        date_s << date_s_str;
        date_f << date_f_str;

        std::chrono::from_stream(date_s, "%F", date_start);
        std::chrono::from_stream(date_f, "%F", date_finish);

        date_s.clear();
        date_f.clear();

        auto tmp = std::make_tuple(id, name, is_done, date_start, date_finish, is_overdue, description, employee_id);

        out_vec.push_back(tmp);
    }

    return out_vec;

}

std::vector<std::tuple<int, std::string, bool, std::chrono::year_month_day,
                       std::chrono::year_month_day, bool, std::vector<int>, int>> deserealize_work_task(std::string file_name) {
    nlohmann::json j;
    std::ifstream in(file_name);
    std::chrono::year_month_day date_start, date_finish;
    std::vector<std::tuple<int, std::string, bool, std::chrono::year_month_day,
                           std::chrono::year_month_day, bool, std::vector<int>, int>> out_vec;

    in >> j;
    in.close();

    for (auto x:j) {
        std::stringstream date_s, date_f;

        int id = x["id"];
        std::string name = x["name"];
        bool is_done = x["is_done"];
        std::string date_s_str = x["date_start"];
        std::string date_f_str = x["date_finish"];
        bool is_overdue = x["is_overdue"];
        std::vector<int> employees_id = x["employees_id"];
        int project_id = x["project_id"];

        date_s << date_s_str;
        date_f << date_f_str;

        std::chrono::from_stream(date_s, "%F", date_start);
        std::chrono::from_stream(date_f, "%F", date_finish);

        date_s.clear();
        date_f.clear();

        auto tmp = std::make_tuple(id, name, is_done, date_start, date_finish, is_overdue, employees_id, project_id);

        out_vec.push_back(tmp);
    }

    return out_vec;
}

std::vector<std::tuple <int, std::string, std::vector<int>,
           std::chrono::year_month_day, std::chrono::year_month_day,
                       int, int, bool, std::vector<int>>> deserealize_project(std::string file_name) {
    nlohmann::json j;
    std::ifstream in(file_name);
    std::chrono::year_month_day date_start, date_finish;
    std::vector<std::tuple <int, std::string, std::vector<int>,
                           std::chrono::year_month_day, std::chrono::year_month_day,
                           int, int, bool, std::vector<int>>> out_vec;

    std::cout << "jopa";

    in >> j;
    in.close();

    for (auto x:j) {
        std::stringstream date_s, date_f;

        int id = x["id"];
        std::string project_name = x["project_name"];
        std::vector<int> tasks_vec = x["tasks_vec"];
        std::string date_s_str = x["date_start"];
        std::string date_f_str = x["date_finish"];
        int task_count = x["task_count"];
        int done_task_count = x["done_task_count"];
        bool is_done = x["is_done"];
        std::vector<int> employee_vec = x["employee_vec"];

        for (auto x:employee_vec) {
            std::cout << x << '*';
        }

        date_s << date_s_str;
        date_f << date_f_str;

        std::chrono::from_stream(date_s, "%F", date_start);
        std::chrono::from_stream(date_f, "%F", date_finish);

        date_s.clear();
        date_f.clear();

        auto tmp = std::make_tuple(id, project_name, tasks_vec, date_start, date_finish, task_count, done_task_count, is_done, employee_vec);

        out_vec.push_back(tmp);
    }

    std::cout << "jopa";

    return out_vec;
}

/*        j_tmp["id"] = std::get<0>(in_vec[0]);
        j_tmp["project_id"] = std::get<1>(in_vec[0]);
        j_tmp["first_name"] = std::get<2>(in_vec[0]);
        j_tmp["middle_name"] = std::get<3>(in_vec[0]);
        j_tmp["surname"] = std::get<4>(in_vec[0]);
        j_tmp["date_birth"] = date_b.str();
        j_tmp["KPI"] = std::get<6>(in_vec[0]);
        j_tmp["role"] = std::get<7>(in_vec[0]);
        j_tmp["salary"] = std::get<8>(in_vec[0]);
        j_tmp["date_start"] = date_s.str();
        j_tmp["is_cur_working"] = std::get<10>(in_vec[0]);
        j_tmp["work_task_vec"] = std::get<11>(in_vec[0]);
        j_tmp["personal_task_vec"] = std::get<12>(in_vec[0]);
        j_tmp["login"] = std::get<13>(in_vec[0]);
        j_tmp["password"] = std::get<14>(in_vec[0]);*/

std::vector<std::tuple<int, int, std::string, std::string, std::string, std::chrono::year_month_day,
           double, int, double, std::chrono::year_month_day, bool, std::vector<int>, std::vector<int>,
                       std::string, std::string>> deseralize_employee(std::string file_name) {
    nlohmann::json j;
    std::ifstream in(file_name);
    std::chrono::year_month_day date_start, date_birth;
    std::vector<std::tuple<int, int, std::string, std::string, std::string, std::chrono::year_month_day,
                           double, int, double, std::chrono::year_month_day, bool, std::vector<int>, std::vector<int>,
                           std::string, std::string>> out_vec;

    std::cout << "govno";

    in >> j;
    in.close();

    for (auto x:j) {
        std::stringstream date_s, date_b;

        int id = x["id"];
        int project_id = x["project_id"];
        std::string first_name = x["first_name"];
        std::string middle_name = x["middle_name"];
        std::string surname = x["surname"];
        std::string date_b_str = x["date_birth"];
        double KPI = x["KPI"];
        int role = x["role"];
        double salary = x["salary"];
        std::string date_s_str = x["date_start"];
        bool is_cur_working = x["is_cur_working"];
        std::vector<int> work_task_vec = x["work_task_vec"];
        std::vector<int> personal_task_vec = x["personal_task_vec"];
        std::string login = x["login"];
        std::string password = x["password"];

        date_b << date_b_str;
        date_s << date_s_str;

        std::chrono::from_stream(date_s, "%F", date_start);
        std::chrono::from_stream(date_b, "%F", date_birth);

        date_b.clear();
        date_s.clear();

        auto tmp = std::make_tuple(id, project_id, first_name, middle_name, surname, date_birth, KPI, role, salary,
                                   date_start, is_cur_working, work_task_vec, personal_task_vec, login, password);

        out_vec.push_back(tmp);
    }

    std::cout << "govno";

    return out_vec;
}
