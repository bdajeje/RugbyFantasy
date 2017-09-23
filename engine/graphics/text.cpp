#include "text.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

namespace engine {

TextProperties::TextProperties(std::string font_name, int size, sf::Color color)
  : font {fonts::FontCache::get(font_name)}
  , color {color}
  , size {size}
{
}

Text::Text(const sf::String& string, const TextProperties& properties)
  : _text(std::make_shared<sf::Text>(string, *properties.font, properties.size))
{
  _text->setColor(properties.color);
}

void Text::internalDraw(sf::RenderTarget& target, sf::RenderStates states) const noexcept
{
  target.draw(*_text, states);
}

TextSP getText(const std::string& text_content, const TextProperties& properties)
{
  return std::make_shared<Text>(text_content, properties);
}

}
