#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <map>

#include "Field.h"
#include "string"
using namespace std;
class FieldView: public sf::Drawable {
    bool LoadTextures(string path_to_folder); //TODO: create all logic for drawing
    Field *field;
    std::map<type, sf::Texture> textures;
public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    FieldView(Field* field, string path_to_tilemap);
    void DrawField();
};
