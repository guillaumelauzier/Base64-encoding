#include <bitcoin/bitcoin.hpp>

int main() {
  // Encode the data
  std::string data = "Hello, world!";
  std::string encoded_data = bc::encode_base16(bc::to_chunk(data));

  // Create a script with the encoded data
  bc::data_chunk script_data(encoded_data.begin(), encoded_data.end());
  bc::script script = bc::script(bc::machine::opcode::return_, script_data);

  // Create a transaction output with the script
  bc::transaction_output output(0, script);

  // Output the transaction output
  std::cout << output.to_data(true) << std::endl;
}
