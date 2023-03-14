#include <iostream>
#include <string>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;
using std::list;

int main() {
    string surname;
    int group;
    list<string> listSurname;
    list<int> listGroup;
    cout << "Break: 0 0" << endl;
    while (true) {
        cin >> group >> surname;
        if (group == 0 || surname == "0") {
            break;
        }

        listSurname.push_back(to_string(group) + " " + surname);
        listGroup.push_back(group);
    }
    cout << endl;
    listGroup.sort();
    listGroup.unique();
    for (auto group : listGroup) {
        cout << group << ":" << endl;
        for (auto surname : listSurname) {
            if (surname.find(to_string(group)) != string::npos) {
                cout << surname << endl;
            }
        }
        cout << endl;
    }
}