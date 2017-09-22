#include "textures_cache.hpp"

#include <utils/directory.hpp>

namespace textures {

std::unique_ptr<TexturesCache> TexturesCache::_instance;

void TexturesCache::init(const std::string& image_directory)
{
  if( _instance )
    return;

  _instance.reset( new TexturesCache(image_directory) );
}

TexturesCache::TexturesCache(const std::string& image_directory)
  : _directory { utils::ensureDirectoryEnd(image_directory) }
{}

const sf::Texture& TexturesCache::get(const std::string& texture_file_path)
{
  // Find texture
  auto found_it = _instance->_textures.find(texture_file_path);

  // Found, return it
  if( found_it != _instance->_textures.end() )
    return found_it->second;

  // Not already loaded, so load it then return it
  return _instance->loadTexture(texture_file_path);
}

const sf::Texture& TexturesCache::loadTexture(const std::string& texture_file_path)
{
  // Load texture
  sf::Texture& texture = _textures[texture_file_path];
  if( !texture.loadFromFile( _directory + texture_file_path ) )
    throw std::invalid_argument {"Can't load texture: " + texture_file_path};

  return texture;
}

} // texture
