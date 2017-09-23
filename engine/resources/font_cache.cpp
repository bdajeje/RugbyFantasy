#include "font_cache.hpp"

#include <utils/directory.hpp>

namespace fonts {

std::unique_ptr<FontCache> FontCache::_instance;

void FontCache::init(const std::string& font_directory)
{
  _instance.reset( new FontCache(font_directory) );
}

FontCache::FontCache(const std::string& font_directory)
  : _directory { utils::ensureDirectoryEnd(font_directory) }
{}

FontSP FontCache::get(const std::string& font_file_path)
{
  FontCache& instance = FontCache::instance();

  // Find font
  auto found_it = instance._fonts.find(font_file_path);

  // Found, return it
  if( found_it != instance._fonts.end() )
    return found_it->second;

  // Not already loaded, so load it then return it
  return instance.loadFont(font_file_path);
}

FontSP FontCache::loadFont(const std::string& font_file_path)
{
  // Load font
  auto font = std::make_shared<sf::Font>();
  _fonts.emplace(font_file_path, font);

  if( !font->loadFromFile( _directory + font_file_path ) )
    throw std::invalid_argument {"Can't load font: " + font_file_path};

  return font;
}

}
