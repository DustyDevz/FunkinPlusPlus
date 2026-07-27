/*
  Funkin++ (Copyright (©) 2026 Dusty)
  SPDX-License-Identifier: AGPL-3.0

  This program is free software and you can redistribute it and/or modify
  it under the terms of the GNU Affero General Public License version 3.0.

  This program is distributed WITHOUT ANY WARRANTY.

  License: https://www.gnu.org/licenses/agpl-3.0.html
  Project: https://github.com/DustyDevz/FunkinPlusPlus
*/

#pragma once
#include <imgui.h>
#include <ImGuiImplDiligent.hpp>
#include "render_device.hpp"
#include "app/window.hpp"

namespace Funkin::Render {
    class Render {
    public:
        bool Init(const App::Window& window, bool vsync = false);
        void Shutdown();
        void Resize(uint32_t width, uint32_t height);

        void BeginFrame();
        void EndFrame();

    private:
        Device m_device_;
        std::unique_ptr<Diligent::ImGuiImplDiligent> m_imgui_;
    };
}