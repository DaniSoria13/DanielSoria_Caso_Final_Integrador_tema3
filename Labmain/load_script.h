//
// Created by User on 25/11/2024.
//

#ifndef LOAD_SCRIPT_H
#define LOAD_SCRIPT_H


struct ColorConsole
{
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};

struct ConsoleBox
{
    void new_text() {/*...*/}
    void set_text(const std::string &text) { std::cout << text << std::endl; }
};

void load_script(const char* filename, bool show_script = false);

void load_script();


#endif //LOAD_SCRIPT_H
