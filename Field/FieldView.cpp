#include "FieldView.h"
#include "iostream"
#include <SFML/Graphics.hpp>

FieldView::FieldView(Field* field, string path_to_tilemap){
    this->field = field;
    LoadTextures(path_to_tilemap);
}

bool FieldView::LoadTextures(string path_to_folder)
{
    sf::Texture *texture;
    texture->loadFromFile(path_to_folder+"\\"+"grass_c.png");
    std::map<BorderCadification, sf::Texture*> PairsOfTerrain;
    PairsOfTerrain.emplace(FieldView::C, texture);
    textures.emplace(Tile::TERRAIN,  PairsOfTerrain);

    (*texture).loadFromFile(path_to_folder+"\\"+"water.png");
    textures.emplace(Tile::WATER, *texture);
}

void FieldView::DrawField(){
    for(int j = 0; j < field->height; j++)
    {
        for(int i = 0; i < field->width; i++)
        {
            if (field->Tiles[i][j]->content)
                std::cout << field->Tiles[i][j]->content->Render();
            else
                std::cout << ((field->Tiles[i][j]->GetType() == Tile::TERRAIN) ? "# " : "~ ");
        }
        std::cout<<std::endl;
    }
}

void FieldView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (int i=0; i<this->field->height; i++)
    {
        for (int j=0; j<this->field->width; j++)
        {
            try {
                sf::Sprite sprite;
                sprite.setTexture(textures.at(field->Tiles[j][i]->GetType()), false);
                sprite.move(j*sprite.getLocalBounds().width, i*sprite.getLocalBounds().height);
                target.draw(sprite);
            }
            catch(std::exception)
            {
                std::cerr << "Texture for " << field->Tiles[j][i]->GetType() << " not found." << std::endl;
            }
        }
    }
}