#include <cassert>
#include <iostream>
namespace nan {
    bool toInt(char c, int &theInt) {
        if (c >= '0' && c <= '9') {
            theInt = c - '0';// ASCII code of 0 = 48
            return true;
        }
        return false;
    }

    void runTestsToInt() {
        int number = -1;
        toInt('0', number);
        assert(number == 0);
        number = -1;
        toInt('9', number);
        assert(number == 9);
        number = -1;
        toInt('x', number);
        assert(number == -1);
        std::cout << "All toInt() tests passed successfully!" << std::endl;
    }

    int decode(const std::string &line) {
        int first = -1;
        int last = -1;
        int current_int;

        for (char c: line) {
            if (toInt(c, current_int)) {
                if (first == -1) {
                    first = current_int;
                }
                last = current_int;
            }
        }
        if (first == -1 || last == -1)
            throw std::invalid_argument("no digits in the input");
        return first * 10 + last;
    }


    void runTestsDecode() {
        std::string lines[] = {
            "1abc2",
            "pqr3stu8vwx",
            "a1b2c3d4e5f",
            "treb7uchet"};
        int expected[]{12, 38, 15, 77};
        for (int i = 0; i < 4; ++i) {
            assert(decode(lines[i]) == expected[i]);
        }
        try {
            decode("no digit");
            assert(false);
        } catch (std::invalid_argument &e) {
            std::cout << std::string(e.what()) << std::endl;
        }
        std::cout << "All decode() tests passed successfully!" << std::endl;
    }
}
    int main() {
        nan::runTestsToInt();
        nan::runTestsDecode();
        return 0;
    }
