#include <vector>
#include <string>
#include <iostream>

#include <zip.h>

#include "tiles.h"
#include "json.h"


Tileset::Tileset(int width, int height){
    this->width = width;
    this->height = height;
}

Tileset::Tileset(std::string filename){
    this->filename = filename;
    zip *content = zip_open(filename.c_str(), 0, NULL);
    const char* name = "docData.json";
    struct zip_stat st;
    zip_stat_init(&st);
    zip_stat(content, name, 0, &st);
    
    char* contents = new char[st.size];
    zip_file *description = zip_fopen(content, name, 0);
    zip_fread(description, contents, st.size);
    zip_fclose(description);
    
    json data (contents);
    json palette;
    json colors;

    std::vector<json>::iterator iter;
    for (iter = data.getContents().begin(); iter != data.getContents().end(); iter++){
        std::cout << (*iter).getKey() << std::endl;
        if ((*iter).getKey() == "palette"){
            palette = *iter;
        }
    }
    for (iter = palette.getContents().begin(); iter != palette.getContents().end(); iter++){
        if ((*iter).getKey() == "colors"){
            colors = *iter;
        }
    }
    
    for (iter = colors.getContents().begin(); iter != colors.getContents().end(); iter++){
        this->palette.push_back(std::stoi((*iter).getValue(), nullptr, 16));
    }

    zip_close(content);
}
