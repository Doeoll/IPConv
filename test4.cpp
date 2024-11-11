#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>  // 시간을 측정하기 위한 헤더

std::string binaryToDecimalIP(const std::string& binaryStr) {
    if (binaryStr.size() != 32) {
        return "Invalid input: 32-bit binary string required.";
    }

    std::string ipAddress;
    for (int i = 0; i < 4; ++i) {
        int decimalValue = 0;

        // 8비트를 10진수로 변환 (비트 연산을 사용하여 직접 계산)
        for (int j = 0; j < 8; ++j) {
            decimalValue = (decimalValue << 1) | (binaryStr[i * 8 + j] - '0');
        }

        ipAddress += std::to_string(decimalValue);
        if (i < 3) {
            ipAddress += ".";
        }
    }
    return ipAddress;
}

std::vector<std::string> binaryGenerator(int count) {
    std::vector<std::string> binaryStrings;
    //binaryStrings.reserve(count);  // 메모리를 미리 예약하여 재할당 방지
    for (int i = 0; i < count; ++i) {
        std::string binaryStr;
        for (int j = 0; j < 32; ++j) {
            binaryStr += (rand() % 2) ? '1' : '0';
        }
        binaryStrings.push_back(binaryStr);
    }
    return binaryStrings;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // 랜덤 시드 초기화

    // 실행 시간 측정 시작
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<std::string> binaryStrings = binaryGenerator(100000000);

    // 각 이진수를 10진수 IP로 변환하여 출력
    for (const std::string& binaryStr : binaryStrings) {
        std::string ipAddress = binaryToDecimalIP(binaryStr);
        //std::cout << "Binary IP address: " << binaryStr << " -> Decimal IP address: " << ipAddress << std::endl;
    }

    // 실행 시간 측정 종료
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    // 실행 시간 출력
    std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;


    return 0;
}
