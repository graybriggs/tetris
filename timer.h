#pragma once

#include <functional>

class Timer {
public:
	//Timer(void (*func)(), float duration, bool repeated);
	Timer(std::function<void()>, float duration, bool repeated);

	void start_timer();
	void stop_timer();
	void reset_timer();
	void update();

private:
	//void (*func)();
	std::function<void()> func;

	float duration;
	bool repeated;
	bool active;

	float start_time;
	float current_time;
};