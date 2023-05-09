
#ifndef JSONSERIALIZER_HPP
#define JSONSERIALIZER_HPP

#include <tuple>
#include <string>
#include <chrono>
#include <vector>

#if defined(__NT__)|| defined(_MSC_VER)|| defined(WIN32) || defined(_WIN32) || defined(_WIN32_) || defined(__WIN32__) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(_WIN62_) || defined(__WIN64) || defined(__WIN64__)
#define JSONSERIALIZER_EXPORT __declspec(dllexport)
#define JSONSERIALIZER_IMPORT __declspec(dllimport)
#endif


void JSONSERIALIZER_EXPORT serialize_personal_task(std::vector<std::tuple<int, std::string, bool,
                                                   std::chrono::year_month_day, std::chrono::year_month_day,
                                                   bool, std::string, int>> in_vec, std::string file_name);
void JSONSERIALIZER_EXPORT serialize_work_task(std::vector<std::tuple<int, std::string, bool, std::chrono::year_month_day,
                                                                      std::chrono::year_month_day, bool, std::vector<int>, int>> in_vec,
                                               std::string file_name);
void JSONSERIALIZER_EXPORT serialize_project(std::vector<std::tuple<int, std::string, std::vector<int>,
                                                                    std::chrono::year_month_day, std::chrono::year_month_day,
                                                                    int, int, bool, std::vector<int>>> in_vec,
                                             std::string file_name);
void JSONSERIALIZER_EXPORT serializer_employee(std::vector<std::tuple<int, int, std::string, std::string,
                                                                      std::string, std::chrono::year_month_day, double,
                                                                      int, double, std::chrono::year_month_day,
                                                                      bool, std::vector<int>, std::vector<int>,
                                                                      std::string, std::string>> in_vec,
                                               std::string file_name);

std::vector<std::tuple<int, std::string, bool,
                       std::chrono::year_month_day, std::chrono::year_month_day,
                       bool, std::string, int>> JSONSERIALIZER_EXPORT deserealize_personal_task(std::string file_name);

std::vector<std::tuple<int, std::string, bool, std::chrono::year_month_day,
                       std::chrono::year_month_day, bool, std::vector<int>, int>> JSONSERIALIZER_EXPORT deserealize_work_task(std::string file_name);

std::vector<std::tuple <int, std::string, std::vector<int>,
                       std::chrono::year_month_day, std::chrono::year_month_day,
                       int, int, bool, std::vector<int>>> JSONSERIALIZER_EXPORT deserealize_project(std::string file_name);

std::vector<std::tuple<int, int, std::string, std::string, std::string, std::chrono::year_month_day,
                       double, int, double, std::chrono::year_month_day, bool, std::vector<int>, std::vector<int>,
                       std::string, std::string>> JSONSERIALIZER_EXPORT deseralize_employee(std::string file_name);



#endif // JSONSERIALIZER_H
