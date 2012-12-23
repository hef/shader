#ifndef SDLINPUT_H
#define SDLINPUT_H
#include <functional>
#include <vector>

class SDLInput
{
public:
	SDLInput();
	bool init();
	bool shutdown();
	bool handleInput();
	void onExit( std::function<void(void)> const& exit );
private:
	std::vector<std::function<void(void)>> exits;
};
#endif // SDLINPUT_H
