#include "GameEngine.hpp"
#include "ImageButton.hpp"
#include "Label.hpp"
#include "Point.hpp"
#include "Slider.hpp"
#include "AudioHelper.hpp"
#include "Resources.hpp"

#include "SettingScene.hpp"
#include "StageSelectScene.hpp"

void SettingScene::Initialize(){
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::ImageButton* btn;

    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 200, halfH + 250 , 400, 100);
    btn->SetOnClickCallback(std::bind(&SettingScene::PlayOnClick, this, 1));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Go Back", "pirulen.ttf", 48, halfW, halfH + 300 , 0, 0, 0, 255, 0.5, 0.5));
    
    Slider *sliderBGM, *sliderSFX;
    
    sliderBGM = new Slider(40 + halfW - 95, halfH - 50 - 2, 190, 4);
    sliderBGM->SetOnValueChangedCallback(std::bind(&SettingScene::BGMSlideOnValueChanged, this, std::placeholders::_1));
    AddNewControlObject(sliderBGM);
    AddNewObject(new Engine::Label("BGM: ", "pirulen.ttf", 28, 40 + halfW - 60 - 95, halfH - 50, 255, 255, 255, 255, 0.5, 0.5));
    
    sliderSFX = new Slider(40 + halfW - 95, halfH + 50 - 2, 190, 4);
    sliderSFX->SetOnValueChangedCallback(std::bind(&SettingScene::SFXSlideOnValueChanged, this, std::placeholders::_1));
    AddNewControlObject(sliderSFX);
    AddNewObject(new Engine::Label("SFX: ", "pirulen.ttf", 28, 40 + halfW - 60 - 95, halfH + 50, 255, 255, 255, 255, 0.5, 0.5));
    
    // Not safe if release resource while playing, however we only free while change scene, so it's fine.
    bgmInstance = AudioHelper::PlaySample("select.ogg", true, AudioHelper::BGMVolume);
    sliderBGM->SetValue(AudioHelper::BGMVolume);
    sliderSFX->SetValue(AudioHelper::SFXVolume);
}
void SettingScene::Terminate(){
    AudioHelper::StopSample(bgmInstance);
    bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
    IScene::Terminate();
}

void SettingScene::PlayOnClick(int state){
    Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}

void SettingScene::BGMSlideOnValueChanged(float value){
    AudioHelper::ChangeSampleVolume(bgmInstance, value);
    AudioHelper::BGMVolume = value;
}

void SettingScene::SFXSlideOnValueChanged(float value){
    AudioHelper::SFXVolume = value;
}
