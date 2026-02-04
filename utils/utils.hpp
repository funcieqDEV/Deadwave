#include <cstdlib>
#include <ctime>

namespace util {
inline int random(int min, int max) { return rand() % (max - min + 1) + min; }
} // namespace util
