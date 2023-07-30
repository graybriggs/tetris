#pragma once


class Timer {
public:
	Timer(void (*func)(), float duration, bool repeated);

	void start_timer();
	void stop_timer();
	void reset_timer();
	void update();

private:
	void (*func)();

	float duration;
	bool repeated;
	bool active;

	float start_time;
	float current_time;
};