
#include "../include/employee.h"
#include <iostream>

/*std::string get_hash(std::string str_to_hash) {
    const unsigned int length = 128;
    unsigned char res[length];
    memset(res, 0, length * sizeof(unsigned char));
    unsigned char salt = 0;
    PKCS5_PBKDF2_HMAC(str_to_hash.c_str(), str_to_hash.size() * sizeof(str_to_hash[0]),
                      &salt, sizeof(salt), 4096, EVP_sha512(),
                      length * sizeof(unsigned char), res);

    std::stringstream output;
    for (size_t i = 0; i < length; i++) {
        output << std::setw(sizeof(unsigned char) * 2) << std::setfill('0')
               << std::hex << static_cast<unsigned short>(res[i]);
    }
    return output.str();
}*/

Employee::Employee(int id, std::string first_name, std::string middle_name, std::string surname,
         std::chrono::year_month_day date_birth) :
    id(id), first_name(first_name), middle_name(middle_name), surname(surname),
    date_birth(date_birth)
{
    date_start = std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now());
    //this->login = get_hash(this->first_name);
    //this->password = get_hash(this->first_name);
    this->login = first_name;
    this->password = first_name;
}

Employee::Employee(int id, std::string first_name, std::string middle_name, std::string surname,
                   std::chrono::year_month_day date_birth, std::chrono::year_month_day date_start) :
    id(id), first_name(first_name), middle_name(middle_name), surname(surname),
    date_birth(date_birth), date_start(date_start)
{
    //this->login = get_hash(this->first_name);
    //this->password = get_hash(this->first_name);
    this->login = first_name;
    this->password = first_name;
}

Employee::Employee(int id, std::string first_name, std::string middle_name, std::string surname,
         std::chrono::year_month_day date_birth, std::chrono::year_month_day date_start,
         std::string login, std::string password) :
    id(id), first_name(first_name), middle_name(middle_name), surname(surname),
    date_birth(date_birth), date_start(date_start), login(login), password(password)
{}

void Employee::set_salary(double new_salary) {
    this->salary = new_salary;
}
double Employee::get_salary() {
    return this->salary;
}
void Employee::set_role(Role new_role) {
    this->role = new_role;
}
Role Employee::get_role() {
    return this->role;
}
void Employee::set_kpi(double new_kpi) {
    this->KPI = new_kpi;
}
double Employee::get_kpi() {
    return this->KPI;
}
void Employee::set_working_status(bool new_status) {
    this->is_cur_working = new_status;
}
bool Employee::get_working_status() {
    return this->is_cur_working;
}
std::chrono::year_month_day Employee::get_start_date() {
    return this->date_start;
}
std::chrono::year_month_day Employee::get_date_birth() {
    return this->date_birth;
}
std::string Employee::get_middle_name() {
    return this->middle_name;
}
std::string Employee::get_first_name() {
    return this->first_name;
}
std::string Employee::get_surname() {
    return this->surname;
}
std::vector<int> Employee::get_work_tasks() {
    return this->work_task_vec;
}
std::vector<int> Employee::get_personal_tasks() {
    return personal_task_vec;
}
void Employee::add_work_task(int new_task) {
    this->work_task_vec.push_back(new_task);

}
void Employee::add_personal_task(int new_task) {
    this->personal_task_vec.push_back(new_task);
}

int Employee::get_id() {
    return this->id;
}

void Employee::set_project_id(int new_project_id) {
    this->project_id = new_project_id;
}

int Employee::get_project_id() {
    return this->project_id;
}

std::string Employee::get_login() {
    return this->login;
}

void Employee::set_login(std::string new_login) {
    this->login = new_login;
}

std::string Employee::get_password() {
    return this->password;
}

void Employee::set_password(std::string new_password) {
    this->password = new_password;
}

void Employee::remove_task(int id) {
    this->work_task_vec.erase(std::find_if(this->work_task_vec.begin(), this->work_task_vec.end(),
                                          [id](int task_id){return id == task_id;}));
}

void Employee::remove_personal_task(int id) {
    std::cout << "point 1";
    auto it = std::find_if(this->personal_task_vec.begin(), this->personal_task_vec.end(),
                           [id](int task_id){return id == task_id;});
    std::cout << *it;
    this->personal_task_vec.erase(it);
}
