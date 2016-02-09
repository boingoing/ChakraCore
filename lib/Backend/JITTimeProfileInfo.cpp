//-------------------------------------------------------------------------------------------------------
// Copyright (C) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.txt file in the project root for full license information.
//-------------------------------------------------------------------------------------------------------

#include "BackEnd.h"

JITTimeProfileInfo::JITTimeProfileInfo(ProfileData * profileData) :
    m_profileData(profileData)
{
}

/* static */
void
JITTimeProfileInfo::InitializeJITProfileData(
    __in Js::DynamicProfileInfo * profileInfo,
    __in Js::FunctionBody *functionBody,
    __out ProfileData * data)
{
    if (profileInfo == nullptr)
    {
        return;
    }
    CompileAssert(sizeof(LdElemData) == sizeof(Js::LdElemInfo));

    data->profiledLdElemCount = functionBody->GetProfiledLdElemCount();
    data->ldElemData = (LdElemData*)profileInfo->GetLdElemInfo();

    CompileAssert(sizeof(StElemData) == sizeof(Js::StElemInfo));
    data->profiledStElemCount = functionBody->GetProfiledStElemCount();
    data->stElemData = (StElemData*)profileInfo->GetStElemInfo();

    CompileAssert(sizeof(ArrayCallSiteData) == sizeof(Js::ArrayCallSiteInfo));
    data->profiledArrayCallSiteCount = functionBody->GetProfiledArrayCallSiteCount();
    data->arrayCallSiteData = (ArrayCallSiteData*)profileInfo->GetArrayCallSiteInfo();

    CompileAssert(sizeof(FldData) == sizeof(Js::FldInfo));
    data->inlineCacheCount = functionBody->GetProfiledFldCount();
    data->fldData = (FldData*)profileInfo->GetFldInfo();

    CompileAssert(sizeof(ThisData) == sizeof(Js::ThisInfo));
    data->thisData = *reinterpret_cast<ThisData*>(&profileInfo->GetThisInfo());

    CompileAssert(sizeof(CallSiteData) == sizeof(Js::CallSiteInfo));
    data->profiledCallSiteCount = functionBody->GetProfiledCallSiteCount();
    data->callSiteData = reinterpret_cast<CallSiteData*>(profileInfo->GetCallSiteInfo());

    CompileAssert(sizeof(ValueType) == sizeof(uint16));
    data->profiledReturnTypeCount = functionBody->GetProfiledReturnTypeCount();
    data->returnTypeData = reinterpret_cast<uint16*>(profileInfo->GetReturnTypeInfo());

    data->profiledDivOrRemCount = functionBody->GetProfiledDivOrRemCount();
    data->divideTypeInfo = reinterpret_cast<uint16*>(profileInfo->GetDivideTypeInfo());

    data->profiledSwitchCount = functionBody->GetProfiledSwitchCount();
    data->switchTypeInfo = reinterpret_cast<uint16*>(profileInfo->GetSwitchTypeInfo());

    data->profiledInParamsCount = functionBody->GetProfiledInParamsCount();
    data->parameterInfo = reinterpret_cast<uint16*>(profileInfo->GetParameterInfo());

    data->loopCount = functionBody->GetLoopCount();
    data->loopImplicitCallFlags = reinterpret_cast<byte*>(profileInfo->GetLoopImplicitCallFlags());

    data->implicitCallFlags = static_cast<byte>(profileInfo->GetImplicitCallFlags());

    data->flags |= profileInfo->IsAggressiveIntTypeSpecDisabled(false) ? Flags_disableAggressiveIntTypeSpec : 0;
    data->flags |= profileInfo->IsAggressiveIntTypeSpecDisabled(true) ? Flags_disableAggressiveIntTypeSpec_jitLoopBody : 0;
    data->flags |= profileInfo->IsAggressiveMulIntTypeSpecDisabled(false) ? Flags_disableAggressiveMulIntTypeSpec : 0;
    data->flags |= profileInfo->IsAggressiveMulIntTypeSpecDisabled(true) ? Flags_disableAggressiveMulIntTypeSpec_jitLoopBody : 0;
    data->flags |= profileInfo->IsDivIntTypeSpecDisabled(false) ? Flags_disableDivIntTypeSpec : 0;
    data->flags |= profileInfo->IsDivIntTypeSpecDisabled(true) ? Flags_disableDivIntTypeSpec_jitLoopBody : 0;
    data->flags |= profileInfo->IsLossyIntTypeSpecDisabled() ? Flags_disableLossyIntTypeSpec : 0;
    data->flags |= profileInfo->IsTrackCompoundedIntOverflowDisabled() ? Flags_disableTrackCompoundedIntOverflow : 0;
    data->flags |= profileInfo->IsFloatTypeSpecDisabled() ? Flags_disableFloatTypeSpec : 0;
    data->flags |= profileInfo->IsArrayCheckHoistDisabled(false) ? Flags_disableArrayCheckHoist : 0;
    data->flags |= profileInfo->IsArrayCheckHoistDisabled(true) ? Flags_disableArrayCheckHoist_jitLoopBody : 0;
    data->flags |= profileInfo->IsArrayMissingValueCheckHoistDisabled(false) ? Flags_disableArrayMissingValueCheckHoist : 0;
    data->flags |= profileInfo->IsArrayMissingValueCheckHoistDisabled(true) ? Flags_disableArrayMissingValueCheckHoist_jitLoopBody : 0;
    data->flags |= profileInfo->IsJsArraySegmentHoistDisabled(false) ? Flags_disableJsArraySegmentHoist : 0;
    data->flags |= profileInfo->IsJsArraySegmentHoistDisabled(true) ? Flags_disableJsArraySegmentHoist_jitLoopBody : 0;
    data->flags |= profileInfo->IsArrayLengthHoistDisabled(false) ? Flags_disableArrayLengthHoist : 0;
    data->flags |= profileInfo->IsArrayLengthHoistDisabled(true) ? Flags_disableArrayLengthHoist_jitLoopBody : 0;
    data->flags |= profileInfo->IsTypedArrayTypeSpecDisabled(false) ? Flags_disableTypedArrayTypeSpec : 0;
    data->flags |= profileInfo->IsTypedArrayTypeSpecDisabled(true) ? Flags_disableTypedArrayTypeSpec_jitLoopBody : 0;
    data->flags |= profileInfo->IsLdLenIntSpecDisabled() ? Flags_disableLdLenIntSpec : 0;
    data->flags |= profileInfo->IsBoundCheckHoistDisabled(false) ? Flags_disableBoundCheckHoist : 0;
    data->flags |= profileInfo->IsBoundCheckHoistDisabled(true) ? Flags_disableBoundCheckHoist_jitLoopBody : 0;
    data->flags |= profileInfo->IsLoopCountBasedBoundCheckHoistDisabled(false) ? Flags_disableLoopCountBasedBoundCheckHoist : 0;
    data->flags |= profileInfo->IsLoopCountBasedBoundCheckHoistDisabled(true) ? Flags_disableLoopCountBasedBoundCheckHoist_jitLoopBody : 0;
    data->flags |= profileInfo->IsFloorInliningDisabled() ? Flags_disableFloorInlining : 0;
    data->flags |= profileInfo->IsNoProfileBailoutsDisabled() ? Flags_disableNoProfileBailouts : 0;
    data->flags |= profileInfo->IsSwitchOptDisabled() ? Flags_disableSwitchOpt : 0;
    data->flags |= profileInfo->IsEquivalentObjTypeSpecDisabled() ? Flags_disableEquivalentObjTypeSpec : 0;
    data->flags |= profileInfo->IsObjTypeSpecDisabledInJitLoopBody() ? Flags_disableObjTypeSpec_jitLoopBody : 0;
    data->flags |= profileInfo->IsMemOpDisabled() ? Flags_disableMemOp : 0;
    data->flags |= profileInfo->IsCheckThisDisabled() ? Flags_disableCheckThis : 0;
}

Js::ArrayCallSiteInfo *
JITTimeProfileInfo::GetArrayCallSiteInfo(Js::ProfileId index) const
{
    Assert(index < GetProfiledArrayCallSiteCount());
    return &(reinterpret_cast<Js::ArrayCallSiteInfo*>(m_profileData->arrayCallSiteData)[index]);
}

Js::FldInfo *
JITTimeProfileInfo::GetFldInfo(uint fieldAccessId) const
{
    Assert(fieldAccessId < GetProfiledFldCount());
    return &(reinterpret_cast<Js::FldInfo*>(m_profileData->fldData)[fieldAccessId]);
}

Js::ThisInfo
JITTimeProfileInfo::GetThisInfo() const
{
    return *reinterpret_cast<Js::ThisInfo*>(&m_profileData->thisData);
}

ValueType
JITTimeProfileInfo::GetReturnType(Js::OpCode opcode, Js::ProfileId callSiteId) const
{
    if (opcode < Js::OpCode::ProfiledReturnTypeCallI)
    {
        Assert(Js::DynamicProfileInfo::IsProfiledCallOp(opcode));
        Assert(callSiteId < GetProfiledCallSiteCount());
        return GetCallSiteInfo()[callSiteId].returnType;
    }
    Assert(Js::DynamicProfileInfo::IsProfiledReturnTypeOp(opcode));
    Assert(callSiteId < GetProfiledReturnTypeCount());
    return reinterpret_cast<ValueType*>(m_profileData->returnTypeData)[callSiteId];
}

ValueType
JITTimeProfileInfo::GetDivProfileInfo(Js::ProfileId divideId) const
{
    Assert(divideId < GetProfiledDivOrRemCount());
    return reinterpret_cast<ValueType*>(m_profileData->divideTypeInfo)[divideId];
}

ValueType
JITTimeProfileInfo::GetSwitchProfileInfo(Js::ProfileId switchId) const
{
    Assert(switchId < GetProfiledSwitchCount());
    return reinterpret_cast<ValueType*>(m_profileData->switchTypeInfo)[switchId];
}

ValueType
JITTimeProfileInfo::GetParameterInfo(Js::ArgSlot index) const
{
    Assert(index < GetProfiledInParamsCount());
    return reinterpret_cast<ValueType*>(m_profileData->parameterInfo)[index];
}

Js::ImplicitCallFlags
JITTimeProfileInfo::GetLoopImplicitCallFlags(uint loopNum) const
{
    // TODO: michhol OOP JIT, investigate vaibility of reenabling this assert
    // Assert(Js::DynamicProfileInfo::EnableImplicitCallFlags(functionBody));
    Assert(loopNum < GetLoopCount());

    // Mask out the dispose implicit call. We would bailout on reentrant dispose,
    // but it shouldn't affect optimization.
    return (Js::ImplicitCallFlags)(m_profileData->loopImplicitCallFlags[loopNum] & Js::ImplicitCall_All);
}

Js::ImplicitCallFlags
JITTimeProfileInfo::GetImplicitCallFlags() const
{
    return static_cast<Js::ImplicitCallFlags>(m_profileData->implicitCallFlags);
}

Js::LoopFlags
JITTimeProfileInfo::GetLoopFlags(uint loopNum) const
{
    // TODO: michhol OOP JIT... figure out how to easily move the BVs
    Assert(UNREACHED);
    return Js::LoopFlags();
}

bool
JITTimeProfileInfo::IsModulusOpByPowerOf2(Js::ProfileId profileId) const
{
    return GetDivProfileInfo(profileId).IsLikelyTaggedInt();
}

bool
JITTimeProfileInfo::IsAggressiveIntTypeSpecDisabled(const bool isJitLoopBody) const
{
    if (isJitLoopBody)
    {
        return TestFlag(Flags_disableAggressiveIntTypeSpec_jitLoopBody);
    }
    else
    {
        return TestFlag(Flags_disableAggressiveIntTypeSpec);
    }
}

bool
JITTimeProfileInfo::IsSwitchOptDisabled() const
{
    return TestFlag(Flags_disableSwitchOpt);
}

bool
JITTimeProfileInfo::IsEquivalentObjTypeSpecDisabled() const
{
    return TestFlag(Flags_disableEquivalentObjTypeSpec);
}

bool
JITTimeProfileInfo::IsObjTypeSpecDisabledInJitLoopBody() const
{
    return TestFlag(Flags_disableObjTypeSpec_jitLoopBody);
}

bool
JITTimeProfileInfo::IsAggressiveMulIntTypeSpecDisabled(const bool isJitLoopBody) const
{
    if (isJitLoopBody)
    {
        return TestFlag(Flags_disableAggressiveMulIntTypeSpec_jitLoopBody);
    }
    else
    {
        return TestFlag(Flags_disableAggressiveMulIntTypeSpec);
    }
}

bool
JITTimeProfileInfo::IsDivIntTypeSpecDisabled(const bool isJitLoopBody) const
{
    if (isJitLoopBody)
    {
        return TestFlag(Flags_disableDivIntTypeSpec_jitLoopBody);
    }
    else
    {
        return TestFlag(Flags_disableDivIntTypeSpec);
    }
}

bool
JITTimeProfileInfo::IsLossyIntTypeSpecDisabled() const
{
    return TestFlag(Flags_disableLossyIntTypeSpec);
}

bool
JITTimeProfileInfo::IsMemOpDisabled() const
{
    return TestFlag(Flags_disableMemOp);
}

bool
JITTimeProfileInfo::IsTrackCompoundedIntOverflowDisabled() const
{
    return TestFlag(Flags_disableTrackCompoundedIntOverflow);
}

bool
JITTimeProfileInfo::IsFloatTypeSpecDisabled() const
{
    return TestFlag(Flags_disableFloatTypeSpec);
}

bool
JITTimeProfileInfo::IsCheckThisDisabled() const
{
    return TestFlag(Flags_disableCheckThis);
}

bool
JITTimeProfileInfo::IsArrayCheckHoistDisabled(const bool isJitLoopBody) const
{
    if (isJitLoopBody)
    {
        return TestFlag(Flags_disableArrayCheckHoist_jitLoopBody);
    }
    else
    {
        return TestFlag(Flags_disableArrayCheckHoist);
    }
}

bool
JITTimeProfileInfo::IsArrayMissingValueCheckHoistDisabled(const bool isJitLoopBody) const
{
    if (isJitLoopBody)
    {
        return TestFlag(Flags_disableArrayMissingValueCheckHoist_jitLoopBody);
    }
    else
    {
        return TestFlag(Flags_disableArrayMissingValueCheckHoist);
    }
}

bool
JITTimeProfileInfo::IsJsArraySegmentHoistDisabled(const bool isJitLoopBody) const
{
    if (isJitLoopBody)
    {
        return TestFlag(Flags_disableJsArraySegmentHoist_jitLoopBody);
    }
    else
    {
        return TestFlag(Flags_disableJsArraySegmentHoist);
    }
}

bool
JITTimeProfileInfo::IsArrayLengthHoistDisabled(const bool isJitLoopBody) const
{
    if (isJitLoopBody)
    {
        return TestFlag(Flags_disableArrayLengthHoist_jitLoopBody);
    }
    else
    {
        return TestFlag(Flags_disableArrayLengthHoist);
    }
}

bool
JITTimeProfileInfo::IsTypedArrayTypeSpecDisabled(const bool isJitLoopBody) const
{
    if (isJitLoopBody)
    {
        return TestFlag(Flags_disableTypedArrayTypeSpec_jitLoopBody);
    }
    else
    {
        return TestFlag(Flags_disableTypedArrayTypeSpec);
    }
}

bool
JITTimeProfileInfo::IsLdLenIntSpecDisabled() const
{
    return TestFlag(Flags_disableLdLenIntSpec);
}

bool
JITTimeProfileInfo::IsBoundCheckHoistDisabled(const bool isJitLoopBody) const
{
    if (isJitLoopBody)
    {
        return TestFlag(Flags_disableBoundCheckHoist_jitLoopBody);
    }
    else
    {
        return TestFlag(Flags_disableBoundCheckHoist);
    }
}

bool
JITTimeProfileInfo::IsLoopCountBasedBoundCheckHoistDisabled(const bool isJitLoopBody) const
{
    if (isJitLoopBody)
    {
        return TestFlag(Flags_disableLoopCountBasedBoundCheckHoist_jitLoopBody);
    }
    else
    {
        return TestFlag(Flags_disableLoopCountBasedBoundCheckHoist);
    }
}

bool
JITTimeProfileInfo::IsFloorInliningDisabled() const
{
    return TestFlag(Flags_disableFloorInlining);
}

bool
JITTimeProfileInfo::IsNoProfileBailoutsDisabled() const
{
    return TestFlag(Flags_disableNoProfileBailouts);
}

Js::ProfileId
JITTimeProfileInfo::GetProfiledArrayCallSiteCount() const
{
    return static_cast<Js::ProfileId>(m_profileData->profiledArrayCallSiteCount);
}

Js::ProfileId
JITTimeProfileInfo::GetProfiledCallSiteCount() const
{
    return static_cast<Js::ProfileId>(m_profileData->profiledCallSiteCount);
}

Js::ProfileId
JITTimeProfileInfo::GetProfiledReturnTypeCount() const
{
    return static_cast<Js::ProfileId>(m_profileData->profiledReturnTypeCount);
}

Js::ProfileId
JITTimeProfileInfo::GetProfiledDivOrRemCount() const
{
    return static_cast<Js::ProfileId>(m_profileData->profiledDivOrRemCount);
}

Js::ProfileId
JITTimeProfileInfo::GetProfiledSwitchCount() const
{
    return static_cast<Js::ProfileId>(m_profileData->profiledSwitchCount);
}

Js::ArgSlot
JITTimeProfileInfo::GetProfiledInParamsCount() const
{
    return static_cast<Js::ArgSlot>(m_profileData->profiledInParamsCount);
}

uint
JITTimeProfileInfo::GetProfiledFldCount() const
{
    return m_profileData->inlineCacheCount;
}

uint
JITTimeProfileInfo::GetLoopCount() const
{
    return m_profileData->loopCount;
}

Js::CallSiteInfo *
JITTimeProfileInfo::GetCallSiteInfo() const
{
    return reinterpret_cast<Js::CallSiteInfo*>(m_profileData->callSiteData);
}
