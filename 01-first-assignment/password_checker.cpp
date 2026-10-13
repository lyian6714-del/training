/*
原代码错误说明：
1. 数字判断：0 和 9 是整数值，不是数字字符。
   应使用字符 '0' 和 '9'。
2. 长度判断：password.size() <= 10 判断的是长度至多为 10。
   题目要求至少 10 个字符，应改为 >= 10。
3. 范围边界：lower < ch && ch < upper 排除了两端字符，
   导致 A、Z、a、z、0、9 不被正确识别。
   应使用 lower <= ch && ch <= upper。
4. 编译警告：变量 checked 没有被使用，删除该变量。

自设计测试：
输入：Li Wang Abcdefghi0
预期输出：VALID
理由：长度恰好为 10，含大写字母、小写字母和数字，
      不包含 Li 或 Wang，同时检查 A 和 0 的范围边界。
*/

#include <iostream>
#include <string>

bool contains_between(const std::string& text, char lower, char upper) {
    for (char ch : text) {
        if (lower <= ch && ch <= upper) {
            return true;
        }
    }
    return false;
}

bool check_password(const std::string& first_name,
                    const std::string& last_name,
                    const std::string& password) {
    bool length_ok = password.size() >= 10;
    bool upper_ok = contains_between(password, 'A', 'Z');
    bool lower_ok = contains_between(password, 'a', 'z');
    bool digit_ok = contains_between(password, '0', '9');
    bool name_ok = password.find(first_name) == std::string::npos &&
                   password.find(last_name) == std::string::npos;

    return length_ok && upper_ok && lower_ok && digit_ok && name_ok;
}

int main() {
    std::string first_name, last_name, password;
    if (!(std::cin >> first_name >> last_name >> password)) {
        std::cerr << "请输入：名 姓 密码\n";
        return 1;
    }
    std::cout << (check_password(first_name, last_name, password)
                      ? "VALID" : "INVALID") << '\n';
    return 0;
}