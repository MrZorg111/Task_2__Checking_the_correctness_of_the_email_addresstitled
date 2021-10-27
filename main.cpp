#include <iostream>
#include <string>


std::string chek(std::string a, std::string b) {
    0123456789abcdefgijklmnopqrstuvwxyzABCDEFGIJKLMNOPRSTUVWXYZ.
}

int main() {

    std::string email, email_path1, email_path2;
    std::cout << "Enter email address: \n";
    std::cin >> email;

    for (int i = 0; i < email.length();) {
        char e = email[i];
        if (e == 64) {
            for (int j = i + 1; j < email.length();) {
                e = email[j];
                email_path2 += e;
                j++;
            }
            break;
        }
        email_path1 += e;
        i++;
    }
std::cout << chek(email_path1, email_path2);
}

