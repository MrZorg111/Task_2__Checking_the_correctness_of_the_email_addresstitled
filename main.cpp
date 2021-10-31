#include <iostream>
#include <string>


 std::string chek(std::string a, std::string b) {
    std::string part_chek1 = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.-!#$%&'*+/=?^_`{|}~";
    std::string part_chek2 = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.-";
    int count1 = 0, count2 = 0;
    bool good = true;
     for (int i = 0; i < a.length(); i++) {
         for (int j = 0; j < part_chek1.length(); j++) {
             if (a[i] == part_chek1[j]) {
                 count1++;
             }
         }
     }
     if (count1 != a.length()) {
         good = false;
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
    //std::cout << a << "\t" << count1 << "\t" << a.length() << "\n"; Проверочная строка.
     for (int i = 0; i < b.length(); i++) {
         for (int j = 0; j < part_chek2.length(); j++) {
             if (b[i] == part_chek2[j]) {
                 count2++;
             }
         }
     }
     if (count2 < b.length()) {
         good = false;
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
     //std::cout << b << "\t" << count2 << "\t" << b.length() << "\n"; Проверочная строка.
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
//std::cout << email_part1 << "\t" << email_part2 << "\n"; Проверочная строка.
   if (email_part2.length() == 0) {
       std::cout << "No!";
   }
   if ((email_part1.length() < 1 || email_part1.length() > 64) || (email_part2.length() < 1 || email_part2.length() > 63)) {
       std::cout << "No!";
   }
   else {
       std::cout << chek(email_part1, email_part2);
   }
}

