#include "TextureManager.h"

using namespace std;

TextureManager* TextureManager::Instance = NULL;

TextureManager:: TextureManager() {}
TextureManager* TextureManager::get_Instance()
{
    if(Instance == NULL)
    {
        Instance = new TextureManager();
        return Instance;
    }
    return Instance;
}

bool TextureManager::load(string fileName, string
                          id, SDL_Renderer* pRenderer)
{
    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
    if(pTempSurface == 0)
    {
        return false;
    }
    SDL_Texture* pTexture =
        SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);
    if(pTexture != 0)
    {
        m_textureMap[id] = pTexture;
        return true;
    }
    return false;
}

void TextureManager::draw(string id, int x, int y, int
                          width, int height, SDL_Renderer* pRenderer,
                          int type_flip, double ti_le)
{
    SDL_RendererFlip flip = (type_flip>0)?SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = width;
    destRect.w = (int)(width /ti_le);
    srcRect.h = height;
    destRect.h = (int)(height / ti_le);
    destRect.x = x;
    destRect.y = y;
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect,
                     &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(string id, int x, int y, int
                               width, int height, int currentRow, int currentFrame, SDL_Renderer
                               *pRenderer, int type_flip, double ti_le)
{
    SDL_RendererFlip flip = (type_flip>0)?SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);
    srcRect.w = width;
    destRect.w = (int)(width /ti_le);
    srcRect.h = height;
    destRect.h = (int)(height / ti_le);
    destRect.x = x;
    destRect.y = y;
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect,
                     &destRect, 0, 0, flip);
}
void TextureManager::clearFromTextureMap(string id)
{
    m_textureMap.erase(id);
}
