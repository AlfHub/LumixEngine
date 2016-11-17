#pragma once


#include "editor/studio_app.h"
#include "imgui/imgui.h"


namespace AnimEditor
{


struct Container;
class ControllerResource;


class AnimationEditor : public StudioApp::IPlugin
{
public:
	AnimationEditor(StudioApp& app);
	~AnimationEditor();

	void setContainer(Container* container) { m_container = container; }
	bool isEditorOpened() { return m_editor_opened; }
	void toggleEditorOpened() { m_editor_opened = !m_editor_opened; }
	bool isInputsOpened() { return m_inputs_opened; }
	void toggleInputsOpened() { m_inputs_opened = !m_inputs_opened; }
	void onWindowGUI() override;

private:
	void save();
	void saveAs();
	void drawGraph();
	void load();
	void showEditor();
	void showInputs();
	void showConstants();
	void showAnimSet();

private:
	StudioApp& m_app;
	bool m_editor_opened;
	bool m_inputs_opened;
	ImVec2 m_offset;
	ControllerResource* m_resource;
	Container* m_container;
	char m_path[Lumix::MAX_PATH_LENGTH];
};


}