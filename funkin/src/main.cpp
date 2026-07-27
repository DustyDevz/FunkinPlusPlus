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
#include "render/render.hpp"

int main() {
    LOG_PRINT("hi");

    Funkin::App::Window window;
    if (!window.Init("window test", 1280, 720)) {
        LOG_CRIT("Failed to initialize window");
        return 1;
    }

    Funkin::Render::Render renderer;
    if (!renderer.Init(window)) {
        LOG_CRIT("Failed to initialized renderer");
        return 1;
    }

    while (window.PollEvents()) {
        renderer.BeginFrame();
        renderer.EndFrame();
    }

    renderer.Shutdown();
    window.Shutdown();
    return 0;
}