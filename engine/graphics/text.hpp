#ifndef TEXT_HPP
#define TEXT_HPP

#include <memory>

#include <SFML/Graphics/Text.hpp>

#include <engine/drawable.hpp>
#include <engine/resources/font_cache.hpp>

namespace engine {

struct TextProperties
{
  TextProperties(std::string font_name, int size = 30, sf::Color color = sf::Color::Black);

  fonts::FontSP font;
  sf::Color color;
  int size;
};

class Text final : public Drawable
{
  public:

    Text(const sf::String& string, const TextProperties& properties);

    void setString(const sf::String& string) { _text->setString(string); }
    virtual void setColor(const sf::Color& color) { _text->setColor(color); }
    void setCharacterSize(unsigned int size) { _text->setCharacterSize(size); }
    void setFont(const sf::Font& font) { _text->setFont(font); }
    virtual void setPosition(sf::Vector2f pos) override { _text->setPosition(pos); }
    virtual void move(float x, float y) override { _text->move(x, y); }

    const sf::String& getString() const { return _text->getString(); }
    virtual sf::Vector2f getSize() const noexcept override { return {_text->getLocalBounds().width, _text->getLocalBounds().height}; }
    virtual const sf::Vector2f& getPosition() const noexcept override { return _text->getPosition(); }

  protected:

    void internalDraw(sf::RenderTarget& target, sf::RenderStates states) const noexcept override;

  private:

    std::shared_ptr<sf::Text> _text;
};

using TextSP = std::shared_ptr<Text>;

TextSP getText(const std::string& text_content, const TextProperties& properties);

}

#endif // TEXT_HPP
