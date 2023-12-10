// main.cpp
// Sun 10 Dec 06:24:49 UTC 2023

// zeroing in on the issue 06:25z

#include <Arduino.h>
#include <iostream>
#include <memory>
#include <string>

template <typename... Args>
std::string format_string(const std::string &format, Args... args) {
  int size_s = std::snprintf(nullptr, 0, format.c_str(), args...) +
               1; // Extra space for '\0'
  if (size_s <= 0) {
    std::cout << "Error during formatting.";
    return "";
  }
  auto size = static_cast<size_t>(size_s);
  std::unique_ptr<char[]> buf(new char[size]);
  std::snprintf(buf.get(), size, format.c_str(), args...);
  return std::string(buf.get(),
                     buf.get() + size - 1); // We don't want the '\0' inside
}

// Example of using above function
// to format a series of strings as a singular
// json formatted string.

#if 0
std::string json =
  format_string("\"device_config\": {\"OTALogin\": \"%s\", \"OTAPassword\": "
                "\"%s\", \"OTAPort\": \"%u\"}, this->OTALogin.c_str(), "
                "this->OTAPassword.c_str(), this->OTAPort");
// return json;
#endif

void slower() {
    for (volatile unsigned long c = 1239999; c > 0; c--) { }
}

void setup(){
    Serial.begin(115200);
    Serial.print("hi   ");
    Serial.println(" chupacabra keerflar teldu naknuk");
};

void loop(){
    Serial.write('¶'); // fancy that
    slower();
};

// as hiked off github moments ago commit 10ba62d
// end.
