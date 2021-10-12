#include "FieldView.h"
#include "iostream"
#include <SFML/Graphics.hpp>
#include <utility>

FieldView::FieldView(Field* field, string pathToTilemap){
    this->field = field;
    this->pathToTilemap = std::move(pathToTilemap);
    InitTextures();
}

map<string, sf::Texture *> FieldView::LoadTextures(const string& TextureFileName, bool versatile) { //TODO:requires destructor
    map<string, sf::Texture *> m;
    sf::Texture *texture[9];
    if(versatile)
    {
        for(int i = 0; i<9;i++) {
            texture[i] = new sf::Texture;
            texture[i]->loadFromFile(pathToTilemap + "\\" + TextureFileName + "_" + BorderCadification[i]);
            m.emplace(BorderCadification[i], texture[i]);
        }

    }
    else
    {
        auto* t = new sf::Texture;
        t->loadFromFile(pathToTilemap + "\\" + TextureFileName);
        for(auto & i : BorderCadification) {
            m.emplace(i, t);
        }
    }
    return m;
}


bool FieldView::InitTextures() {

    textures.emplace(Tile::TERRAIN,  LoadTextures("grass", true));
    textures.emplace(Tile::TERRAIN,  LoadTextures("water"));

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
                sprite.setTexture(*textures.at(field->Tiles[j][i]->GetType()).at("C"), false);
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

