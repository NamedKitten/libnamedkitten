#include <string>
#include "conversions.hpp"


std::string NamedKitten::conversions::time_diff(uint64_t times) {
  std::string a = "";
  uint64_t t;
  uint64_t current_time = time(nullptr);
  t = current_time - times;

  uint64_t years = t / 31536000;
  uint64_t days = (t / 86400) % 365;
  uint64_t hours = (t / 3600) % 24;
  uint64_t minutes = (t / 60) % 60;
  uint64_t seconds = (t) % 60;

  if (!years && !days && !hours && !minutes)
    return std::to_string(seconds) + " " +
           (seconds != 1 ? "seconds" : "second") + " ago";
  else {
    bool need_comma = false;
    if (years) {
      a = std::to_string(years) + " " + (years != 1 ? "years" : "year");
      need_comma = true;
    }
    if (days) {
      a += need_comma ? ", " : "";
      a += std::to_string(days) + " " + (days != 1 ? "days" : "day");
      need_comma = true;
    }
    if (hours) {
      a += need_comma ? ", " : "";
      a += std::to_string(hours) + " " + (hours != 1 ? "hours" : "hour");
      need_comma = true;
    }
    if (minutes) {
      a += need_comma ? ", " : "";
      a += std::to_string(minutes) + " " + (minutes != 1 ? "minutes" : "minute");
    }
    return a + " ago";
  }
}

uint64_t NamedKitten::conversions::timestamp_to_unix(std::string timestamp) {
  timestamp.erase(timestamp.length()-13);
  struct tm t;
  strptime(timestamp.c_str(), "%FT%T", &t);
  uint64_t times = mktime(&t) - 3600;
  return times;
}

uint64_t NamedKitten::conversions::snowflake_to_unix(uint64_t snowflake) {
  uint64_t unix_time = (((snowflake >> 22) + 1420070400000) / 1000);
  return unix_time;
}
