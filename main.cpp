#include <iostream>
#include <string>


std::string chek(std::string a, std::string b) {
    std::string part_chek1 = "0123456789abcdefgijklmnopqrstuvwxyzABCDEFGIJKLMNOPRSTUVWXYZ.-!#$%&'*+-/=?^_`{|}~";
    std::string part_chek2 = "0123456789abcdefgijklmnopqrstuvwxyzABCDEFGIJKLMNOPRSTUVWXYZ.-";
    char spot = '.';
    bool good = true;
    for (int i = 0; i < a.length();) {
        for (int j = 0; j < part_chek1.length();) {
           if (a[i] != part_chek1[j]) {
               good = false;
               break;
           }
            j++;

        }
        i++;
    }
    for (int i = 0; i < a.length();) {
        if (spot == a[i] && spot == a[i + 1]) {
            good = false;
            break;
        }
        if (spot == a[0] || spot == a[i == a.length() - 1]) {
            good = false;
            break;
        }
        i++;
    }
    for (int i = 0; i < b.length();) {
        for (int j = 0; j < part_chek2.length();) {
            if (b[i] != part_chek2[j]) {
                good = false;
                break;
            }
            j++;

        }
        i++;
    }
    for (int i = 0; i < b.length();) {
        if (spot == b[i] && spot == b[i + 1]) {
            good = false;
            break;
        }
        if (spot == b[0] || spot == b[i == b.length() - 1]) {
            good = false;
            break;
        }
        i++;
    }
    if (good) {
        return "Yes!";
    } else {
        return "No!";
    }
}

int main() {

    std::string email, email_part1, email_part2;
    std::cout << "Enter email address: \n";
    std::cin >> email;

    for (int i = 0; i < email.length();) {
        char e = email[i];
        if (e == 64) {
            for (int j = i + 1; j < email.length();) {
                e = email[j];
                email_part2 += e;
                j++;
            }
            break;
        }
        email_part1 += e;
        i++;
    }
std::cout << chek(email_part1, email_part2);
}

