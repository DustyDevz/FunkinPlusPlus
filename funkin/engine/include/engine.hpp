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

#if defined(_WIN32)
    #if defined(FunkinEngine_EXPORTS)
        #define FUNKIN_API __declspec(dllexport)
    #else
        #define FUNKIN_API __declspec(dllimport)
    #endif
#else
    #define FUNKIN_API
#endif

namespace FunkinEngine {
    FUNKIN_API void init();
}