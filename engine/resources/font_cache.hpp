#ifndef FONT_CACHE_HPP
#define FONT_CACHE_HPP

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include <map>
#include <memory>

namespace fonts {

using FontSP = std::shared_ptr<sf::Font>;

class FontCache final
{
  public:

    static void init(const std::string& font_directory);
    static FontCache& instance() { return *_instance; }
    static FontSP get(const std::string& font_file_path);

  private:

    FontCache(const std::string& font_directory);
    FontSP loadFont(const std::string& font_name);

  private:

    static std::unique_ptr<FontCache> _instance;

    /* Directory when to find resources */
    const std::string _directory;

    /* Cached textures */
    std::map<std::string, FontSP> _fonts;
};

}

#endif // FONT_CACHE_HPP
