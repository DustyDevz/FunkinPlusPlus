/*
  Funkin++ (Copyright (©) 2026 Dusty)
  SPDX-License-Identifier: AGPL-3.0

  This program is free software and you can redistribute it and/or modify
  it under the terms of the GNU Affero General Public License version 3.0.

  This program is distributed WITHOUT ANY WARRANTY.

  License: https://www.gnu.org/licenses/agpl-3.0.html
  Project: https://github.com/DustyDevz/FunkinPlusPlus
*/

#include "render/render_device.hpp"
#include <EngineFactoryVk.h>

namespace Funkin::Render {
    bool Device::Init(const DeviceCFG &cfg) {
        auto* factory = Diligent::GetEngineFactoryVk();
        Diligent::EngineVkCreateInfo engine_vk_create_info;
        #ifdef FUNKIN_DEBUG
            engine_vk_create_info.EnableValidation = true;
        #endif

        Diligent::IDeviceContext* device_context = nullptr;
        factory->CreateDeviceAndContextsVk(engine_vk_create_info, &m_device_, &device_context);
        if (!m_device_) return false;
        m_context_ = device_context;

        Diligent::SwapChainDesc swap_chain_desc;
        swap_chain_desc.Width  = cfg.width;
        swap_chain_desc.Height = cfg.height;

        Diligent::NativeWindow window{cfg.native_window_handle};
        factory->CreateSwapChainVk(m_device_, m_context_, swap_chain_desc, window, &m_swap_chain_);
        return m_swap_chain_ != nullptr;
    }

    void Device::Shutdown() {
        m_swap_chain_.Release();
        m_context_.Release();
        m_device_.Release();
    }

    void Device::Resize(uint32_t width, uint32_t height) {
        if (m_swap_chain_) m_swap_chain_->Resize(width, height);
    }
}
