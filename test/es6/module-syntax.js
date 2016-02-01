//-------------------------------------------------------------------------------------------------------
// Copyright (C) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.txt file in the project root for full license information.
//-------------------------------------------------------------------------------------------------------

// ES6 Module syntax tests -- verifies syntax of import and export statements

WScript.LoadScriptFile("..\\UnitTestFramework\\UnitTestFramework.js");

var tests = [
    {
        name: "All valid (non-default) export statements",
        body: function () {
            assert.doesNotThrow(function () { WScript.LoadModuleFile('.\\module\\ValidExportStatements.js', 'samethread'); }, "Valid export statements");
        }
    },
    {
        name: "Valid default export statements",
        body: function () {
            assert.doesNotThrow(function () { WScript.LoadModuleFile('.\\module\\ValidExportDefaultStatement1.js', 'samethread'); }, "Unnamed function expression default export");
            assert.doesNotThrow(function () { WScript.LoadModuleFile('.\\module\\ValidExportDefaultStatement2.js', 'samethread'); }, "Named function expression default export");
            assert.doesNotThrow(function () { WScript.LoadModuleFile('.\\module\\ValidExportDefaultStatement3.js', 'samethread'); }, "Unnamed generator function expression default export");
            assert.doesNotThrow(function () { WScript.LoadModuleFile('.\\module\\ValidExportDefaultStatement4.js', 'samethread'); }, "Named generator function expression default export");
            assert.doesNotThrow(function () { WScript.LoadModuleFile('.\\module\\ValidExportDefaultStatement5.js', 'samethread'); }, "Unnamed class expression default export");
            assert.doesNotThrow(function () { WScript.LoadModuleFile('.\\module\\ValidExportDefaultStatement6.js', 'samethread'); }, "Named class default expression export");
            assert.doesNotThrow(function () { WScript.LoadModuleFile('.\\module\\ValidExportDefaultStatement7.js', 'samethread'); }, "Primitive type default export");
            assert.doesNotThrow(function () { WScript.LoadModuleFile('.\\module\\ValidExportDefaultStatement8.js', 'samethread'); }, "Variable in assignment expression default export");
            assert.doesNotThrow(function () { WScript.LoadModuleFile('.\\module\\ValidExportDefaultStatement9.js', 'samethread'); }, "Lambda expression as default export");
            assert.doesNotThrow(function () { WScript.LoadModuleFile('.\\module\\ValidExportDefaultStatement10.js', 'samethread'); }, "Named function statement default export");
            assert.doesNotThrow(function () { WScript.LoadModuleFile('.\\module\\ValidExportDefaultStatement11.js', 'samethread'); }, "Named generator function statement default export");
            assert.doesNotThrow(function () { WScript.LoadModuleFile('.\\module\\ValidExportDefaultStatement12.js', 'samethread'); }, "Named class statement default export");
            assert.doesNotThrow(function () { WScript.LoadModuleFile('.\\module\\ValidExportDefaultStatement13.js', 'samethread'); }, "Default export of an object");
        }
    },
    {
        name: "Syntax error export statements",
        body: function () {
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorExportStatement1.js', 'samethread'); }); // Syntax error if const decl is missing initializer
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorExportStatement2.js', 'samethread'); }); // Syntax error if we're trying to export an identifier without default or curly braces
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorExportStatement3.js', 'samethread'); }); // Syntax error if function declaration is missing binding identifier
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorExportStatement4.js', 'samethread'); }); // Syntax error if generator declaration is missing binding identifier
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorExportStatement5.js', 'samethread'); }); // Syntax error if class declaration is missing binding identifier
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorExportStatement6.js', 'samethread'); }); // Syntax error if we use brackets instead of curly braces in export statement
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorExportStatement7.js', 'samethread'); }); // Syntax error if export statement is in a nested function
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorExportStatement8.js', 'samethread'); }); // Syntax error if export statement is in eval
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorExportStatement9.js', 'samethread'); }); // Syntax error if named export list contains an empty element
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorExportStatement10.js', 'samethread'); }); // Syntax error if export statement is in arrow function
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorExportStatement11.js', 'samethread'); }); // Syntax error if export statement is in try catch statement
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorExportStatement12.js', 'samethread'); }); // Syntax error if export statement is in any block
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorExportStatement13.js', 'samethread'); }); // Export default takes an assignment expression which doesn't allow comma expressions
        }
    },
    {
        name: "All valid import statements",
        body: function () {
            assert.doesNotThrow(function () { WScript.LoadModuleFile('.\\module\\ValidImportStatements.js', 'samethread'); }, "Valid import statements");
        }
    },
    {
        name: "Syntax error import statements",
        body: function () {
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement1.js', 'samethread'); }); // Syntax error if import statement is in eval
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement2.js', 'samethread'); }); // Syntax error if import statement is in nested function
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement3.js', 'samethread'); }); // Syntax error if import statement has multiple default bindings
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement4.js', 'samethread'); }); // Syntax error if import statement is missing from clause
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement5.js', 'samethread'); }); // Syntax error if import statement has comma after namespace import
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement6.js', 'samethread'); }); // Syntax error if import statement has default binding after namespace import
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement7.js', 'samethread'); }); // Syntax error if import statement has named import list after namespace import
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement8.js', 'samethread'); }); // Syntax error if import statement has comma after named import list
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement9.js', 'samethread'); }); // Syntax error if import statement has default binding after named import list
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement10.js', 'samethread'); }); // Syntax error if import statement has namespace import after named import list
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement11.js', 'samethread'); }); // Syntax error if import statement is missing from clause
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement12.js', 'samethread'); }); // Syntax error if named import clause uses brackets
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement13.js', 'samethread'); }); // Syntax error if namespace import is missing 'as' keyword
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement14.js', 'samethread'); }); // Syntax error if namespace imported binding name is not identifier
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement15.js', 'samethread'); }); // Syntax error if named import list contains an empty element
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement16.js', 'samethread'); }); // Imported default bindings are constant bindings
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement17.js', 'samethread'); }); // Default import cannot be bound to the same symbol
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement18.js', 'samethread'); }); // Imported named bindings are constant bindings
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement19.js', 'samethread'); }); // Multiple named imports cannot be bound to the same symbol
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement20.js', 'samethread'); }); // Namespace import bindings are constant bindings
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement21.js', 'samethread'); }); // Multiple namespace imports cannot be bound to the same symbol
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement22.js', 'samethread'); }); // Renamed import bindings are constant bindings
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement23.js', 'samethread'); }); // Named import clause may not contain multiple binding identifiers with the same name
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement24.js', 'samethread'); }); // Imported bindings cannot be overwritten by later imports
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement25.js', 'samethread'); }); // Syntax error if import statement is in arrow function
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement26.js', 'samethread'); }); // Syntax error if import statement is in try catch statement
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement27.js', 'samethread'); }); // Syntax error if import statement is in any block
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement28.js', 'samethread'); }); // Named import clause which has EOF after left curly
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement29.js', 'samethread'); }); // Named import clause which has EOF after identifier
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement30.js', 'samethread'); }); // Named import clause which has EOF after identifier as
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement31.js', 'samethread'); }); // Named import clause which has EOF after identifier as identifier
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement32.js', 'samethread'); }); // Named import clause which has EOF after identifier as identifier comma
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement33.js', 'samethread'); }); // Named import clause which has non-identifier token as the first token
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement34.js', 'samethread'); }); // Named import clause missing 'as' token
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement35.js', 'samethread'); }); // Named import clause with non-identifier token after 'as'
            assert.throws(function () { WScript.LoadModuleFile('.\\module\\SyntaxErrorImportStatement36.js', 'samethread'); }); // Named import clause with too many trailing commas
        }
    },
    {
        name: "All valid re-export statements",
        body: function () {
            assert.doesNotThrow(function () { WScript.LoadModuleFile('.\\module\\ValidReExportStatements.js', 'samethread'); }, "Valid re-export statements");
        }
    },
];

testRunner.runTests(tests, { verbose: WScript.Arguments[0] != "summary" });
