#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include "Field.h"
#include "string"
using namespace std;

class FieldView: public sf::Drawable {
    bool LoadTextures(string path_to_folder);
    Field *field;
    enum BorderCadification{TL, T, TR, L, C, R, BL, B, BR};
    std::map<enum Tile::type, std::map<BorderCadification, sf::Texture*>> textures;
public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    FieldView(Field* field, string path_to_tilemap);
    void DrawField();
};
