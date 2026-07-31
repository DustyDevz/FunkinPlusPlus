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
#include <cstdint>

// TEMP
namespace Funkin::Render {
    struct TextureHandle { uint32_t id = 0; bool isValid() const { return id != 0; } };
    struct MeshHandle    { uint32_t id = 0; bool isValid() const { return id != 0; } };
    struct BufferHandle  { uint32_t id = 0; bool isValid() const { return id != 0; } };

    struct Vertex {
        float x, y;       // position
        float u, v;       // texture coordinate
        float r, g, b, a; // color
    };
}