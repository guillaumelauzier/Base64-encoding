#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Base64 characters
static const std::string base64_chars =
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";

// Encode a string to Base64
std::string base64_encode(const std::string &data) {
  std::string encoded_data;
  int i = 0;
  int j = 0;
  uint8_t buf[3];
  uint8_t b;

  while (i < data.length()) {
    buf[j++] = data[i++];
    if (j == 3) {
      b = (buf[0] & 0xFC) >> 2;
      encoded_data += base64_chars[b];
      b = ((buf[0] & 0x03) << 4) | ((buf[1] & 0xF0) >> 4);
      encoded_data += base64_chars[b];
      b = ((buf[1] & 0x0F) << 2) | ((buf[2] & 0xC0) >> 6);
      encoded_data += base64_chars[b];
      b = buf[2] & 0x3F;
      encoded_data += base64_chars[b];
      j = 0;
    }
  }

  if (j != 0) {
    for (int i = j; i < 3; i++) {
      buf[i] = 0;
    }

    b = (buf[0] & 0xFC) >> 2;
    encoded_data += base64_chars[b];
    b = ((buf[0] & 0x03) << 4) | ((buf[1] & 0xF0) >> 4);
    encoded_data += base64_chars[b];
    if (j == 1) {
      encoded_data += "==";
    } else {
      b = ((buf[1] & 0x0F) << 2) | ((buf[2] & 0xC0) >> 6);
      encoded_data += base64_chars[b];
      encoded_data += "=";
    }
  }

  return encoded_data;
}

int main() {
  std::string data = "Hello, world!";
  std::string encoded_data = base64_encode(data);
  std::cout << "Encoded data: " << encoded_data << std::endl;
  return 0;
}
