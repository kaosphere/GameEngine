#pragma once
class TextureManager;
class FontManager;
class SystemManager;
class RandomGenerator;

struct SharedContext{
	SharedContext():
		m_textureManager(nullptr),
        m_fontManager(nullptr),
		m_systemManager(nullptr),
        m_rand(nullptr)
	{}

	TextureManager* m_textureManager;
    FontManager* m_fontManager;
	SystemManager* m_systemManager;
	RandomGenerator* m_rand;
};
