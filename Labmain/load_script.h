//
// Created by User on 25/11/2024.
//

#ifndef LOAD_SCRIPT_H
#define LOAD_SCRIPT_H

struct ColorConsole
{
  public:
    static constexpr auto fg_blue = "\033[34m";
    public:
    static constexpr auto bg_white = "\033[47m";
};

struct ConsoleBox
{
    void new_text() {/*...*/}
    void set_text(const string &text) { cout << text << endl; }
};

#endif //LOAD_SCRIPT_H
