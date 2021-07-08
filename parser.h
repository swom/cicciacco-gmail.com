#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <vector>
#include "network.h"

static std::map<std::string, std::function<double(double)>> string_to_act_func_map
{
{"linear", linear},
{"sigmoid", sigmoid}
};

std::vector<int> arch_str_to_arch_vec(std::string net_arc);

std::function<double(double)> parse_act_func(const std::vector<std::string>& args);

double parse_change_freq(const std::vector<std::string>& args);

double parse_mut_step(const std::vector<std::string>& args);

double parse_mut_rate(const std::vector<std::string>& args);

std::vector<int> parse_net_arc(const std::vector<std::string>& args);

int parse_pop_size(const std::vector<std::string>& args);

int parse_seed(const std::vector<std::string>& args);

int parse_sel_str(const std::vector<std::string>& args);

double parse_targetA(const std::vector<std::string>& args);
double parse_targetB(const std::vector<std::string>& args);

void test_parser();
#endif // PARSER_H
