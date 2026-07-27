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
#include <RenderDevice.h>
#include <DeviceContext.h>
#include <SwapChain.h>
#include <RefCntAutoPtr.hpp>

namespace Funkin::Render {
    struct DeviceCFG {
        void*    native_window_handle = nullptr;
        void*    native_display_handle = nullptr;
        uint32_t width = 0;
        uint32_t height = 0;
    };

    class Device {
    public:
        bool Init(const DeviceCFG& cfg);
        void Shutdown();
        void Resize(uint32_t width, uint32_t height);

        [[nodiscard]] Diligent::IRenderDevice* GetDevice()   const { return m_device_; }
        [[nodiscard]] Diligent::IDeviceContext* GetContext() const { return m_context_; }
        [[nodiscard]] Diligent::ISwapChain* GetSwapChain()  const { return m_swap_chain_; }

    private:
        Diligent::RefCntAutoPtr<Diligent::IRenderDevice>  m_device_;
        Diligent::RefCntAutoPtr<Diligent::IDeviceContext> m_context_;
        Diligent::RefCntAutoPtr<Diligent::ISwapChain>     m_swap_chain_;
    };
}