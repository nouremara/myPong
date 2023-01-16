/** The game scene abstraction for the application.

	This is the abstraction for all game scenes used within this Pong game.
	This pure class acts as an interface for all scenes and requires them
	to implement functions that are used in the root Game instance.
 */
#ifndef MYPONG_SCENE_H
#define MYPONG_SCENE_H

#include <memory>

struct SDL_KeyboardEvent;
struct SDL_Renderer;

namespace myPong
{
	class Scene
	{
	public:
		virtual void onDraw(SDL_Renderer& renderer) = 0;
		virtual void onUpdate() = 0;
		virtual void onEnter() = 0;
		virtual void onExit() = 0;
		virtual void onKeyDown(SDL_KeyboardEvent& event) = 0;
		virtual void onKeyUp(SDL_KeyboardEvent& event) = 0;
		virtual void onTextInpt(std::string &text) = 0;

		/**
		 * @brief handle mouse click events
		 * 
		 * @param buttonID which button is clicked (left, right, ...)
		 * @param mouseX   x-coordinate of the mouse when clicked
		 * @param mouseY   y-coordinate of the mouse when clicked
		 */
		virtual void onMouseClick(int buttonID, int mouseX, int mouseY) = 0;
	};
	typedef std::shared_ptr<Scene> ScenePtr;
}

#endif