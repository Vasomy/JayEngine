#pragma once

#ifndef IMGUI_INCLUDE
#define IMGUI_INCLUDE
#include"imgui\imgui.h"
#include"imgui\backends\imgui_impl_glfw.h"
#include"imgui\backends\imgui_impl_opengl3.h"
#include"imgui\imfilebrowser.h"
#include"ImGuizmo\ImGuizmo.h"

#include"Math\Math.h"
// 封装drawcall ，初始化，退出时清除资源的功能
class FImGuiContextProxy
{
public:
	static void Init();
	static void Draw();
	static void Exit();

	static void Begin();
	static void End();

	static void Vector3Controller(const char* label, FVector3& value, float reset_value = 0.0f, float column_width = 100.0f)
	{
		auto& io = ImGui::GetIO();

		ImGui::PushID(label);

		ImGui::Columns(2);
		ImGui::SetColumnWidth(0, column_width);
		ImGui::Text(label);
		ImGui::NextColumn();

		float lineHeight = io.FontDefault->FontSize + ImGui::GetStyle().FramePadding.y * 2.0f;
		ImVec2 buttonSize = { lineHeight + 3.0f,lineHeight };
		auto width = ImGui::GetWindowSize().x;
		width -= column_width + 3*buttonSize.x;
		width /= 4;
		ImGui::PushItemWidth(width);
		ImGui::PushItemWidth(width);
		ImGui::PushItemWidth(width);

		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2{ 0,0 });

		/// X
		{
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.8f, 0.1f, 0.15f, 1.0f));
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.9f, 0.2f, 0.20f, 1.0f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.8f, 0.1f, 0.15f, 1.0f));
			ImGui::PushFont(boldFont);
			if (ImGui::Button("X", buttonSize))
			{
				value.x = reset_value;
			}
			ImGui::PopFont();
			ImGui::PopStyleColor(3);

			ImGui::SameLine();
			ImGui::DragFloat("##X", &value.x, 0.1f, 0.0f, 0.0f, "%.2f");
			ImGui::PopItemWidth();
			ImGui::SameLine();

		}
		/// Y
		{
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.2f, 0.7f, 0.2f, 1.0f));
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.3f, 0.8f, 0.3f, 1.0f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.2f, 0.7f, 0.2f, 1.0f));
			ImGui::PushFont(boldFont);
			if (ImGui::Button("Y", buttonSize))
			{
				value.y = reset_value;
			}
			ImGui::PopFont();
			ImGui::PopStyleColor(3);

			ImGui::SameLine();
			ImGui::DragFloat("##Y", &value.y, 0.1f, 0.0f, 0.0f, "%.2f");
			ImGui::PopItemWidth();
			ImGui::SameLine();

		}
		/// Z
		{
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.1f, 0.25f, 0.8f, 1.0f));
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.2f, 0.35f, 0.9f, 1.0f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.1f, 0.25f, 0.8f, 1.0f));
			ImGui::PushFont(boldFont);
			if (ImGui::Button("Z", buttonSize))
			{
				value.z = reset_value;
			}
			ImGui::PopFont();
			ImGui::PopStyleColor(3);

			ImGui::SameLine();
			ImGui::DragFloat("##Z", &value.z, 0.1f, 0.0f, 0.0f, "%.2f");
			ImGui::PopItemWidth();
			//ImGui::SameLine();

		}
		ImGui::Columns(1);
		ImGui::PopStyleVar();
		ImGui::PopID();
	}

private:
	static void SetStyle();

	inline static ImFont* defaultFont{};
	inline static ImFont* boldFont{};
};

#endif // !IMGUI_INCLUDE
