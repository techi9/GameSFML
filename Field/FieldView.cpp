#include "FieldView.h"
#include "Field.h"
#include "iostream"
#include <SFML/Graphics.hpp>

FieldView::FieldView(Field* field, string path_to_tilemap){
    this->field = field;
    LoadTextures(path_to_tilemap);
}

bool FieldView::LoadTextures(string path_to_folder)
{
    textures.clear();
    sf::Texture* texture = new sf::Texture;
    (*texture).loadFromFile(path_to_folder+"\\"+"grass_c.png");
    textures.emplace(TERRAIN, *texture);

    (*texture).loadFromFile(path_to_folder+"\\"+"water.png");
    textures.emplace(WATER, *texture);
}

void FieldView::DrawField(){
    for(int i = 0; i < field->width; i++)
    {
        for(int j = 0; j < field->height; j++)
        {
            if (field->Tiles[i][j]->content)
                std::cout << field->Tiles[i][j]->content->Render();
            else
                std::cout << ((field->Tiles[i][j]->GetType() == TERRAIN) ? "# " : "~ ");
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
                sprite.setTexture(textures.at(field->Tiles[i][j]->GetType()), false);
                sprite.move(i*sprite.getLocalBounds().width, j*sprite.getLocalBounds().height);
                target.draw(sprite);
            }
            catch(std::exception)
            {
                std::cerr << "Texture for " << field->Tiles[i][j]->GetType() << " not found." << std::endl;
            }
        }
    }
}