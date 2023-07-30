

#include <SDL.h>

#include "timer.h"

Timer::Timer(void (*func)(), float duration, bool repeated) :
	func(func), duration(duration), repeated(repeated),
	active(false),
	start_time(0),
	current_time(0)
{
}


void Timer::start_timer() {

	start_time = SDL_GetTicks();
	active = true;
}

void Timer::stop_timer() {
	active = false;
}

void Timer::reset_timer() {
	start_timer();
}

void Timer::update() {
	current_time = SDL_GetTicks();

	if (active) {
		if (current_time - start_time > duration) {
			// do something (function pointer?)
			func();

			if (repeated) {
				reset_timer();
			}
			else {
				stop_timer();
			}
		}
	}
}