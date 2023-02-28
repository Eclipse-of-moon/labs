#include <iostream>
#include <cstring>

using namespace std;

void InputString(char* input) {
    int i = 0;
    std::cin >> input[i];
    while (input[i] != '.') {
        i++;
        std::cin >> input[i];
    }
    input[i] = '\0';
}

bool CheckPalindrome(const char* text) {

    int leftChar = 0;
    int rightChar = strlen(text) - 1;

    for (leftChar; leftChar <= rightChar; leftChar++, rightChar--) {
        if (text[leftChar] == ' ') {
            leftChar++;
            continue;
        }
        if (text[rightChar] == ' ') {
            rightChar--;
            continue;
        }
        if (tolower(text[leftChar]) != tolower(text[rightChar])) {
            return false;
        }
    }
    return true;
}

void task1() {

    std::cout << "Palindrome\n\n";

    std::cout << "Enter full string: ";

    char input[255];
    InputString(input);

    if (CheckPalindrome(input)) {
        std::cout << "This is palindrome" << std::endl;
    }
    else {
        std::cout << "This is't palindrome" << std::endl;
    }

    system("pause");
}

int find_substring1(const char* str_for_search_in, const char* substring, int start_position) {
    int j;
    for (int i = start_position; i < strlen(str_for_search_in); i++) {
        j = 0;
        while (str_for_search_in[i + j] == substring[j]) {
            j++;
            if (j >= strlen(substring)) {
                return i;
            }
        }
    }
    return -1;
}

int* find_substring2(const char* str_for_search_in, const char* substring) {
    int j, count = 0;
    static int sub_arr[10];
    for (int i = 0; i < strlen(str_for_search_in); i++) {
        j = 0;
        while (str_for_search_in[i + j] == substring[j]) {
            j++;
            if (j >= strlen(substring)) {
                sub_arr[count] = i;
                count++;
            }
        }

    }
    return sub_arr;
}

void task2() {

    std::cout << "SUBSTRING SEARCH\n\n";

    std::cout << "Enter full string: ";
    char input[255];
    InputString(input);
    std::cout << "Enter search string: ";
    char substring[50];
    InputString(substring);
    std::cout << "Enter search start position num: ";
    int start_position;
    std::cin >> start_position;

    int output_position1 = find_substring1(input, substring, start_position); //first
    if (output_position1 > 0) {
        std::cout << "\nYour searched first position: " << output_position1 << "\n\n";

        std::cout << "All positions:" << std::endl;
        int* output_position2 = find_substring2(input, substring); //second
        for (int i = 0; i <= sizeof(output_position2) / sizeof(output_position2[0]); i++) {
            std::cout << output_position2[i] << std::endl;
        }
    }
    else {
        std::cout << "Cant find your substring" << std::endl;;
    }

    system("pause");
}

void encrypt(char* str_for_encrypt, int key) {
    int i = 0;
    do
    {
        str_for_encrypt[i] += key;
        i++;
    } while (str_for_encrypt[i] != '\0');
}

void task3() {

    std::cout << "ENCRYPT\n\n";

    std::cout << "Enter string: ";
    char str_for_encrypt[255];
    InputString(str_for_encrypt);
    std::cout << "Enter key: ";
    int key;
    std::cin >> key;

    encrypt(str_for_encrypt, key);
    std::cout << "Encrypted message: " << str_for_encrypt << std::endl;

    system("pause");
}

char* Filter_string(char* str_for_filter) {
    int i, j = 0;
    bool typing = false;
    static char filtred_arr[255];
    for (i = 0; i < strlen(str_for_filter); i++) {
        while (typing == true) {
            if (str_for_filter[i] == '\"') {
                typing = false;
                i++;
                continue;
            }
            filtred_arr[j] = str_for_filter[i];
            j++;
            i++;
        }
        if (str_for_filter[i] == '\"') {
            typing = true;
        }
    }

    return filtred_arr;
}
void task4() {

    std::cout << "INSIDE THE QUOTATION\n\n";

    std::cout << "Enter string: ";
    char str_for_filter[255];
    InputString(str_for_filter);

    std::cout << "Filtered message: " << Filter_string(str_for_filter) << std::endl;

    system("pause");
}


int main() {

    int choice = 0;
    while (true) {

        system("CLS");//clear console
        std::cout << "===========================\n";
        std::cout << "1. Task Palindrome\n" << "2. Task Search\n" << "3. Task Encrypt\n" << "4. Task Filter\n" << "5. Exit\n";
        std::cout << "What do you want to choose? ";
        std::cin >> choice;
        std::cout << "===========================\n\n";

        switch (choice) {
        case 1: {
            task1();
            break;
        }
        case 2: {
            task2();
            break;
        }
        case 3: {
            task3();
            break;
        }
        case 4: {
            task4();
            break;
        }
        default: {
            return 0;
        }
        }
    }
}

