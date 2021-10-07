#include "FieldView.h"
#include "Field.h"
#include "iostream"
FieldView::FieldView(Field* field, string path_to_tilemap){
    this->field = field;
}

void FieldView::DrawField(){
    for(int i = 0; i < field->width; i++)
    {
        for(int j = 0; j < field->height; j++)
        {
            std::cout << ((field->Tiles[i][j]->getType() == TERRAIN) ? "# " : "~ ");
        }
        std::cout<<std::endl;
    }
}
