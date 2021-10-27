#include <iostream>
#include <string>


 std::string chek(std::string a, std::string b) {
    std::string part_chek1 = "0123456789abcdefgijklmnopqrstuvwxyzABCDEFGIJKLMNOPRSTUVWXYZ.-!#$%&'*+-/=?^_`{|}~";
    std::string part_chek2 = "0123456789abcdefgijklmnopqrstuvwxyzABCDEFGIJKLMNOPRSTUVWXYZ.-";

    bool good = true;
    for (int i = 0; i < a.length();) {
        for (int j = 0; j < part_chek1.length();) {
           if (a[i] != part_chek1[j] && j == part_chek1.length()) {
               good = false;
               break;
           }
            j++;

        }
        i++;
    }
    for (int i = 0; i < a.length();) {
        if (a[i] == '.' && a[i + 1] == '.') {
            good = false;
            break;
        }
        if (a[0] == '.' || a[i == a.length()] == '.') {
            good = false;
            break;
        }
        i++;
    }
    for (int i = 0; i < b.length();) {
        for (int j = 0; j < part_chek2.length();) {
            if (b[i] != part_chek2[j] && j == part_chek2.length()) {
                good = false;
                break;
            }
            j++;

        }
        i++;
    }
    for (int i = 0; i < b.length();) {
        if (b[i] == '.' && b[i + 1] == '.') {
            good = false;
            break;
        }
        if (b[0] == '.' || b[i == b.length()] == '.') {
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
    std::cout << email_part1 << "\n" << email_part2;
   if (email_part2.length() == 0) {
       std::cout << "No!";
   }else {
       std::cout << chek(email_part1, email_part2);
   }
}

