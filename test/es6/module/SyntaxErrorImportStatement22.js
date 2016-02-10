//-------------------------------------------------------------------------------------------------------
// Copyright (C) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.txt file in the project root for full license information.
//-------------------------------------------------------------------------------------------------------

// Renamed import bindings are constant bindings

import { foo as foo22 } from "ValidExportStatements.js";

foo22 = 12;
