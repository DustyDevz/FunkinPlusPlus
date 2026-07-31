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
#include <SDL3/SDL.h>

namespace Funkin::App {
    struct NativeWindowInfo {
        // TODO: add linux support for window handles (stop being fucking lazy)
        void* window_handle  = nullptr; // HWND (win32) / xcb_window_t cast to void* (linux)
        void* display_handle = nullptr; // X11 Display* on linux
    };

    class Window {
    public:
        bool Init(const char* title, uint32_t width, uint32_t height);
        void Shutdown();
        bool PollEvents();

        [[nodiscard]] NativeWindowInfo GetNativeHandles() const;
        [[nodiscard]] uint32_t Width()  const { return m_width; }
        [[nodiscard]] uint32_t Height() const { return m_height; }

    private:
        SDL_Window* m_window = nullptr;
        uint32_t m_width = 0, m_height = 0;
    };
}