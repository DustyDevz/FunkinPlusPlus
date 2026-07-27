/*
  Funkin++ (Copyright (©) 2026 Dusty)
  SPDX-License-Identifier: AGPL-3.0

  This program is free software and you can redistribute it and/or modify
  it under the terms of the GNU Affero General Public License version 3.0.

  This program is distributed WITHOUT ANY WARRANTY.

  License: https://www.gnu.org/licenses/agpl-3.0.html
  Project: https://github.com/DustyDevz/FunkinPlusPlus
*/

#include "render/render.hpp"

namespace Funkin::Render {
    bool Render::Init(const App::Window &window, bool vsync) {
        auto handles = window.GetNativeHandles();
        DeviceCFG device_cfg{
            .native_window_handle = handles.window_handle,
            .native_display_handle = handles.display_handle,
            .width = window.Width(),
            .height = window.Height(),
        };

        if (!m_device_.Init(device_cfg)) {
            LOG_ERR("Failed to initialize device");
            return false;
        }

        // Imgui

        return true;
    }

    void Render::BeginFrame() {
        auto* rtv = m_device_.GetSwapChain()->GetCurrentBackBufferRTV();
        m_device_.GetContext()->SetRenderTargets(1, &rtv, nullptr,
            Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);

        const float clear_color[] = {.1f, .1f, .15f, 1.0f};
        m_device_.GetContext()->ClearRenderTarget(rtv, clear_color,
            Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
    }

    void Render::EndFrame() {
        m_device_.GetSwapChain()->Present(0);
    }

    void Render::Resize(uint32_t width, uint32_t height) {
        m_device_.Resize(width, height);
    }

    void Render::Shutdown() {
        m_device_.Shutdown();
    }
}
