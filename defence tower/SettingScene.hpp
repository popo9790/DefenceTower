#ifndef SettingScene_hpp
#define SettingScene_hpp
#include <allegro5/allegro_audio.h>
#include <memory>
#include "IScene.hpp"

class SettingScene final : public Engine::IScene {
private:
    std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
public:
    explicit SettingScene() = default;
    void Initialize() override;
    void PlayOnClick(int state);
    void Terminate() override;
    void BGMSlideOnValueChanged(float value);
    void SFXSlideOnValueChanged(float value);
};
#endif /* SettingScene_hpp */
