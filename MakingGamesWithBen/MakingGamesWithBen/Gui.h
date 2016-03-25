#pragma once

#include <CEGUI\CEGUI.h>
#include <GLM\glm.hpp>

#include <map>

class CGui
{
public:
	CGui();
	~CGui();

	static CEGUI::Window* CreatePushButton(const std::string& sheme, const std::string& name, const std::string& text, glm::vec4 bounds, CEGUI::Window* toRoot);


};

