//-------------------------------------------------------------------------------------------------------
// Copyright (C) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.txt file in the project root for full license information.
//-------------------------------------------------------------------------------------------------------
#include "Backend.h"

ThreadContextInfo::ThreadContextInfo(ThreadContextData * data) :
    m_threadContextData(data)
{
}

intptr_t
ThreadContextInfo::GetNullFrameDisplayAddr() const
{
    return m_threadContextData->nullFrameDisplayAddr;
}

intptr_t
ThreadContextInfo::GetStrictNullFrameDisplayAddr() const
{
    return m_threadContextData->strictNullFrameDisplayAddr;
}
