#include "Text_and_Number.h"

using namespace std;

TextManager *TextManager::Instance = NULL;

TextManager::TextManager() {}

TextManager *TextManager::Get_Instance()
{
    if(Instance == NULL)
    {
        Instance = new TextManager();
        return Instance;
    }
    return Instance;
}

bool TextManager::add_Font(string Font_Name, string ID, int font_Size)
{
    TTF_Font* Font = TTF_OpenFont(Font_Name.c_str(), font_Size);
    if(Font != NULL)
    {
        m_Font[ID] = Font;
        return true;
    }
    return false;
}

void TextManager::print_Text(string Text, string id, SDL_Color color, int x, int y,
                SDL_Renderer *pRenderer)
{
    SDL_Surface *surface = TTF_RenderText_Blended(m_Font[id],
                                                  Text.c_str(), color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(pRenderer, surface);
    int w = 0, h = 0;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    SDL_Rect size_texture = {x, y, w, h};
    SDL_RenderCopy(pRenderer, texture, NULL, &size_texture);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void TextManager::clearFrom_mFont(string ID)
{
    m_Font.erase(ID);
}
