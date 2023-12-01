#include <iostream>
#include <sstream>
#include "input.h"

void p1(){

/*
const std::string day01 = R"(1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet)";
*/

auto get_num_of_line = [](std::string const& line){
    auto const nums = "0123456789";
    auto first_digit = line.find_first_of(nums);
    auto last_digit = line.find_last_of(nums);

    return std::stoi(std::string{line[first_digit], line[last_digit]});

};

std::stringstream ss(day01);
std::string line;
int sum = 0;
while(std::getline(ss,line,'\n')){
    sum += get_num_of_line(line);
}

std::cout << sum << std::endl;
}


void p2(){

    
}




int main() {
    p1();
}