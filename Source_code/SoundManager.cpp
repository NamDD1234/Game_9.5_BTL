#include "SoundManager.h"

using namespace std;

SoundManager *SoundManager::Instance = NULL;

SoundManager::SoundManager()
{
     Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
}

SoundManager* SoundManager::Get_Instance()
{
    if(Instance == NULL)
    {
        Instance = new SoundManager();
        return Instance;
    }
    return Instance;
}

bool SoundManager::load(string Sound_Name, string ID)
{
    Mix_Chunk* music_file = Mix_LoadWAV(Sound_Name.c_str());
    if(music_file != NULL)
    {
        m_Sound[ID] = music_file;
        return true;
    }
    return false;
}

void SoundManager::playSound(string ID, int loop)
{
    Mix_PlayChannel(-1, m_Sound[ID], loop);
}

void SoundManager::delSound(string ID)
{
    m_Sound.erase(ID);
}
