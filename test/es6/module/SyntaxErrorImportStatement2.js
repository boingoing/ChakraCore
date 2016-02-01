// Syntax error if import statement is in nested function

function foo() { 
    import foo from "ValidExportStatements.js";
}
