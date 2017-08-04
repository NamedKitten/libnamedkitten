#include <string>

namespace NamedKitten {
  namespace conversions {
      uint64_t snowflake_to_unix(uint64_t snowflake);
      uint64_t timestamp_to_unix(std::string timestamp);
      std::string time_diff(uint64_t times);
  }
}
