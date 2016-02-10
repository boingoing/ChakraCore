//-------------------------------------------------------------------------------------------------------
// Copyright (C) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.txt file in the project root for full license information.
//-------------------------------------------------------------------------------------------------------

// Multiple namespace imports cannot be bound to the same symbol

import * as foo from "ValidExportStatements.js";
import * as foo from "ValidExportStatements.js";
