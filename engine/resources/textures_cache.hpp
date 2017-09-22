#ifndef ENGINE_TEXTURES_CACHE_HPP
#define ENGINE_TEXTURES_CACHE_HPP

#include <SFML/Graphics/Texture.hpp>

#include <map>
#include <memory>

namespace textures {

class TexturesCache final
{
  public:

    static void init(const std::string& image_directory);   
    static const sf::Texture& get(const std::string& texture_file_path);

  private:

    TexturesCache(const std::string& image_directory);
    const sf::Texture& loadTexture(const std::string& texture);

  private:

    static std::unique_ptr<TexturesCache> _instance;

    /* Directory when to find resources */
    const std::string _directory;

    /* Cached textures */
    std::map<std::string, sf::Texture> _textures;
};

} // texture

#endif // MANAGERS_TEXTURE_MANAGER_HPP
