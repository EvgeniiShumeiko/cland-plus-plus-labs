#include <fstream>
#include <iostream>
#include <string>

void xor_cipher_file(const std::string& in_name, const std::string& out_name, const std::string& key) {
    std::ifstream in(in_name, std::ios::binary);
    std::ofstream out(out_name, std::ios::binary);
    if (!in || !out || key.empty()) return;

    char ch;
    std::size_t i = 0;
    while (in.get(ch)) {
        ch = static_cast<char>(ch ^ key[i % key.size()]);
        out.put(ch);
        ++i;
    }
}

int main() {
    const std::string key = "secret";
    xor_cipher_file("cipher_input.txt", "cipher_encoded.bin", key);
    xor_cipher_file("cipher_encoded.bin", "cipher_decoded.txt", key);
    std::cout << "Созданы файлы cipher_encoded.bin и cipher_decoded.txt\n";
    return 0;
}

