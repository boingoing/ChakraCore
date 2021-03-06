//-------------------------------------------------------------------------------------------------------
// Copyright (C) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.txt file in the project root for full license information.
//-------------------------------------------------------------------------------------------------------

#pragma once


class JavascriptSIMDFloat32x4;
class JavascriptSIMDFloat64x2;

namespace Js
{
    class JavascriptSIMDInt16x8 sealed : public RecyclableObject
    {
    private:
        SIMDValue value;

        DEFINE_VTABLE_CTOR(JavascriptSIMDInt16x8, RecyclableObject);


    public:
        class EntryInfo
        {
        public:
            static FunctionInfo ToString;
            static FunctionInfo Bool;
        };

        JavascriptSIMDInt16x8(SIMDValue *val, StaticType *type);
        static JavascriptSIMDInt16x8* New(SIMDValue *val, ScriptContext* requestContext);
        static bool Is(Var instance);
        static JavascriptSIMDInt16x8* FromVar(Var aValue);

        __inline SIMDValue GetValue() { return value; }

        virtual BOOL GetPropertyReference(Var originalInstance, PropertyId propertyId, Var* value, PropertyValueInfo* info, ScriptContext* requestContext) override;
        virtual BOOL GetProperty(Var originalInstance, PropertyId propertyId, Var* value, PropertyValueInfo* info, ScriptContext* requestContext) override;
        virtual BOOL GetProperty(Var originalInstance, JavascriptString* propertyNameString, Var* value, PropertyValueInfo* info, ScriptContext* requestContext) override;
        virtual RecyclableObject * CloneToScriptContext(ScriptContext* requestContext) override;

        // Entry Points
        static Var EntryToString(RecyclableObject* function, CallInfo callInfo, ...);
        // End Entry Points

        Var  Copy(ScriptContext* requestContext);
        Var  CopyAndSetLane(uint index, int value, ScriptContext* requestContext);

    private:
        bool GetPropertyBuiltIns(PropertyId propertyId, Var* value, ScriptContext* requestContext);
        Var  GetLaneAsNumber(uint index, ScriptContext* requestContext);
        Var  GetLaneAsFlag(uint index, ScriptContext* requestContext);
    };
}

