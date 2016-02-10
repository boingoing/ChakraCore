//-------------------------------------------------------------------------------------------------------
// Copyright (C) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.txt file in the project root for full license information.
//-------------------------------------------------------------------------------------------------------

// Named import clause may not contain multiple binding identifiers with the same name

import { foo as bar, bar } from "ValidExportStatements.js";
