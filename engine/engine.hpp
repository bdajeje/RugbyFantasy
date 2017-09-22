#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <vector>

#include <engine/models/scene.hpp>

namespace engine {

class Engine final
{
  public:

    Engine(int argc, char** argv);
    int start();

  private:

    std::vector<model::SceneSP> _scenes;
};

}

#endif // ENGINE_HPP
