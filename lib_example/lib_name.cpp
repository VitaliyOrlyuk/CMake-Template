#include <stdexcept>

float division(int a, int b) {
  if (b == 0) throw std::logic_error("Input Error: can't divide by zero!");
  return (float)a / b;
}
