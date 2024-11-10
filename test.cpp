#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()

std::string binaryToDecimalIP(const std::string& binaryStr) {
    if (binaryStr.size() != 32) {
        return "Invalid input: 32-bit binary string required.";
    }

    std::string ipAddress;

    // 8비트씩 잘라서 처리
    for (int i = 0; i < 4; ++i) {
        std::string octet = binaryStr.substr(i * 8, 8);  // i번째 8비트 부분 추출
        int decimalValue = std::bitset<8>(octet).to_ulong();  // 2진수를 10진수로 변환
        ipAddress += std::to_string(decimalValue);  // 10진수로 변환된 값을 문자열로 변환하여 추가

        if (i < 3) {
            ipAddress += ".";  // 마지막 옥텟이 아니면 점(.) 추가
        }
    }

    return ipAddress;
}

std::vector<std::string> binaryGenerator(int count) {
    std::vector<std::string> binaryStrings;
    for (int i = 0; i < count; ++i) {
        std::string binaryStr;
        for (int j = 0; j < 32; ++j) {
            // rand() % 2로 0 또는 1을 랜덤하게 생성하여 추가
            binaryStr += (rand() % 2) ? '1' : '0';
        }
        binaryStrings.push_back(binaryStr);
    }
    return binaryStrings;
}

int main() {
    // 랜덤 시드 초기화
    srand(static_cast<unsigned int>(time(0)));

    // 32비트 이진수 10,000개 생성
    std::vector<std::string> binaryStrings = binaryGenerator(10000);

    // 각 이진수를 10진수 IP로 변환하여 출력
    for (const std::string& binaryStr : binaryStrings) {
        std::string ipAddress = binaryToDecimalIP(binaryStr);
        std::cout << "Binary IP address: " << binaryStr << " -> Decimal IP address: " << ipAddress << std::endl;
    }

    return 0;
}
