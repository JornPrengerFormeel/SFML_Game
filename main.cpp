#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

sf::CircleShape shape; // define shape early so it can be used in border function

bool border(sf::Shape &shape) {
  sf::Vector2f temp = shape.getPosition();
  int x = temp.x + 1;
  int y = temp.y + 1;
  // split position vector into int x and y

  if (x > 1050) {
    shape.setPosition(-49, shape.getPosition().y);
    return false;
  }
  if (x < -50) {
    shape.setPosition(1049, shape.getPosition().y);
    return false;
  }
  if (y > 1050) {
    shape.setPosition(shape.getPosition().x, -49);
    return false;
  }
  if (y < -50) {
    shape.setPosition(shape.getPosition().x, 1049);
    return false;
  }
  return true;
  // if shape reaches border of screen move to other side of screen
}

double movement() {
  double speed = 1;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
    speed = 2;
  }
  // define speed value, when shift is pressed double it
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && border(shape)) {
    shape.move(-speed, 0);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && border(shape)) {
    shape.move(speed, 0);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && border(shape)) {
    shape.move(0, -speed);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && border(shape)) {
    shape.move(0, speed);
  }
  return 0;
  // use wasd input to move x and y of shape
}

int main() {
    sf::SoundBuffer soundBuffer;
    //if (!soundBuffer.loadFromFile("gun.wav"))
    //    return -1;
    sf::Sound sound;
    sound.setBuffer(soundBuffer);

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "My window");
    window.setKeyRepeatEnabled(false); 
    sf::Vertex line[2];
    sf::VertexArray lines(sf::LineStrip, 2);

    shape.setRadius(50);
    shape.setOrigin(50, 50);
    shape.setFillColor(sf::Color(150, 250, 150));
    shape.setOutlineThickness(5);
    shape.setOutlineColor(sf::Color(150, 100, 200));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
    lines[0].position = sf::Vector2f(shape.getPosition().x, shape.getPosition().y);
    lines[1].position = sf::Vector2f(sf::Mouse::getPosition(window));
    lines[0].color = sf::Color::Blue;
    lines[1].color = sf::Color::Blue;
    // set line position and default color

    movement();

    window.clear(sf::Color(60, 60, 60));

    if (event.type == sf::Event::MouseButtonPressed)
    {
            sound.play();
            lines[0].color = sf::Color::Red;
            lines[1].color = sf::Color::Red;
    }
    // when mouse pressed change line color and play sound
    window.draw(lines);
    window.draw(shape);
    window.display();
    }

    return 0;
}
