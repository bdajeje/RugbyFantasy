#include <iostream>

#include <engine/engine.hpp>
#include <utils/exception.hpp>

int main(int argc, char** argv)
{
  srand(time(NULL));

  try {
    engine::Engine engine(argc, argv);
    return engine.start();
  } catch (const utils::Exception& e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }
}
