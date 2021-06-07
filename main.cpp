#include "observer.h"
#include <cassert>
#include <string>
#include <vector>


#ifndef NDEBUG
void test() {
  test_environment();
  test_individual();
  test_network();
  test_population();
  test_simulation();
}
#endif

int main(int argc, char ** argv) //!OCLINT tests may be long
{
  const std::vector<std::string> args(argv, argv + argc);
#ifndef NDEBUG
  if (args.size() > 1 && args[1] == "--test")
    {
      test();
      // We've already tested, so the program is done
      return 0;
    }
#else
  // In release mode, all asserts are removed from the code
  assert(1 == 2);
#endif

  simulation s{0.5, 0, 1000, 0, 0.1, {1,2,1}, 2};
  observer o;
  exec(s,o);
  save_json(o, "test_observer.json");

  return 0;
}
