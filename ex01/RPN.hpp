#pragma once

#include <stack>
#include <string>
#include <queue>

class RPN {
private:
    static RPN *_instance;

    std::queue<char> _que;

    RPN();
    ~RPN();
    RPN(const char *arg);
    RPN(const RPN &ref);
    RPN &operator=(const RPN &ref);

public:
    static RPN *get_instance(const char *arg);
    static void release_instance();
    
    static int execute();
};
