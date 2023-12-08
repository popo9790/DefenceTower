#include <algorithm>
#include <string>

#include "Point.hpp"
#include "Slider.hpp"

Slider::Slider(float x, float y, float w, float h) :
	ImageButton("stage-select/slider.png", "stage-select/slider-blue.png", x, y),
	Bar("stage-select/bar.png", x, y, w, h),
	End1("stage-select/end.png", x, y + h / 2, 0, 0, 0.5, 0.5),
	End2("stage-select/end.png", x + w, y + h / 2, 0, 0, 0.5, 0.5) {
	Position.x += w;
	Position.y += h / 2;
	Anchor = Engine::Point(0.5, 0.5);
}
void Slider::Draw() const {
    Bar.Draw();
    End1.Draw();
    End2.Draw();
    ImageButton::Draw();
}
void Slider::SetOnValueChangedCallback(std::function<void(float value)> onValueChangedCallback) {
    OnValueChangedCallback = onValueChangedCallback;
}
void Slider::SetValue(float value) {
	// TODO 1 (4/7): Call 'OnValueChangedCallback' when value changed. Can imitate ImageButton's 'OnClickCallback'.
	// Also, move the slider along the bar, to the corresponding position.
    this->value = value;
    Position.x  = End1.Position.x + (End2.Position.x - End1.Position.x) * value / 5.0;
    if(OnValueChangedCallback)
        OnValueChangedCallback(value);
}

void Slider::OnMouseDown(int button, int mx, int my) { //fixed
	// TODO 1 (5/7): Set 'Down' to true if mouse is in the slider.
    if(Position.x - Size.x / 2 <= mx && mx <= Position.x + Size.x / 2 &&
       Position.y - Size.y / 2  <= my && my <= Position.y + Size.y)
        Down = true;
}

void Slider::OnMouseUp(int button, int mx, int my) {
    // TODO 1 (6/7): Set 'Down' to false.
    Down = false;
}

void Slider::OnMouseMove(int mx, int my) {
	// TODO 1 (7/7): Clamp the coordinates and calculate the value. Call 'SetValue' when you're done.
    if(Down){
        float value_tmp = (mx - End1.Position.x) / 40.0;
        if(value_tmp >= 5)
            value_tmp = 5;
        if(value_tmp <= 0)
            value_tmp = 0;
        SetValue(value_tmp);
    }
}
