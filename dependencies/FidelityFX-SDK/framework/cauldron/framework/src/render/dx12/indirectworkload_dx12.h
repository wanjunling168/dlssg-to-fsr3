// This file is part of the FidelityFX SDK.
//
// Copyright (C) 2024 Advanced Micro Devices, Inc.
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "render/indirectworkload.h"
#include "render/dx12/defines_dx12.h"

#include <agilitysdk/include/d3d12.h>

namespace cauldron
{
    class Buffer;
    class CommandList;

    class IndirectWorkloadInternal final : public IndirectWorkload
    {
    public:
        IndirectWorkloadInternal(const IndirectCommandType& type);
        virtual ~IndirectWorkloadInternal() = default;

    private:
        IndirectCommandType                             m_type;
        uint32_t                                        m_stride;
        MSComPtr<ID3D12CommandSignature>                m_pCommandSignature = nullptr;

        friend void ExecuteIndirect(CommandList* pCmdList, IndirectWorkload* pIndirectWorkload, const Buffer* pArgumentBuffer, uint32_t drawCount, uint32_t offset);
    };
}  // namespace cauldron
