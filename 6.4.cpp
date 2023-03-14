#include <iostream>
#include <string>
#include <set>

using std::cout;
using std::cin;
using std::endl;
using std::set;
using std::string;
using std::to_string;

int main() {
    set<string> stLogin;
    set<string> stLoginNum;
    string input = "";
    int inputNum;
    std::cout << "Break: exit" << std::endl;
    while (true) {
        std::cout << "Login: " << std::endl;
        std::cin >> input;
        if (input == "exit") {
            break;
        }
        cin >> inputNum;
        if (stLogin.empty() || stLogin.find(input) == stLogin.end()) {
            std::cout << "Login True: " << input << std::endl;

            stLogin.insert(input);
            stLoginNum.insert(input + " " + to_string(inputNum));

            for (auto loginNum : stLoginNum) {
                std::cout << loginNum << std::endl;
            }
        }
        else {
            std::cout << "Login False: " << input << std::endl;

            for (auto loginNum : stLoginNum) {
                std::cout << loginNum << std::endl;
            }
        }
    }
}