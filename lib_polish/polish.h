//Copyright 2022 Andrey Karagodin

#ifndef LIB_POLISH_POLISH_H_
#define LIB_POLISH_POLISH_H

#include <iostream>
#include <string>
#include <ctype.h>
#include "../lib_stack/stack.h"
#include "../lib_list/list.h"
#include <algorithm>

using namespace std;


class Parser {
    string symbols[7] = { "+", "-", "*", "/", "x", "(", ")"};
    CList<string> Lexlist;

    string removeSpaces(string input)
    {
        input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
        return input;
    }

public:
    
    Parser() {};
    bool check(string expression) {
        string newexpression;
        string symbol;
        newexpression = removeSpaces(expression);
        Stack<char> brackets;
        bool isCorrect;
        int len = newexpression.length();
        for (int i = 0; i < len; i++) {
            try {
                if (isdigit(newexpression[i])) {
                    isCorrect = true;
                }
                else {
                    symbol = newexpression[i];
                    for (int j = 0; j < 7; j++) {
                        if (symbol == symbols[j]) {
                            isCorrect = true;
                        }
                        else {
                            isCorrect = false;
                        }
                    }
                   
                }
                if (newexpression[i] == '(')
                {
                    brackets.push(newexpression[i]);
                }
                if (newexpression[i] == ')') {
                    brackets.pop();
                }
            }
            catch (const std::logic_error) {
                isCorrect = false;
                return isCorrect;
            }
        }
        return isCorrect;
        
    };

    void parse(string expression, int _X) {
        string newexpression;
        int x = _X;
        int len;
        string digitbuff;
        string symbolsbuff;
        if (check(expression)) {
            newexpression = removeSpaces(expression);
            len = newexpression.length();
            for (int i = 0; i < len; i++) {
                if (isdigit(newexpression[i])) {
                    digitbuff += newexpression[i];
                }
                else {
                    if (digitbuff != "") {
                        Lexlist.push_front(digitbuff);
                        digitbuff = "";
                    }
                    if (newexpression[i] == 'x') {
                        Lexlist.push_front(to_string(x));
                        digitbuff = "";
                    }
                    else {
                        symbolsbuff = newexpression[i];
                        Lexlist.push_front(symbolsbuff);
                    }
                }
            }
            if (digitbuff != "") {
                Lexlist.push_front(digitbuff);
                digitbuff = "";
            }

        }else 
        {
            throw logic_error("Incorrect formula to solve. Try again.");
        }
    };

    CList<string> getLexemList() {
        CList<string> copy;
        copy.copy(Lexlist);
        return copy;
    };
};

class PolishConvertor {
    Stack<string> operatorstack;
    CList<string> output;
    string op2[2] = { "+", "-" };
    string op3[2] = { "*", "/" };
    string parenthis[2] = { "(", ")" };

    bool isNumber(const std::string& s) {
        return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
    }

public:
    PolishConvertor() {};
    CList<string> convert(CList<string> list) {
        string token;
        string opbuff;
        int len = list.getSize();
        for (int i = 0; i < len; i++) {
            token = list.pop_back();
            if (isNumber(token)) {
                output.push_front(token);
                token = "";
            }
            for (int j = 0; j < 2; j++) {
                if (token == op2[j]) {
                    if (!operatorstack.isEmpty()) {
                        opbuff = operatorstack.gettop();
                        while (opbuff == op3[j] || opbuff == op2[j]) {
                            output.push_front(operatorstack.pop());
                            if (!operatorstack.isEmpty()) {
                                opbuff = operatorstack.gettop();
                            }
                            else {
                                opbuff = "";
                            }
                        }
                    }
                    operatorstack.push(token);
                    token = "";
                }
                if (token == op3[j]) {
                    if (!operatorstack.isEmpty()) {
                        opbuff = operatorstack.gettop();
                        while (opbuff == op3[0] || opbuff == op3[1]) {
                            output.push_front(operatorstack.pop());
                            if (!operatorstack.isEmpty()) {
                                opbuff = operatorstack.gettop();
                            }
                            else {
                                opbuff = "";
                            }
                        }
                    }
                    operatorstack.push(token);
                    token = "";
                }
            }
            if (token == parenthis[0]) {
                operatorstack.push(token);
            }
            if (token == parenthis[1]) {
                opbuff = operatorstack.gettop();
                while (opbuff != parenthis[0]) {
                    output.push_front(operatorstack.pop());
                    opbuff = operatorstack.gettop();
                }
                operatorstack.pop();
                token = "";
            }
        }
        if (!operatorstack.isEmpty()) {
            while (!operatorstack.isEmpty()) {
                output.push_front(operatorstack.pop());
            }
        }
        CList<string> copy;
        copy.copy(output);
        cout << "Reverse Polish notation: ";
        while (!copy.isEmpty()) {
            cout << copy.pop_back() << " ";
        }
        return output;
    }
};

class Calculator {
    Parser p;
    PolishConvertor c;
    string expression;
    float X;
    float result;
    float add(string num1, string num2) {
        float number1 = stof(num1);
        float number2 = stof(num2);
        return number1 + number2;
    }
    float subs(string num1, string num2) {
        float number1 = stof(num1);
        float number2 = stof(num2);
        return number1 - number2;
    }
    float mult(string num1, string num2) {
        float number1 = stof(num1);
        float number2 = stof(num2);
        return number1 * number2;
    }
    float div(string num1, string num2) {
        float number1 = stof(num1);
        float number2 = stof(num2);
        return number1 / number2;
    }
public:
    Calculator() {};

    float calculate(string expression, int _x) {
        int x = _x;
        CList<string> explist;
        Stack<string> stlist;
        p.parse(expression, x);
        explist = c.convert(p.getLexemList());
        int len = explist.getSize();
        string buff;
        float res = 0;
        for (int i = 0; i < len; i++) {
            buff = explist.pop_back();
            if (isdigit(buff[0])) {
                stlist.push(buff);
            }
            else {
                if (buff == "+") {
                    string num1 = stlist.pop();
                    string num2 = stlist.pop();
                    res = add(num1, num2);
                    stlist.push(to_string(res));
                }
                if (buff == "-") {
                    string num2 = stlist.pop();
                    string num1 = stlist.pop();
                    res = subs(num1, num2);
                    stlist.push(to_string(res));
                }
                if (buff == "*") {
                    string num1 = stlist.pop();
                    string num2 = stlist.pop();
                    res = mult(num1, num2);
                    stlist.push(to_string(res));
                }
                if (buff == "/") {
                    string num2 = stlist.pop();
                    string num1 = stlist.pop();
                    res = div(num1, num2);
                    stlist.push(to_string(res));
                }
            }
        }
        return res;
    }
};

#endif // LIB_POLISH_POLISH_H