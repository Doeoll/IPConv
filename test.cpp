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

    // 8��Ʈ�� �߶� ó��
    for (int i = 0; i < 4; ++i) {
        std::string octet = binaryStr.substr(i * 8, 8);  // i��° 8��Ʈ �κ� ����
        int decimalValue = std::bitset<8>(octet).to_ulong();  // 2������ 10������ ��ȯ
        ipAddress += std::to_string(decimalValue);  // 10������ ��ȯ�� ���� ���ڿ��� ��ȯ�Ͽ� �߰�

        if (i < 3) {
            ipAddress += ".";  // ������ ������ �ƴϸ� ��(.) �߰�
        }
    }

    return ipAddress;
}

std::vector<std::string> binaryGenerator(int count) {
    std::vector<std::string> binaryStrings;
    for (int i = 0; i < count; ++i) {
        std::string binaryStr;
        for (int j = 0; j < 32; ++j) {
            // rand() % 2�� 0 �Ǵ� 1�� �����ϰ� �����Ͽ� �߰�
            binaryStr += (rand() % 2) ? '1' : '0';
        }
        binaryStrings.push_back(binaryStr);
    }
    return binaryStrings;
}

int main() {
    // ���� �õ� �ʱ�ȭ
    srand(static_cast<unsigned int>(time(0)));

    // 32��Ʈ ������ 10,000�� ����
    std::vector<std::string> binaryStrings = binaryGenerator(10000);

    // �� �������� 10���� IP�� ��ȯ�Ͽ� ���
    for (const std::string& binaryStr : binaryStrings) {
        std::string ipAddress = binaryToDecimalIP(binaryStr);
        std::cout << "Binary IP address: " << binaryStr << " -> Decimal IP address: " << ipAddress << std::endl;
    }

    return 0;
}
