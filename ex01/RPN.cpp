#include "RPN.hpp"

RPN *RPN::_instance = NULL;

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const char *arg)
{
    std::string str(arg);

    for (size_t i = 0; i < str.length(); i++) {
        if (i & 1) {
            if (str[i] != ' ')
                throw "format error";
        }
        else {
            if (!(std::isdigit(str[i]) || str[i] == '*' || str[i] == '-' || str[i] == '/' || str[i] == '+'))
                throw "not a number or arithmatic sign";
            _que.push(str[i]);
        }
    }
}

RPN::RPN(const RPN &ref)
{
    (void) ref;
}

RPN &RPN::operator=(const RPN &ref)
{
    (void) ref;
    return *this;
}

RPN *RPN::get_instance(const char *arg)
{
    if (!_instance)
        _instance = new RPN(arg);
    return _instance;
}

void RPN::release_instance()
{
    if (_instance)
        delete _instance;
    _instance = NULL;
}

int RPN::execute()
{
    std::queue<char> &que = _instance->_que;
    std::stack<int> stk;

    while (!que.empty()) {
        char cur = que.front();
        que.pop();

        if (std::isdigit(cur))
            stk.push(cur - '0');
        else {
            long long num1, num2, res;
            if (stk.size() < 2)
                throw "Error";

            num2 = stk.top();
            stk.pop();
            num1 = stk.top();
            stk.pop();
            switch (cur) {
            case '+':
                res = num1 + num2;
                break;
            case '-':
                res = num1 - num2;
                break;
            case '*':
                res = num1 * num2;
                break;
            case '/':
                if (num2 == 0)
                    throw "Zero division error";
                res = num1 / num2;
            }
            if (res > INT_MAX || res < INT_MIN)
                throw "Error";
            stk.push(static_cast<int>(res));
        }
    }

    if (stk.size() != 1)
        throw "Error";
    
    return stk.top();
}