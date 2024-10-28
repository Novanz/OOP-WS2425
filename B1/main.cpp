#include <cassert>
#include <iostream>

int altChecksum(int input) {
    if (input <0) {
        throw std::invalid_argument("Input should be positive");
    }
    int result = 0;
    int sign = 1;
    int divisor = 1;// 10er exp

    int temp = input;
    while (temp >= 10) {
        temp /= 10;
        divisor *= 10;
    }
    while (divisor > 0) {
        result += (input / divisor) % 10 * sign;
        sign *= -1;
        divisor /= 10;
    }
    return result;
}

void runTestsAltChecksum() {
    assert(altChecksum(471) == -2);
    try {
        altChecksum(-471);
    } catch (std::invalid_argument &e) {
        assert(std::string(e.what()) == "Input should be positive");
    }
    assert(altChecksum(4711) == -3);
    assert(altChecksum(1) == 1);
    assert(altChecksum(10) == 1);
    assert(altChecksum(123456) == -3);
    assert(altChecksum(987654320) == 4);
    assert(altChecksum(18446466) == -5);

    std::cout << "All  altChecksum() tests passed successful!\n";
}

bool toInt(char c, int *theInt) {
    if (theInt == nullptr) {
        return false;
    }

    if (c >= '0' && c <= '9') {
        *theInt = c - '0'; // ASCII code of 0 = 48
        return true;
    }
    return false;
}

void runTestsToInt() {
    int result = 0;
    // Test valid digits
    for (char c = '0'; c <= '9'; c++) {
        assert(toInt(c, &result) == true);
        assert(result == (c - '0'));
    }

    // Test non-digit characters
    assert(toInt('a', &result) == false);
    assert(toInt('Z', &result) == false);
    assert(toInt(',', &result) == false);
    assert(toInt('$', &result) == false);

    // Test null pointer
    assert(toInt('5', nullptr) == false);

    std::cout << "All toInt() tests passed successfully!" << std::endl;
}

int decode(const char *line) {
    int first = -1;
    int last = -1;
    int temp;

    for (; *line != '\0'; line++) {
        if (toInt(*line, &temp)) {
            if (first == -1) {
                first = temp;
            }
            last = temp;
        }
    }
    if (first == -1 || last == -1)
        return -1;
    return first * 10 + last;
}

void runTestsDecode() {
    assert(decode("1xyz2") == 12);
    assert(decode("abc3pqr8ijk") == 38);
    assert(decode("x1y2z3v4w5q") == 15);
    assert(decode("hello7world") == 77);
    assert(decode("nodigits") == -1);
    assert(decode("") == -1);
    assert(decode("9") == 99);
    assert(decode("a1b2c3d4e5f") == 15);
    std::cout << "All decode() tests passed successfully!" << std::endl;
}

int main() {
    //std::cout<< altChecksum(-471)<< std::endl;
    runTestsAltChecksum();
    runTestsToInt();
    runTestsDecode();
    return 0;
}