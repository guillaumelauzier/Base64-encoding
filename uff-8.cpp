#include <iostream>
#include <string>
#include <vector>

int main() {
  // Convert text to binary data using UTF-8 encoding
  std::string text = "Hello, world!";
  std::vector<uint8_t> binary_data(text.begin(), text.end());

  // Output the binary data
  for (const auto &byte : binary_data) {
    std::cout << std::hex << static_cast<int>(byte) << " ";
  }
  std::cout << std::endl;

  return 0;
}
