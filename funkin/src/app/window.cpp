/*
  Funkin++ (Copyright (©) 2026 Dusty)
  SPDX-License-Identifier: AGPL-3.0

  This program is free software and you can redistribute it and/or modify
  it under the terms of the GNU Affero General Public License version 3.0.

  This program is distributed WITHOUT ANY WARRANTY.

  License: https://www.gnu.org/licenses/agpl-3.0.html
  Project: https://github.com/DustyDevz/FunkinPlusPlus
*/

#include "app/window.hpp"

namespace Funkin::App {
    bool Window::Init(const char *title, uint32_t width, uint32_t height) {
        if (!SDL_Init(SDL_INIT_VIDEO)) return false;

        m_window = SDL_CreateWindow(title, (int)width, (int)height,
                                   SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY);
        if (!m_window) return false;

        m_width = width;
        m_height = height;
        return true;
    }

    bool Window::PollEvents() {
        SDL_Event sdl_event;
        while (SDL_PollEvent(&sdl_event)) {
            if (sdl_event.type == SDL_EVENT_QUIT) return false;
            if (sdl_event.type == SDL_EVENT_WINDOW_RESIZED) {
                m_width  = sdl_event.window.data1;
                m_height = sdl_event.window.data2;
            }
            // TODO: Port old input system and add input events
            // TODO: Port old input system and add input events
            // TODO: Port old input system and add input events
        }

        return true;
    }

    NativeWindowInfo Window::GetNativeHandles() const {
        NativeWindowInfo native_window_info;
        SDL_PropertiesID sdl_properties_id = SDL_GetWindowProperties(m_window);

        // TODO: Add linux support for window
        #if defined(_WIN32)
            native_window_info.window_handle = SDL_GetPointerProperty(sdl_properties_id, SDL_PROP_WINDOW_WIN32_HWND_POINTER, nullptr);
        #endif

        return native_window_info;
    }

    void Window::Shutdown() {
        if (m_window) SDL_DestroyWindow(m_window);
        SDL_Quit();
    }
}
