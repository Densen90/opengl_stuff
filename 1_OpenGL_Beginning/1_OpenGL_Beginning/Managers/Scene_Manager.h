#pragma once
#include "Shader_Manager.h"
#include "Models_Manager.h"
#include "../Core/Init/IListener.h"

namespace Managers
{
	class Scene_Manager : public Core::IListener
	{
	public:
		Scene_Manager();
		~Scene_Manager();

		virtual void notifyBeginFrame() override;
		virtual void notifyDisplayFrame() override;
		virtual void notifyEndFrame() override;
		virtual void notifyReshape(int width, int height, int previousWidth, int previousHeight) override;
	private:
		Managers::Shader_Manager *shaderManager;
		Managers::Models_Manager *modelsManager;
	};
}
